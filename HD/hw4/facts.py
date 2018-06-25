# print square roots in Python language.  R. Brown, 9/2010 

from math import factorial

print("n\tn!\n----------------")

for n in range(0, 6):
    print(n,"\t",factorial(n))
