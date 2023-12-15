
from Armstrong import is_armstrong_number

def generate_armstrong_numbers(lower_limit, upper_limit):

    armstrong_numbers = []

    for num in range(lower_limit, upper_limit + 1):
        if is_armstrong_number(num):
            armstrong_numbers.append(num)

    return armstrong_numbers

if __name__ == "__main__":

    lower_limit = int(input("Enter the lower limit: "))
    upper_limit = int(input("Enter the upper limit: "))


    while upper_limit < lower_limit:
        print("Error: Upper limit must be greater than or equal to the lower limit.")
        upper_limit = int(input("Enter the correct upper limit: "))


    result = generate_armstrong_numbers(lower_limit, upper_limit)
    print(f"Armstrong numbers between {lower_limit} and {upper_limit}: {result}")
