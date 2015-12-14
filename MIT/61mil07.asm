
;ASSIGNMENT NO.7

section .data
    welmsg db 10,"***WELCOME TO 64 BIT PROGRAMMING***"
    welmsg_len equ $-welmsg
    meanmsg db 10,"CALCULATED MEAN IS:-"
    meanmsg_len equ $-meanmsg
    sdmsg db 10,"CALCULATED STANDARD DEVIATION IS:-"
    sdmsg_len equ $-sdmsg
    varmsg db 10,"CALCULATED VARIANCE IS:-"
    varmsg_len equ $-varmsg
    thanxmsg db 10,"THANK YOU FOR USING THE PROGRAM",10
    thanxmsg_len equ $-thanxmsg
    array dd 102.56,198.21,100.67,230.78,67.93
    arraycnt dw 05
    dpoint db '.'
    hdec dq 100
                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
section .bss
    dispbuff resb 1
    resbuff rest 1
	mean resd 1
	variance resd 1
    %macro linuxsyscall 4
        mov rax,%1
        mov rdi,%2
        mov rsi,%3	
        mov rdx,%4
        syscall
    %endmacro   

section .text
   global _start
_start:
    linuxsyscall 01,01,welmsg,welmsg_len
	finit
	fldz
	mov rbx,array
	mov rsi,00
	xor rcx,rcx
	mov cx,[arraycnt]
up:	fadd dword[RBX+RSI*4]
	inc rsi
	loop up

	fidiv word[arraycnt]
	fst dword[mean]
	linuxsyscall 01,01,meanmsg,meanmsg_len	
	call dispres






	MOV RCX,00
	MOV CX,[arraycnt]
	MOV RBX,array
	MOV RSI,00
	FLDZ

up1:	FLDZ
	FLD DWORD[RBX+RSI*4]
	FSUB DWORD[mean]
	FST ST1
	FMUL
	FADD
	INC RSI
	LOOP up1
	FIDIV word[arraycnt]
	FST dWORD[variance]
	FSQRT
	linuxsyscall 01,01,sdmsg,sdmsg_len
	CALL dispres
	FLD dWORD[variance]
	linuxsyscall 01,01,varmsg,varmsg_len
	CALL dispres
	linuxsyscall 01,01,thanxmsg,thanxmsg_len

exit: mov rax,60
      mov rdi,0
      syscall

disp8_proc:
	mov rdi,dispbuff
	mov rcx,02

back:	rol bl,04
	mov dl,bl
	and dl,0FH
	cmp dl,09
	jbe next1
	add dl,07H

next1:  add dl,30H
	mov [rdi],dl
	inc rdi
	loop back
	ret

dispres:
	fimul dword[hdec]
	fbstp tword[resbuff]
	xor rcx,rcx
	mov rcx,09H
	mov rsi,resbuff+9







up2:	push rcx
	push rsi
	mov bl,[rsi]
	call disp8_proc
	linuxsyscall 01,01,dispbuff,2	
	pop rsi
	dec rsi
	pop rcx
	loop up2
	linuxsyscall 01,01,dpoint,1
	mov bl,[resbuff]
	call disp8_proc
	linuxsyscall 01,01,dispbuff,2
	ret

;OUTPUT
---------------------------------------------------------------------------------------------
admin1@cnlcomp17:~$ cd Desktop
admin1@cnlcomp17:~/Desktop$ cd PPS
admin1@cnlcomp17:~/Desktop/PPS$ cd MIL
admin1@cnlcomp17:~/Desktop/PPS/MIL$ nasm -f elf64 61mil07.asm -o mil07.o
admin1@cnlcomp17:~/Desktop/PPS/MIL$ ld -o mil07 mil07.o
admin1@cnlcomp17:~/Desktop/PPS/MIL$ ./mil07

***WELCOME TO 64 BIT PROGRAMMING***
CALCULATED MEAN IS:-000000000000000140.30
CALCULATED STANDARD DEVIATION IS:-000000000000000062.32
CALCULATED VARIANCE IS:-000000000000003954.34
THANK YOU FOR USING THE PROGRAM
admin1@cnlcomp17:~/Desktop/PPS/MIL$ 



