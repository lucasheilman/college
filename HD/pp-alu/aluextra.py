#This code prints out all values of all logic gates with every different value combination of the control lines f0, f1, and f2, and a and b
#binval takes the value from the logic gates and returns 1 if true and 0 if false
def binval(x):
    if x:
        return 1
    else:
        return 0
#mbinval takes the value from the logic gates and returns 0 if true and 1 if false
def nbinval(x):
    if x:
        return 0
    else:
        return 1
#aandb takes two values and ands them
def aandb(a,b):
    return binval(a==1 and b==1)
#aandb3 takes three values and ands them
def aandb3(a,b,c):
    return binval(a==1 and b==1 and c==1)
#aorb takes two values and ors them
def aorb(a,b):
    return binval(a==1 or b==1)
#finalor takes eight values and ors them
def finalor(a,b,c,d,e,f,g,h):
    return binval(a==1 or b==1 or c==1 or d==1 or e==1 or f==1 or g==1 or h==1)
#bnot takes a value and returns a 1 if 0 and 0 if 1
def bnot(b):
    return binval(b==0)
#axorb takes two values and xors them
def axorb(a,b):
    return binval(a+b==1)
#anandb takes two values and nands them
def anandb(a,b):
    return nbinval(a==1 and b==1)
#anorb takes two values and nors them
def anorb(a,b):
    return nbinval(a==1 or b==1)
#anxorb takes two values and nxors them
def anxorb(a,b):
    return nbinval(a+b==1)
#alu takes the all the values from the logic gates and ors them to get the final output 
def alu(f0,f1,f2,a,b):
    return (finalor(aandb(aandb(a,b),aandb3(bnot(f0),bnot(f1),bnot(f2))),aandb(aorb(a,b),aandb3(f0,bnot(f1),bnot(f2))),aandb(bnot(b),aandb3(bnot(f0),f1,bnot(f2))),aandb(bnot(a),aandb3(f0,f1,bnot(f2))),aandb(anandb(a,b),aandb3(bnot(f0),bnot(f1),f2)),aandb(anorb(a,b),aandb3(f0,bnot(f1),f2)),aandb(axorb(a,b),aandb3(bnot(f0),f1,f2)),aandb(anxorb(a,b),aandb3(f0,f1,f2))))
#print_call prints the values that are being put into the alu, the logic gate that is being activated, and the output
def print_call(f0,f1,f2,a,b):
    #lg is the logic gate that is being activated
    if aandb3(bnot(f0),bnot(f1),bnot(f2))==1:
        lg="AND"
    elif aandb3(f0,bnot(f1),bnot(f2))==1:
        lg="OR"
    elif aandb3(bnot(f0),f1,bnot(f2))==1:
        lg="BNOT"
    elif aandb3(f0,f1,bnot(f2))==1:
        lg="ANOT"
    elif aandb3(bnot(f0),bnot(f1),f2)==1:
        lg="NAND"
    elif aandb3(f0,bnot(f1),f2)==1:
        lg="NOR"
    elif aandb3(bnot(f0),f1,f2)==1:
        lg="XOR"
    elif aandb3(f0,f1,f2)==1:
        lg="NXOR"
    print("")
    print("F0=",f0,", F1=",f1,", F2=",f2,", A=",a,", B=",b,", Logic gate=",lg,sep='')
    print("alu(",f0,", ",f1,", ",f2,", ",a,", ",b,") --> ",alu(f0,f1,f2,a,b),sep='')
#print_section calls print_call to to print out all the different possible combinations of f0, f1, f2, a, and b
def print_section():
    print_call(0,0,0,0,0)
    print_call(0,0,0,0,1)
    print_call(0,0,0,1,0)
    print_call(0,0,0,1,1)
    print_call(0,0,1,0,0)
    print_call(0,0,1,0,1)
    print_call(0,0,1,1,0)
    print_call(0,0,1,1,1)
    print_call(0,1,0,0,0)
    print_call(0,1,0,0,1)
    print_call(0,1,0,1,0)
    print_call(0,1,0,1,1)
    print_call(0,1,1,0,0)
    print_call(0,1,1,0,1)
    print_call(0,1,1,1,0)
    print_call(0,1,1,1,1)
    print_call(1,0,0,0,0)
    print_call(1,0,0,0,1)
    print_call(1,0,0,1,0)
    print_call(1,0,0,1,1)
    print_call(1,0,1,0,0)
    print_call(1,0,1,0,1)
    print_call(1,0,1,1,0)
    print_call(1,0,1,1,1)
    print_call(1,1,0,0,0)
    print_call(1,1,0,0,1)
    print_call(1,1,0,1,0)
    print_call(1,1,0,1,1)
    print_call(1,1,1,0,0)
    print_call(1,1,1,0,1)
    print_call(1,1,1,1,0)
    print_call(1,1,1,1,1)
print_section()
