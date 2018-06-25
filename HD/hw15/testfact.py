def factorial(n):
    if n<=10 and n>=1:
        n=n*factorial(n-1)
    else:
        return n
def main():
    print(factorial(10))
main()
