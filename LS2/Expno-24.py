
lst1=(input("Enter the keys(seperate by comma): ").split(","))
lst2=(input("Enter values (separated by comma):" ).split(","))
print(type(lst1))
print(type(lst2))
dict1={lst1:lst2 for lst1,lst2 in zip(lst1,lst2)}
print(dict1) 

#dict1={ 'apple':5,'cherry':8,'banana':2,'date':1}
sort_key_asc=dict(sorted(dict1.items()))
print("Ascending order by keys: ",sort_key_asc)

sort_key_desc=dict(sorted(dict1.items(),reverse=True))
print("Descending order by keys: ",sort_key_desc)

sort_value_asc=dict(sorted(dict1.items(),key=lambda item:item[1]))
print("Ascendng order by values: ",sort_value_asc)

sort_value_desc=dict(sorted(dict1.items(),key=lambda item:item[1], reverse=True))
print("Descending order by values: ",sort_value_desc)
