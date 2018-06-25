#This code emmulates an ALU and prints out every different input that can be recieved and the output for that input. Lucas Heilman, 11/2/15
#binval takes the input from the logic gates and turns it to a 1 if true and a 0 if false
def binval(x):
    if x:
        return 1
    else:
        return 0
#aandb takes two values and ands them
def aandb(a,b):
    return binval(a==1 and b==1)
#aandb3 takes three values and ands them
def aandb3(a,b,c):
    return binval(a==1 and b==1 and c==1)
#aorb takes two value and ands them
def aorb(a,b):
    return binval(a==1 or b==1)
#finalor takes four values and ors them
def finalor(a,b,c,d):
    return binval(a==1 or b==1 or c==1 or d==1)
#bnot takes a value and turns it into a 1 if it was a 0 and a 0 if it was a 1
def bnot(b):
    return binval(b==0)
#axorb takes two values and xors them
def axorb(a,b):
    return binval(a+b==1)
#aplusb takes the control lines, a, b and the carry-in and functions as the adder in the alu
def aplusb(f0,f1,a,b,c):
    return aandb(axorb(c,axorb(a,b)),aandb(f0,f1))
#carryout takes the control lines, a, b and the carry-in and returns the carry-out
def carryout(f0,f1,a,b,c):
    return aorb(aandb3(aandb(f0,f1),a,b),aandb3(aandb(f0,f1),axorb(a,b),c))
#alu takes all values and ors them together to get the final output, this output is shifted one spot to the left and added to the carryout
def alu(f0,f1,inva,ena,enb,c_i,a,b):
    return (int((int(bin((finalor(aandb(aandb(axorb(aandb(ena,a),inva),aandb(b,enb)),aandb(bnot(f0),bnot(f1))),aandb(aorb(axorb(aandb(ena,a),inva),aandb(b,enb)),aandb(bnot(f0),f1)),aandb(bnot(aandb(enb,b)),aandb(f0,bnot(f1))),aplusb(f0,f1,axorb(aandb(ena,a),inva),aandb(enb,b),c_i)))),2)<<1)+int(bin(carryout(f0,f1,axorb(aandb(a,ena),inva),aandb(b,enb),c_i)),2)))
#print_call takes four arguments and creates a section of calls of alu with all different values for a, b, and the carry-in
def print_call(f0,f1,inva,ena,enb):
    print("")
    print("F0=",f0,", F1=",f1,", INVA=",inva,", ENA=",ena,", ENB=",enb,sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",0,", ",0,", ",0,") --> ",alu(f0,f1,inva,ena,enb,0,0,0),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",0,", ",0,", ",1,") --> ",alu(f0,f1,inva,ena,enb,0,0,1),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",0,", ",1,", ",0,") --> ",alu(f0,f1,inva,ena,enb,0,1,0),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",0,", ",1,", ",1,") --> ",alu(f0,f1,inva,ena,enb,0,1,1),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",1,", ",0,", ",0,") --> ",alu(f0,f1,inva,ena,enb,1,0,0),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",1,", ",0,", ",1,") --> ",alu(f0,f1,inva,ena,enb,1,0,1),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",1,", ",1,", ",0,") --> ",alu(f0,f1,inva,ena,enb,1,1,0),sep='')
    print("alu(",f0,", ",f1,", ",inva,", ",ena,", ",enb,", ",1,", ",1,", ",1,") --> ",alu(f0,f1,inva,ena,enb,1,1,1),sep='')
#print_section calls print_call and prints all values for the control lines, inva, ena, and enb and prints them 
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
