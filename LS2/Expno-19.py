numbers=[]
numbers=(int(x) for x in (input("Enter numbers(separated by commas)")).split(","))

filtered_numbers = [num for num in numbers if num % 2 != 0]

print("List with even numbers removed:", filtered_numbers)
