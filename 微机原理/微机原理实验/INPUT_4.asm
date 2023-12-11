DATA SEGMENT
    WRONG DB "Input Error$"
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA

CRLF PROC
;回车换行
    MOV AH,2
    MOV DL,0DH;回车
    INT 21H
    MOV AH,2
    MOV DL,0AH;换行
    INT 21H
    RET
CRLF ENDP

START:
    MOV AX,DATA
    MOV DS,AX
    XOR AX,AX

    JMP FIRST
AGAIN:
    CALL CRLF
    MOV AH,09H
    MOV DX,OFFSET WRONG
    INT 21H
    CALL CRLF
FIRST:
    MOV AH,01H
    INT 21H
    XOR AH,AH
    CMP AL,"0"
    JB AGAIN
    CMP AL,"9"
    JA AGAIN

    SUB AL,"0"
    MOV DL,AL
    MUL DL
    MUL DX
    MOV DX,AX

    MOV AH,4CH
    INT 21H
CODE ENDS
END START