dict1={}
dict2={}
n1=int(input("Enter the size of first dictionary"))
n2=int(input("Enter the size of second dictionary"))
for i in range(n1):
	key=input("Enter the keys: ")
	value=input("Enter the values: ")
	dict1[key]=value
pirnt(dict1)

for i in range(n2):
	key=input("Enter the keys: ")
	value=input("Enter the values: ")
        dict2[key]=value
print(dict2)

#dict1={'a':1,'b':2,'c':3}
#dict2={'d':4,'e':5,'f':6}
merged_dict={}
for k,v in dict1.items():
	merged_dict[k]=v
for k,v in dict2.items():
 	if k not in merged_dict:
		merged_dict[k]=v
print("dictionary 1:",dict1)
print("dictionary 2:",dict2)
print("merged dictionary:",merged_dict)

