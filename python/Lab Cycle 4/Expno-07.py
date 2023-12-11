display_powers_of_2 = lambda n:list(map(lambda x: 2**x, range(1,n+1)))
num_of_powers =int(input("Enter the number of powers needed:"))
result = display_powers_of_2(num_of_powers)
print(f"Powers of 2 are:",result)
