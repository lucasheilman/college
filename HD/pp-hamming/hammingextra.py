#this program takes a input of a 21 bit hamming code in hexadecimal and finds any mistakes and fixes them. Lucas Heilman 10/15/15
def main():
    #inp is the input of the hamming code
    inp=input("Enter a 21 bit hamming code in hexadecimal")
    #x is the binary form of the hamming code
    x=bin(int(inp,16))[2:].zfill(21)
    #y is the list that holds the binary
    y=[]
    #a is added into the list of y
    for a in x:
        y=y+[a]
    #wrongbit will add the parity bits to find the one that is wrong
    wrongbit=0
    #numsforpar1 adds the total number of 1's that are important to parity bit one
    numsforpar1=int(y[2])+int(y[4])+int(y[6])+int(y[8])+int(y[10])+int(y[12])+int(y[14])+int(y[16])+int(y[18])+int(y[20])
    #numsforpar2 adds the total number of 1's that are important to parity bit two
    numsforpar2=int(y[2])+int(y[5])+int(y[6])+int(y[9])+int(y[10])+int(y[13])+int(y[14])+int(y[17])+int(y[18])
    #numsforpar4 adds the total number of 1's that are important to parity bit four
    numsforpar4=int(y[4])+int(y[5])+int(y[6])+int(y[11])+int(y[12])+int(y[13])+int(y[14])+int(y[19])+int(y[20])
    #numsforpar8 adds the total number of 1's that are important to parity bit eight
    numsforpar8=int(y[8])+int(y[9])+int(y[10])+int(y[11])+int(y[12])+int(y[13])+int(y[14])
    #numsforpar16 adds the total number of 1's that are important to parity bit sixteen
    numsforpar16=int(y[16])+int(y[17])+int(y[18])+int(y[19])+int(y[20])
    #evenorodd1 finds if numsforpar1 is even or odd
    evenorodd1=numsforpar1%2
    #evenorodd2 finds if numsforpar2 is even or odd
    evenorodd2=numsforpar2%2
    #evenorodd4 finds if numsforpar4 is even or odd
    evenorodd4=numsforpar4%2
    #evenorodd8 finds if numsforpar8 is even or odd
    evenorodd8=numsforpar8%2
    #evenorodd16 finds if nums for par16 is even or odd
    evenorodd16=numsforpar16%2
    if int(y[0])!=evenorodd1:
        wrongbit = wrongbit+1
    if int(y[1])!=evenorodd2:
        wrongbit = wrongbit+2
    if int(y[3])!=evenorodd4:
        wrongbit = wrongbit+4
    if int(y[7])!=evenorodd8:
        wrongbit=wrongbit+8
    if int(y[15])!=evenorodd16:
        wrongbit=wrongbit+16
    wrongbit = wrongbit-1
    if int(y[wrongbit]) == 1:
        y[wrongbit]='0'
    else:
        y[wrongbit]='1'
    #finalbin is the string form of list y
    finalbin=''.join(y)
    if wrongbit == -1:
        print(inp)
    else:
        print(hex(int(finalbin,2))[2:])
main()