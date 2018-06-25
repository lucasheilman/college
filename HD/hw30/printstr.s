!!! print a null-terminated string on standard output
!!! example of a function call and definition
!!! R.Brown 11/05

	_EXIT = 1
	_WRITE = 4
	_STDOUT = 1

.SECT .TEXT
	PUSH	str		! print the string
	CALL	printstr
	ADD	SP,2		! clean up stack

	PUSH	0		! normal exit status
	PUSH	_EXIT
	SYS
	
!! printstr
!!  1 arg -- address of a null-terminated string
!!  state change -- the chars of arg1 are printed, excluding the
!!    terminating nullbyte
!!  return -- none

printstr:
	PUSH	BX		! save registers
	PUSH	BP
	MOV	BP,SP		! set up BP

	MOV	BX,6(BP)	! copy argument value to BX
	!! loop invar - all bytes seen so far are not nullbytes
1:	CMPB	(BX),0		! if the next char (BX) is not a nullbyte...
	JE	2f
	INC	BX		! then add 1 to BX
	JMP	1b		! and look at next char

2:	!! assert - BX holds address of first nullbyte in the arg string
	SUB	BX,6(BP)	! store length of arg string in BX 
	PUSH	BX		! print arg string
	PUSH	6(BP)
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8		! clean stack

	POP	BP		! restore registers
	POP	BX
	RET

.SECT .DATA
dummy:	.BYTE 65
str:	.ASCIZ "Test string"

.SECT .BSS
	