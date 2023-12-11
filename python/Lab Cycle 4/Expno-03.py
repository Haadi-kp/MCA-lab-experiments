def compare():
	num=int(input("Enter a limit: "))
	str1=input("enter a string : ")
	str2=input("enter the second string : ")
	if(str1[0:num]==str2[0:num]):
		return True
	else:
		return False


flag=compare()
if(flag):
	print("true")
else:
	print("false")
