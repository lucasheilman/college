        _EXIT    = 1             
        _GETCHAR = 117             
        _WRITE   = 4             
        _STDIN   = 0             
        _STDOUT  = 1
        MAXBUFF  = 100
.SECT .TEXT                     
start:  ! print prompt, as detailed in next five instructions

	PUSH	buff-prompt	!size of prompt
	PUSH	prompt		!adress of prompt
	PUSH	_STDOUT		
	PUSH	_WRITE
	SYS
	ADD	SP,8		!clean stack
	PUSH	MAXBUFF
	PUSH	buff
	CALL	gettrans
	ADD	SP,4
3:
	PUSH	MAXBUFF		!size of buff
	PUSH	buff		!address of buff
	CALL	getline		!call getline function
	ADD	SP,4		!clean stack
	CMP	(buff),"\n"	!compares buff to a newline
	JE	4f		!if it is, jump to 4
	PUSH	AX		!size of buff
	PUSH	buff		!the address of the  line from getline
	PUSH	_STDOUT		
	PUSH	_WRITE
	SYS
	ADD	SP,8
	JMP	3b		!jump back to  3
4:	
	PUSH	0		
	PUSH	_EXIT
	SYS

getline:
	PUSH	BP
	MOV	BP,SP
	PUSH	BX
	PUSH	CX
	MOV	BX,4(BP)	!move buff to bx
	MOV	CX,4(BP)	!move buff to cx
	ADD	CX,6(BP)	!add maxbuff to cx
	SUB	CX,1		!subtract 1 from cx
1:
	CMP	CX,BX		!compare buff to cx
	JE	2f		!jump to 2 if theyre equal
	PUSH	_GETCHAR	!get a character
	SYS
	ADD	SP,2		!clean the stack
	CMPB	AL,-1		!AL is the value of getchar, compare it to a "nullbyte"
	JE	2f		!jump to 2 if they are equal
	MOVB	(BX),AL		!move the value of al to the value of bx
	INC	BX		!increment the address of bx
	CMPB	AL,"\n"		!compare AL to a newline
	JNE	1b		!do the loop of 1 again if they are not equal
2:
	MOVB	(BX),"\0"	!move a null byte to the value of bx
	SUB	BX,4(BP)	!subtract buff from the address of bx
	MOV	AX,BX		!move bx to ax because ax can cross functions
	POP	CX
	POP	BX
	POP	BP
	RET

gettrans:
	PUSH	BP
	PUSH	BX
	MOV	BP,SP
	PUSH	6(BP)		!size of buff
	PUSH	4(BP)		!address of buff
	CALL	getline		!call getline function
	ADD	SP,4		!clean stack	

	MOV	BX,4(BP)	!move buff to bx
	MOVB	AL,(BX)		!move the first bit of buff to al
	MOVB	(inchar),AL	!move that bit to inchar
	MOVB	AL,2(BX)	!move the second bit of buff to al
	MOVB	(outchar),AL	!move that bit to outchar

	POP	BX
	POP	BP
	RET
	  
.SECT .DATA                     
prompt:                         
.ASCII  "Type one line, then press ENTER:  "
buff:
.BYTE	MAXBUFF
inchar:
.BYTE	1
outchar:
.BYTE	1
.SECT .BSS
