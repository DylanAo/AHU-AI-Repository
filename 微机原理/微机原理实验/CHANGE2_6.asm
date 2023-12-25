DATA SEGMENT
    A DB 'AAAAA'
    B DB 'BBBBB'
    D DB 'CCCCC'
    DB '$'
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA

    CHANGE MACRO X,Y
    LOCAL AGAIN
        MOV CX,53
        LEA SI,X
        LEA DI,Y
    AGAIN:
        MOV AL,BYTE PTR [SI]
        XCHG BYTE PTR [DI],AL
        XCHG BYTE PTR [SI],AL 
        INC SI
        INC DI
        LOOP AGAIN
    ENDM

START:
    MOV AX,DATA
    MOV DS,AX
    XOR AX,AX

    CHANGE A,B
    CHANGE A,D

    LEA DX,A
    MOV AH,09H
    INT 21H

    MOV AH,4CH
    INT 21H
CODE ENDS
END START