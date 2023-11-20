def generate_factors(n):
	factors=[]
	i=1
	while i*i<=n:
		if n%i==0:
			factors.append(i)
			factors.append(n//i)
		i+=1
	return factors
n=int(input("Enter a number : "))
factors= generate_factors(n)
factors.sort()
print(factors)
