SORT PROC
;入口参数:要排序的数组段地址放在AX,偏移地址放BX,数组长度放CX
;功能:冒泡排序,仅支持8位DB型,由小到大
    PUSH AX
    PUSH BX
    PUSH CX
    PUSH DX
    PUSHF

    MOV DS,AX
    MOV AX,CX
    DEC CX
AGAIN1_SORT:
    PUSH CX
    PUSH BX
    ;计算内层起始的偏移地址

AGAIN2_SORT:
    MOV DL,[BX]
    MOV DH,[BX+1]
    CMP DL,DH
    JB BELOW_SORT
    MOV [BX],DH
    MOV [BX+1],DL
BELOW_SORT:
    INC BX
    LOOP AGAIN2_SORT

    POP BX
    POP CX
    LOOP AGAIN1_SORT
    POPF
    POP DX
    POP CX
    POP BX
    POP AX
    RET
SORT ENDP