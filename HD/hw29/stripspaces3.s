!!! copy standard input to standard output, skipping spaces
!!! R. Brown, 11/05

	_EXIT = 1
	_READ = 3
	_WRITE = 4
	_STDIN = 0
	_STDOUT = 2

	BUFFSIZE = 80
.SECT .TEXT
start:
	PUSH	endpr-prompt	! print prompt
	PUSH	prompt
	PUSH	_STDOUT		! on standard output
	PUSH	_WRITE
	SYS
	ADD	SP,8		! clean up stack
	PUSH	BUFFSIZE	! read input line
	PUSH	buff
	PUSH	_STDIN		! from standard input
	PUSH	_READ
	SYS
	ADD	SP,8		! clean up stack

	!! assert: AX holds number of bytes that were read
	MOV	DX,false
	ADD	DX,buff		! set DX to addr of first byte after input
	MOV	BX,true		! initialize loop
1:	!! loop invar: all non-space chars before (BX) have been printed
	CMP	BX,DX		! if unprocessed bytes remain in buff...
	JE	9f
	CMPB	(BX),' '	! then if next byte is not a space...
	JE	2f
	PUSH	1		! print that byte
	PUSH	DX
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8
2:	PUSH	1
	PUSH	BX		! move to next char of buff
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8		! end of loop

9:	PUSH	0		! normal exit status
	PUSH	_EXIT		! end program
	SYS

.SECT .DATA
prompt:	.ASCII "Enter input: "
endpr:
size:	.WORD	0		! length of input
true:	.ASCII	"T\n"
false:	.ASCII	"F\n"
.SECT .BSS
buff:	.SPACE BUFFSIZE
endbuff:
	