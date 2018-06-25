#This code takes an input (16 bit hexadecimal) and outputs the hamming code for that specific input (21 bit hexidecimal). Lucas Heilman, 10/14/15
def main():
    #x is the 16 bit hexadecimal input, which gets turned into a binary number
    x=int(bin(int(input("Enter a 16 bit hexadecimal number"),16)),2)
    #maskforpar1 is the binary code that picks out the important bits for parity bit 1
    maskforpar1=int(bin(int("dab5",16)),2)
    #maskforpar2 is the binary code that picks out the important bits for parity bit 2
    maskforpar2=int(bin(int("b66c",16)),2)
    #maskforpar4 is the binary code that picks out the important bits for parity bit 4
    maskforpar4=int(bin(int("71e3",16)),2)
    #maskforpar8 is the binary code that picks out the important bits for parity bit 8
    maskforpar8=int(bin(int("0fe0",16)),2)
    #maskforpar16 is the binary code that picks out the important bits for parity bit 16
    maskforpar16=int(bin(int("001f",16)),2)
    #par1nums is the important bits for parity bit 1
    par1nums=x&maskforpar1
    #par2nums is the important bits for parity bit 2
    par2nums=x&maskforpar2
    #par4nums is the important bits for parity bit 4
    par4nums=x&maskforpar4
    #par8nums is the important bits for parity bit 8
    par8nums=x&maskforpar8
    #par16nums is the important bits for parity bit 16
    par16nums=x&maskforpar16
    #count holds the amount of 1's that are in the binary code of par1nums, parity1 is the number that is first parity bit, depending on if count is even or odd
    count=0
    for a in bin(par1nums):
        if a == "1":
            count = count+1
        if count%2==0:
            parity1=0
        else:
            parity1=int(bin(int("100000",16)),2)
    #count holds the amount of 1's that are in the binary code of par2nums, parity2 is the number that is second parity bit, depending on if count is even or odd
    count=0
    for a in bin(par2nums):
        if a == "1":
            count = count+1
        if count%2==0:
            parity2=0
        else:
            parity2=int(bin(int("80000",16)),2)
    #count holds the amount of 1's that are in the binary code of par4nums, parity4 is the number that is fourth parity bit, depending on if count is even or odd
    count=0
    for a in bin(par4nums):
        if a == "1":
            count = count+1
        if count%2==0:
            parity4=0
        else:
            parity4=int(bin(int("20000",16)),2)
    #count holds the amount of 1's that are in the binary code of par8nums, parity8 is the number that is eigth parity bit, depending on if count is even or odd
    count=0
    for a in bin(par8nums):
        if a == "1":
            count = count+1
        if count%2==0:
            parity8=0
        else:
            parity8=int(bin(int("2000",16)),2)
    #count holds the amount of 1's that are in the binary code of par16nums, parity16 is the number that is first parity bit, depending on if count is even or odd
    count=0
    for a in bin(par16nums):
        if a == "1":
            count = count+1
        if count%2==0:
            parity16=0
        else:
            parity16=int(bin(int("20",16)),2)
    #maskforbit3 is the binary code that picks out bit 3 so that it can be moved to its correct spot
    maskforbit3=int(bin(int("8000",16)),2)
    #maskforbits5to7 is the binary code that picks out bits 5 through 7 so that it can be moved to its correct spot
    maskforbits5to7=int(bin(int("3800",16)),2)
    #maskforbits9to15 is the binary code that picks out bits 9 through 15 so that it can be moved to its correct spot
    maskforbits9to15=int(bin(int("fe0",16)),2)
    #maskforbits17to21 is the binary code that picks out bits 17 through 21 so that it can be moved to its correct spot
    maskforbits17to21=int(bin(int("1f",16)),2)
    #bit3spot is bit 3 in its correct spot
    bit3spot=x&maskforbit3
    #bit5to7spot is bits 5 through 7 in their correct spots
    bit5to7spot=x&maskforbits5to7
    #bit9to15spot is bits 9 through 15 in their correct spots
    bit9to15spot=x&maskforbits9to15
    #bit17to21spot is bits 17 through 21 in their correct spots
    bit17to21spot=x&maskforbits17to21
    bit3spot=bit3spot<<3
    bit5to7spot=bit5to7spot<<2
    bit9to15spot=bit9to15spot<<1
    #finaloutput is all the bit groups and parity bits added together in binary to create the hamming code, and then becomes the hexadecimal output 
    finaloutput=hex(parity1+parity2+bit3spot+parity4+bit5to7spot+parity8+bit9to15spot+parity16+bit17to21spot)
    print(finaloutput[2:])
main()
