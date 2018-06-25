# print square roots in Python language.  R. Brown, 9/2010 

from math import factorial

print("n\tn!\n----------------")
n=0
while n<6:
    print(n,"\t",factorial(n))
    n=n+1
