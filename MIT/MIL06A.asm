;ASSIGNMENT.NO:6.
;TITLE:Write X86/64 ALP to perform multiplication of two 8-bit hexadecimal numbers. Use successive addition
	and Accept input from the user. (use of 64-bit registers is expected)
;------------------------------------------------------------------------------------------------------------
section .data
welmsg db 10,'Multiplication using successive addition',10
welmsg_len equ $-welmsg
nummsg db 10,'Enter two digits of Number::'
nummsg_len equ $-nummsg
resmsg db 10,'Multiplication of elements::'
resmsg_len equ $-resmsg
blankmsg db 10,'',10
blank_len equ $-blankmsg
section .bss
numascii resb 03
multi1 resb 01
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

dispmsg nummsg,nummsg_len
accept numascii,3





call packnum
mov [multi1],bl

dispmsg nummsg,nummsg_len
accept numascii,3
call packnum
mov ecx,00h
mov eax,[multi1]

addup:

add ecx,eax
dec bl
jnz addup

mov [resl],ecx
dispmsg resmsg,resmsg_len
mov ebx,[resl]

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




ov al,bl
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
;----------------------------------------------------
;admin1@cnlcomp17:~/Desktop$ nasm -f elf64 MIL06A.asm -o MIL06A.o
;admin1@cnlcomp17:~/Desktop$ ld -o MIL06A MIL06A.o
;admin1@cnlcomp17:~/Desktop$ ./MIL06A
;Multiplication using successive addition
;Enter two digits of Number::10
;Enter two digits of Number::20
;Multiplication of elements::0200
;admin1@cnlcomp17:~/Desktop$ 


