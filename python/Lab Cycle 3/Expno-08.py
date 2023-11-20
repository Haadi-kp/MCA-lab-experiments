def reverse_number(n):
        reversed_num=0
        while n>0:
                remainder=n%10
                reversed_num=reversed_num*10+remainder
                n//=10
        print(reversed_num)
n=int(input("Enter a number:"))
reverse_number(n)
