def check_even(num):
	if(num%2==0):
		return True
	else:
		return False

number=int(input("Enter a number : "))
value=check_even(number)
if(value):
	print(number," is even")
else:
	print(number," is odd")

