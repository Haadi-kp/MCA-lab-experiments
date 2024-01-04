file = open("File.txt","r")
lines=[]
for line in file:
        lines.append(line)
print(lines)
file.close()
