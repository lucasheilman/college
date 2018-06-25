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
	
	PUSH	MAXBUFF		!size of buff
	PUSH	buff		!address of buff
	CALL	getline		!call getline function
	ADD	SP,4		!clean stack
	PUSH	AX		!size of buff
	PUSH	buff		!the line
	PUSH	_STDOUT		
	PUSH	_WRITE
	SYS
	ADD	SP,8
	PUSH	0		
	PUSH	_EXIT
	SYS

getline:
	PUSH	BP
	MOV	BP,SP
	PUSH	BX
	PUSH	CX
	MOV	BX,4(BP)
	MOV	CX,4(BP)
	ADD	CX,6(BP)
	SUB	CX,1
1:
	CMP	CX,BX
	JE	2f
	PUSH	_GETCHAR
	SYS
	ADD	SP,2
	CMPB	AL,-1
	JE	2f
	MOVB	(BX),AL
	INC	BX
	CMPB	AL,"\n"
	JNE	1b	
2:
	MOVB	(BX),"\0"
	SUB	BX,4(BP)
	MOV	AX,BX
	POP	CX
	POP	BX
	POP	BP
	RET
      
        
.SECT .DATA                     
prompt:                         
.ASCII  "Type one line, then press ENTER:  "
buff:
.BYTE	MAXBUFF
.SECT .BSS
