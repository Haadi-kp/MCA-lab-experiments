total = 0
list1= input("Enter the elements of list (comma separated):").split(',')
list1= [int (ele) for ele in list1]
for ele in range(0,len(list1)):
	total=total+list1[ele]
print("sum of all elements in given list: ",total)
