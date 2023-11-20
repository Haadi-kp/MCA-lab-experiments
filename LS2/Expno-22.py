list=input("Enter a list of words seperated by spaces:").split()
longest_len=0
for word in list:
  if len(word)>longest_len:
    longest_len=len(word)
print("length of the longest word:",longest_len)
