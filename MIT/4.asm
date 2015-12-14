
;ASSIGNMENT.NO:4.
;TITLE:4. Write X86/64 ALP for the following operations on the string entered by the user.
 	(use of 64-bit registers is expected)
	a) Calculate Length of the string b) Reverse the string
	c) Check whether the string is palindrome
			OR
	Make your program user friendly by providing MENU like:
	(a) Enter the string b) Calculate length of string c) Reverse string d) Check palindrome e) Exit
	Display appropriate messages to prompt the user while accepting the input and displaying the result.

section .data
	welmsg db 10,'Welcome to Assembly Language Program',10
	welmsg_len equ $-welmsg
	accmsg db 10,'Please enter the string:: '
	accmsg_len equ $-accmsg
	lenmsg db 10,'Length of the string is:: '
	lenmsg_len equ $-lenmsg
	revmsg db 10,'Reverse string is:: '
	revmsg_len equ $-revmsg
	palimsg db 10,'String is Palindrome....'
	palimsg_len equ $-palimsg
	npalimsg db 10,'String is not Palindrome....'
	npalimsg_len equ $-npalimsg

section .bss
	accbuff resb 50
	accbuff_len equ $-accbuff
	revbuff resb 50
	actlen resq 1
	dnumbuff resb 16

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
	linuxsyscall 01,01,welmsg,welmsg_len		;display welcome message
	linuxsyscall 01,01,accmsg,accmsg_len		;display enter string message
	linuxsyscall 0,0,accbuff,accbuff_len		;accept string
	dec rax							;calculate actual 
									length of string entered




;by decrementing rax as 
									it includes ENTER char
	mov [actlen],rax						;Following lines displays 
									length of string
	linuxsyscall 01,01,lenmsg,lenmsg_len		;display length message
	mov rbx,[actlen]						;load count in rbx for display
	call disp64_proc						;call display procedure 
									to display RBX contents

									;Following lines will 		
									reverse the string and display it
	mov rsi,accbuff					;Point rsi to first 
								byte of original string
	mov rdi,revbuff					;Point rdi to first byte 
								of reverse string buffer
	mov rcx,[actlen]				;Load count in RCX
	add rsi,rcx					;Add count in rsi to point 
							to next byte after original string
	dec rsi						;Decrement rsi to point to
								 last char of original string
again:
	mov al,[rsi]					;Copy char from 
								original string and
	mov [rdi],al					;Copy to reverse
								 string buffer 
	dec rsi						;decrement pointer to reverse
	inc rdi						;increment pointer 
	loop again
	linuxsyscall 01,01,revmsg,revmsg_len		;display reverse 
									string message
	linuxsyscall 01,01,revbuff,[actlen]		;display reverse string

;Following lines will check for palindrome

	mov rsi,accbuff					;Point rsi to first 
								byte of original string
	mov rdi,revbuff					;Point rdi to first
							 byte of reverse string buffer
	mov rcx,[actlen]				;Load count in RCX
	shr rcx,1					;Divide count by 2




	repe cmpsb					;Compare original and 
							reverse string char by char
	jne nopali					;If last comparison is not 
							equal, string is not palindrome
	linuxsyscall 01,01,palimsg,palimsg_len		;display string 
									palindrome message
	jmp exit
nopali:
	linuxsyscall 01,01,npalimsg,npalimsg_len	;display string not palindrome message
exit:
	linuxsyscall 01,01,thankmsg,thankmsg_len
	mov rax,60		;Exit
	mov rbx,00
	syscall

disp64_proc:
	mov rdi,dnumbuff	;point esi to buffer
	mov rcx,16		;load number of digits to display 

dispup1:
	rol rbx,4		;rotate number left by four bits
	mov dl,bl		;move lower byte in dl
	and dl,0fh		;mask upper digit of byte in dl
	cmp dl,09h		;compare with 9
	jbe dispskip1		;if less than or equal 
					to 9 skip adding 07 more 
	add dl,07h		
dispskip1:
	add dl,30h		;add 30h to calculate ASCII code
	mov [rdi],dl		;store ASCII code in buffer
	inc rdi			;point to next byte
	loop dispup1		;decrement the count of digits to display
					;if not zero jump to repeat
	linuxsyscall 01,01,dnumbuff,16	;Dispays only lower 
							5 digits as upper three are '0'
		ret

OUTPUT:
admin1@cnlcomp17:~/Desktop/PPS/MIL$ nasm -f elf64 mil04.asm -o mil4.o
admin1@cnlcomp17:~/Desktop/PPS/MIL$ ./mil4

Welcome to Assembly Language Program

Please enter the string:: ABCDE

Length of the string is:: 0000000000000005
Reverse string is:: EDCBA
String is not Palindrome....

