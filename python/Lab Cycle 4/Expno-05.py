
def add_num(*args):
	"""
	This function uses variable length 
	argument.
	"""
	return sum(args)

lst= input("Enter integers (comma separated) : ").split(",")
lst= [int(num) for num in lst ]
result = add_num(*lst)

print("The sum of the integers is: ",result)
