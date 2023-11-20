string = input("Enter the string : ")

lst = list(string)

first = lst[0]

for i in range(1,len(lst)):
    if lst[i]==first:
        lst[i]="$"

str = " "
str = str.join(lst)
print(str)
