string=input("Enter a string :")
lst=list(string)
temp=lst[0]
length=len(string)
lst[0]=lst[length-1]
lst[length-1]=temp
str=""
print(str.join(lst))
