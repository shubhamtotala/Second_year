;ASSIGNMENT.NO:6.
;TITLE:Write X86/64 ALP to perform multiplication of two 8-bit hexadecimal numbers.add and shift method.
	 Accept input from the user. (use of 64-bit registers is expected);
;---------------------------------------------------------------------------------------------------
section .data
welmsg db 10,'Multiplication using add and shift method',10
welmsg_len equ $-welmsg
nummsg db 10,'Enter two digits of Number::'
nummsg_len equ $-nummsg
resmsg db 10,'Multiplication of elements::'
resmsg_len equ $-resmsg
blankmsg db 10,'',10
blank_len equ $-blankmsg

section .bss
numascii resb 03
multi1 resb 02
resl resb 02
multi2 resb 02
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
dispmsg nummsg,nummsg_len
accept numascii,3
call packnum





mov [multi1],bl

dispmsg nummsg,nummsg_len
accept numascii,3
call packnum
mov [multi2],bl

mov al,[multi1]

mov cl,0
mov edx,0
mov edx,08h
addup:
	rcr al,01
	jnc next1
	mov bh,00h
	shl bx,cl
	add [resl],bx
	mov bl,[multi2]
next1: 	inc cl
       	dec edx    
jnz addup


dispmsg resmsg,resmsg_len
mov bx,[resl]

call disp16_proc

dispmsg blankmsg,blank_len
mov eax,01 ;Exit
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
skip1: sub al,30h
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
dskip: add al,30h
mov [edi],al
inc edi
loop dup1

dispmsg dispbuff,4
ret
;----------------------------------------------
;admin1@cnlcomp17:~/Desktop$ nasm -f elf64 MIL06B.asm -o MIL06B.o
;admin1@cnlcomp17:~/Desktop$ ld -o MIL06B MIL06B.o
;admin1@cnlcomp17:~/Desktop$ ./MIL06B
;Multiplication using add and shift method
;Enter two digits of Number::11
;Enter two digits of Number::01
;Multiplication of elements::0011
;admin1@cnlcomp17:~/Desktop$ 

