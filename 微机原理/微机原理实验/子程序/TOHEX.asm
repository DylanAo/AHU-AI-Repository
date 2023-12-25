TOHEX PROC
;入口参数BX
;功能:将BX以16进制形式输出,不带回车换行
;建议在DEBUG模式下使用，直接运行可能会有问题
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSHF

    MOV CX,4D
AGAIN_HEX:
    ;取头四位出来放到AX高4位中,并左移4位
    MOV AX,0F000H
    AND AX,BX
    PUSH CX
    MOV CL,4D
    ROL BX,CL
    POP CX

    ;将AX中高4位变为AH中低4位
    PUSH CX
    MOV CL,4D
    SHR AH,CL
    POP CX

    ;对AH中第四位计算出ASCII码,并放回AH中
    ADD AH,'0'
    CMP AH,'9'
    JBE BELOW_HEX
    ADD AH,7D

    ;输出AH中字符
BELOW_HEX:
    MOV DL,AH
    MOV AH,2
    INT 21H
OVER_HEX:
    LOOP AGAIN_HEX

    POPF
    POP DX
    POP CX
    POP BX
    POP AX
    RET
TOHEX ENDP
