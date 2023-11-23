dict1={}
dict2={}
n1=int(input("Enter the size of first dictionary : "))
for i in range(n1):
        key=input("Enter the key"+str(i+1)+" : ")
        value=input("Enter the value"+str(i+1)+" : ")
        dict1[key]=value

n2=int(input("Enter the size of second dictionary : "))
for i in range(n2):
        key=input("Enter the key"+str(i+1)+" : ")
        value=input("Enter the values"+str(i+1)+" : ")
        dict2[key]=value

merged_dict={}
for k,v in dict1.items():
        merged_dict[k]=v
for k,v in dict2.items():
        if k not in merged_dict:
                merged_dict[k]=v
print()
print("dictionary 1:",dict1)
print()
print("dictionary 2:",dict2)
print()
print("merged dictionary:",merged_dict)
