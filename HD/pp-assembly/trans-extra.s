!The purpose of this code is to take a line of input that dictates either a single or double  translation to happen, it then takes more lines of input and does the translations on those lines.
!Once you end the program with a newline, it prints a summary statement that includes the number of characters, number of words, and number of lines. Lucas Heilman 12/13/15
        _EXIT    = 1             
        _GETCHAR = 117             
        _WRITE   = 4             
        _STDIN   = 0             
        _STDOUT  = 1
	_STDERR  = 2
        MAXBUFF  = 100
.SECT .TEXT                     
start: 

	PUSH	endpr-prompt	!size of prompt
	PUSH	prompt		!adress of prompt
	PUSH	_STDOUT		
	PUSH	_WRITE
	SYS
	ADD	SP,8		!clean stack
	PUSH	MAXBUFF		!size of buff
	PUSH	buff		!address of buff
	CALL	getline		!call getline function
	ADD	SP,4		!clean stack
	PUSH	buff
	CALL	gettrans
	ADD	SP,2
	CMP	AX,0
	JE	2f

1:
	PUSH	MAXBUFF		!size of buff
	PUSH	buff		!address of buff
	CALL	getline		!call getline function
	ADD	SP,4		!clean stack
	CMP	(buff),"\n"	!compares buff to a newline
	JE	2f		!if it is, jump to 2
	PUSH	buff		
	CALL	translate
	ADD	SP,2
	INC	(wordct)
	PUSH	AX
	PUSH	buff
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8
	JMP	1b		!jump back to  1
2:
	CALL	print_summary
	PUSH	0		
	PUSH	_EXIT
	SYS
!getline takes in lines of input and moves it into the variable buff
getline:
	PUSH	BP
	MOV	BP,SP
	PUSH	BX
	PUSH	CX
	MOV	BX,4(BP)	!move buff to bx
	MOV	CX,4(BP)	!move buff to cx
	ADD	CX,6(BP)	!add maxbuff to cx
	SUB	CX,1		!subtract 1 from cx
3:
	CMP	CX,BX		!compare buff to cx
	JE	4f		!jump to 2 if theyre equal
	PUSH	_GETCHAR	!get a character
	SYS
	ADD	SP,2		!clean the stack
	CMPB	AL,-1		!AL is the value of getchar, compare it to a nullbyte
	JE	4f		!jump to 2 if they are equal
	MOVB	(BX),AL		!move the value of al to the value of bx
	INC	BX		!increment the address of bx
	CMPB	AL,"\n"		!compare AL to a newline
	JNE	3b		!do the loop of 1 again if they are not equal
4:
	MOVB	(BX),"\0"	!move a null byte to the value of bx
	SUB	BX,4(BP)	!subtract buff from the address of bx
	MOV	AX,BX		!move bx to ax because ax can cross functions
	POP	CX
	POP	BX
	POP	BP
	RET
!gettrans takes the first line of input to set as the translation. This line is either 4 characters long, to do one translation, or 8 characters long, to do 2 translations. To input 2 translations the input would look like (k L p D\n)
gettrans:
	PUSH	BP
	PUSH	BX
	MOV	BP,SP
	CALL	checktrans
	CMP	(inputlength),0	!if input length is 0
	JE	2f		!go to 2
1:
	MOV	BX,6(BP)	!move buff to bx
	MOVB	AL,(BX)		!move the first bit of buff to al
	MOVB	(inchar),AL	!move that bit to inchar
	MOVB	AL,2(BX)	!move the second bit of buff to al
	MOVB	(outchar),AL	!move that bit to outchar
	CMP	(inputlength),2	!if inputlength is not  2
	JNE	5f		!jump to 5
	MOVB	AL,4(BX)	!move the first bit of buff to al
	MOVB	(inchar2),AL	!move that bit to inchar
	MOVB	AL,6(BX)	!move the second bit of buff to al
	MOVB	(outchar2),AL	!move that bit to outchar
	MOV	AX,1		!the right stuff was entered
	POP	BX
	POP	BP
	RET
2:
	MOV	AX,0		!the right stuff was not entered
5:
	POP	BX
	POP	BP
	RET
!translate takes the variables buff, inchar, and outchar for one translation, and also takes inchar2 and outchar2 for 2 translations. It does the translations on buff. It also counts the total number of characters, lines, and words.	
translate:
	PUSH	BP
	MOV	BP,SP
	PUSH	BX
	PUSH	DX
	MOV	BX,4(BP)	!moves address of buff to bx
	MOV	DX,(inword)	!moves inword value to dx
1:
	CMPB	(BX),"\0"	!if bx is a nullbyte...
	JE	9f		!exit
	CMPB	(BX),0x41	!if bx is less than A
	JL	5f		!jump to being out of a word (DX=0)
	CMPB	(BX),0x7a	!if bx is greater than z
	JG	5f		!jump to being out of a word (DX=0)
	CMPB	(BX),0x5a	!if bx is less than or equal to Z
	JLE	2f		!jump to compare to being out of a  word
	CMPB	(BX),0x61	!if bx is greater than or equal to a
	JGE	2f		!jump to compare to being out of a word
	JMP	5f		!jump to being out of a word (DX=0)
2:
	CMP	DX,0		!if dx is out of a word
	JE	3f		!then jump to word counter
	JMP	4f		!else, jump to in word (DX=1) 
3:
	INC	(wordct)	!add 1 to word count
4:
	MOV	DX,1		!in a word
	JMP	6f		!jump to see if end of line
5:
	MOV	DX,0		!out of a word
6:
	CMPB	(BX),'\n'	!if bx is a newline
	JE	7f		!then jump to line counter
	JMP	8f		!else, jump to translater
7:
	INC	(linect)	!add 1 to linecount
8:
	MOVB	AL,(inchar)	!move inchar to AL
	CMPB	(BX),AL		!if bx equals AL(inchar)
	JE	3f		!then jump to change character to outchar
	CMPB	(inputlength),1	!if it is only one translate
	JE	2f		!jump to 2f
	MOVB	AL,(inchar2)	!move inchar2 to AL
	CMPB	(BX),AL		!if inchar2 equals al(inchar2)
	JE	4f		!jump to 4
	JMP	2f		!else, jump to character counter
3:
	MOVB	AL,(outchar)	!move outchar to AL
	MOVB	(BX),AL		!move AL(outchar) to BX, which will replace the current bx value
	JMP	2f
4:
	MOVB	AL,(outchar2)	!move outchar2 to al
	MOVB	(BX),AL		!move al(outchar2) to bx
2:
	INC	(charct)	!add one to character count
	INC	BX		!increment BX
	JMP	1b		!get next character
	
9:
	SUB	BX,4(BP)	!subtract first place of  buff, from current place in buff
	MOV	AX,BX		!move length of characters read in to ax
	POP	DX		
	POP	BX
	POP	BP
	RET
!print summary prints the summary statement that includes the number of characters, words, and lines	
print_summary:
	PUSH	BP
	MOV	BP,SP
	PUSH	characters-summary
	PUSH	summary		!print summary
	PUSH	_STDERR
	PUSH	_WRITE
	SYS
	ADD	SP,8
	PUSH	(charct)	!print charct
	PUSH	_STDERR
	CALL	printdec
	ADD	SP,4
	PUSH	words-characters
	PUSH	characters	!print characters
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8
	PUSH	(wordct)	!print wordct
	PUSH	_STDERR
	CALL	printdec
	ADD	SP,4
	PUSH	lines-words
	PUSH	words		!print words
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8
	PUSH	(linect)	!print linect
	PUSH	_STDERR
	CALL	printdec
	ADD	SP,4
	PUSH	endsum-lines
	PUSH	lines		!print lines
	PUSH	_STDOUT
	PUSH	_WRITE
	SYS
	ADD	SP,8
	POP	BP
	RET
	
checktrans:
	PUSH	BP
	MOV	BP,SP
	CMP	AX,4		!if ax has a length of 4
	JE	1f		!jump to 1
	CMP	AX,8		!if ax has length of 8
	JE	2f		!jump to 2
	JMP	3f		!else, exit
1:
	MOV	(inputlength),1	!change inputlength to 1 translation
	JMP	3f
2:
	MOV	(inputlength),2	!change inputlength to 2 translations
3:
	POP	BP
	RET

.SECT .DATA                     
prompt:                         
.ASCII  "Type one line, then press ENTER:  "
endpr:
inchar:
.BYTE	1
outchar:
.BYTE	1
inword:
.WORD	1
charct:
.WORD	0
wordct:
.WORD	0
linect:
.WORD	0
summary:
.ASCII	"Summary:\n "
characters:
.ASCII	" characters\n "
words:
.ASCII	" words\n "
lines:
.ASCII	" lines\n"
endsum:
inputlength:
.BYTE	0
inchar2:
.BYTE	1
outchar2:
.BYTE	1
.SECT .BSS
buff:	.SPACE	MAXBUFF
