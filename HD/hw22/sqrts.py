# print square roots in Python language.  R. Brown, 9/2010 

from math import sqrt

print("sqrt(n)\n--------")
max = int(sys.argv[1])
for n in range(0, max+1):
    print(sqrt(n))
