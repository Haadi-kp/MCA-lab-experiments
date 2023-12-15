from rectangle import area as rectArea,perimeter as rectPerimeter
from circle import*
from threeDGraphics.cuboid import surfaceArea as cubArea,volume as cubVolume
from threeDGraphics.sphere import surfaceArea as sphArea,volume as sphVolume

length_rect = float(input("Enter the length of the rectangle: "))
width_rect = float(input("Enter the width of the rectangle: "))

radius_circle = float(input("Enter the radius of the circle: "))

length_cuboid = float(input("Enter the length of the cuboid: "))
width_cuboid = float(input("Enter the width of the cuboid: "))
height_cuboid = float(input("Enter the height of the cuboid: "))

radius_sph = float(input("Enter the radius of the sphere: "))

print("\nRectangle Area:", rectArea(length_rect, width_rect))
print("Rectangle Perimeter:", rectPerimeter(length_rect, width_rect))

print("\nCircle Area:", area(radius_circle))
print("Circle Perimeter:", perimeter(radius_circle))

print("\nCuboid Surface Area:", cubArea(length_cuboid, width_cuboid, height_cuboid))
print("Cuboid Volume:", cubVolume(length_cuboid, width_cuboid, height_cuboid))

print("\nSphere surface area : ",sphArea(radius_sph))
print("Sphere volume : ",sphVolume(radius_sph))


