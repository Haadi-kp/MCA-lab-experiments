lst=[]
n=int(input("enter the limit:"))
for i in range(n):
	value=int(input("enter the value: "))
	if value>100:
		lst.append("over")
	else:
		lst.append(value)
print(lst)
