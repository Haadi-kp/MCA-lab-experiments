#positive numbers
numbers=[int(x) for x in (input("Enter a list of integers separated by spaces : ").split())]
positive=[num for num in numbers if num>0]
print("positive list of numbers : ",positive) 


#squares

N=int(input("enter the value of N: "))
squares=[num**2 for num in range(1,N+1)]
print("square of numbers : ",squares)


#vowels

word=input("Enter a word :")
vowels=[char for char in word if char.lower() in 'aeiou']
print("Lists of vowels : ",vowels)

#ordinal values

word=input("Enter a word: ")
ordinal_values=[ord(char) for char in word]
print("Ordinal values of each element : ",ordinal_values)
