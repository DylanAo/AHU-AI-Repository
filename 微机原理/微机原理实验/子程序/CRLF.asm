CRLF PROC
;回车换行
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSHF

    MOV AH,2
    MOV DL,0DH;回车
    INT 21H
    MOV AH,2
    MOV DL,0AH;换行
    INT 21H

    POPF
    POP DX
    POP CX
    POP BX
    POP AX
    RET
CRLF ENDP