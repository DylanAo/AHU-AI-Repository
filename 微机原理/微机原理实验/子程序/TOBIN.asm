TOBIN PROC
;入口参数BX
;功能:将BX以2进制形式输出,不带回车换行

    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSHF

    MOV CX,16D
AGAIN_BIN:
    MOV AX,8000H
    AND AX,BX
    ROL BX,1
    CMP AX,8000H
    JB BELOW_BIN
    JMP ABOVE_BIN
BELOW_BIN:
    MOV AH,2
    MOV DL,'0'
    INT 21H
    JMP OVER_BIN
ABOVE_BIN:
    MOV AH,2
    MOV DL,'1'
    INT 21H
OVER_BIN:
    LOOP AGAIN_BIN

    POPF
    POP DX
    POP CX
    POP BX
    POP AX
    RET
TOBIN ENDP