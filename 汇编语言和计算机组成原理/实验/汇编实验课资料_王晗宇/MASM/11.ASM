;数据段
data segment
	;定义字节大小(8位)的字符串，变量名为string
	;db表示字节
	;0dh,0ah表示回车换行
	;$表示字符串终止符
	string db 'Hello World!',0dh,0ah,'$' 
data ends

;代码段
code segment
assume cs:code,ds:data 
start:
	;push ds
	;mov ax,0
	;push ax
	mov ax,data
	mov ds,ax
	;------
	lea dx,string
	mov ah,09h ;ah是ax的高8位，功能号09h表示输出dx指向的字符串string
	int 21h ;中断指令，调用用户程序，执行ah中设置的09h号功能
	;------
	mov ah,4ch ;功能号4ch表示从用户程序返回操作系统，结束程序
	int 21h
code ends
	end start