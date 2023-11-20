lst1 = []
lst2 = []
sum1 = 0
sum2 = 0
print("Enter elements of first list (enter exit to stop ):")
count = 1
while(True):
    
    inpt = input("Integer"+str(count)+" : ")
    count+=1
    if inpt =="exit":
        break
    else:
        lst1.append(int(inpt))
        sum1 = sum1+int(inpt)


print("Enter elements of second list (enter exit to stop ):")
count2 = 1
while(True):
    inpt = input("Integer"+str(count2)+" : ")
    count2+=1
    if inpt =="exit":
        break;
    else:
        lst2.append(int(inpt))
        sum2 = sum2+int(inpt)



if count==count2:
    print("List's are of same length")
else:
    print("List's are of different length")

if sum1 == sum2:
    print("Sums are equal") 
else:
    print("sum are different")       

for i in lst1:
    if i in lst2:
        flag = True
	break    
    else:
        flag = False
if flag:
    print("occurs")
else:
    print("Does not occur")    
