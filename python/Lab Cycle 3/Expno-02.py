n=int(input(" How many terms : "))
n1,n2 = 0,1
count=0
if n<=0:
	print("Please enter a positive number")
elif n==1:
	print("Fibanacci sequence upto",n,":")
	print(n1)
else:
	print("Fibanacci sequence : ")
	while count<n:
		print(n1)
		n3=n1+n2
		n1=n2
		n2=n3
		count+=1
