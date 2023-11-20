def isalldigits_even(number):
        return all(int(digit)%2==0 for digit in str(number))
def gen_sq_num(start,end):
        sq_nums=[]
        curr_num=int((start **0.5//2)*2)
        while curr_num**2<=end:
                candidate=curr_num**2
                if len(str(candidate))==4 and isalldigits_even(candidate):
                        sq_nums.append(candidate)
                curr_num+=2
        return sq_nums
start_range=int(input("Enter the starting range:"))
end_range=int(input("enter the end range:"))
result=gen_sq_num(start_range,end_range)
print(result)
