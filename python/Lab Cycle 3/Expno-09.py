num=int(input("Enter a number : "))
sum=0
num1=num
count=0
temp=num
while num1>0:
	count=count+1
	num1=num1//10
while temp>0:
	digit=temp%10
	sum+=digit**count
	temp//=10
if num==sum:
	print(num," is an Amstrong number")
else:
	print(num," is not an amstrong number")
