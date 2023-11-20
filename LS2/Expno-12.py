lst=[]
n=int(input("enter the limit:"))
for x in range(0,n):
       string=input("enter the string: ")
       lst.append(string)
count=0
for i in lst:
	for j in i:
		if j=="a":
			count+=1
print(count)
