
;TITLE: Write X86/64 Assembly language program (ALP) to add array of N hexadecimal numbers stored in the
	memory. Accept input from the user.
;ASSIGNMENT.NO:3

section .data
	welmsg db 10,'Welcome to MIL assignment 01',10,13
	welmsg_len equ $-welmsg
	cntmsg db 10,'Enter two digits of Count N::',10,13
	cntmsg_len equ $-cntmsg
	nummsg db 10,'Enter two digits of Number::',10,13
	nummsg_len equ $-nummsg
	resmsg db 10,'Addition of array elements::',10,13
	resmsg_len equ $-resmsg
section .bss
	numascii resb 03
	cnt resb 01	
	resl resb 01
	resh resb 01
	dispbuff resb 04
%macro dispmsg 2
	mov eax,04
	mov ebx,01
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
%macro accept 2
	mov eax,03
	mov ebx,0
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
section .text
global _start
_start:
	dispmsg welmsg,welmsg_len
	dispmsg cntmsg,cntmsg_len
	accept numascii,3
	call packnum
	mov [cnt],bl
	xor rcx,rcx
	mov cl,[cnt]
addup:
	push rcx
	dispmsg nummsg,nummsg_len
	accept numascii,3
	call packnum
	add [resl],bl
	adc byte [resh],0
	pop rcx




	loop addup
	dispmsg resmsg,resmsg_len
	mov bl,[resl]
	mov bh,[resh]
	call disp16_proc
	dispmsg thankmsg,thankmsg_len
	mov eax,01		;Exit
	mov ebx,00
	int 80h
packnum:
	mov bl,0
	mov ecx,02
	mov esi,numascii
up1:
	rol bl,04
	mov al,[esi]
	cmp al,39h
	jbe skip1
	sub al,07h
skip1:	
	sub al,30h
	add bl,al
	inc esi
	loop up1
	ret	
disp16_proc:
	mov ecx,4
	mov edi,dispbuff
dup1:
	rol bx,4
	mov al,bl
	and al,0fh
	cmp al,09
	jbe dskip
	add al,07h
dskip:	
	add al,30h
	mov [edi],al
	inc edi
	loop dup1
	dispmsg dispbuff,4
	ret
;########### OUTPUT ##############
;[mahendra@(none) MILALP]$ nasm -f elf64 MIL1201.asm
;[mahendra@(none) MILALP]$ ld -o MIL1201 MIL1201.o
;[mahendra@(none) MILALP]$ ./MIL1201
;Welcome to MIL assignment 01
;Enter two digits of Count N::03
;Enter two digits of Number::FF
;Enter two digits of Number::FF
;Enter two digits of Number::FF
;Addition of array elements::02FD


