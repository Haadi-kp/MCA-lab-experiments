square = lambda x : x**2
rectangle = lambda x,y : x*y
triangle = lambda x,y : (1/2)*x*y

sqrLen = int(input("Enter the length of square : "))
print("The area of square : ",square(sqrLen))

rectLen = int(input("Enter the length of rectangle : "))
rectWidth = int(input("Enter the width of rectangle : "))
print("The area of rectangle : ",rectangle(rectLen,rectWidth))

triaHeight = int(input("Enter the height of triangle : "))
triaBreadth = int(input("Enter the breadth of triangle : "))
print("The area of triangle : ",triangle(triaHeight,triaBreadth))


