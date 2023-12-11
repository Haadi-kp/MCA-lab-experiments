def simple_interest(p,t,r):
        print('The principal is : ', p)
        print('The time period is : ', t)
        print('The rate of interest is : ',r)
        si = (p * t * r)/100
        print('The Simple Interest is : ', si)

P = int(input("Enter the principal amount :"))
T = int(input("Enter the time period :"))
senior=input("Is customer is senior citizen(yes/no) : ") 
print()
if(senior=="yes"):
        R=12
else:
        R=10
simple_interest(P,T,R)

