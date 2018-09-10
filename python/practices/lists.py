#Creates a list for python.
my_list = [1, 2, 3]

#Lists can be printed natively
print(my_list)

#Creates a list again
my_list = list('321')

print(my_list)

#Prints 3rd position of the list
print(my_list[2])

#Prints entire list
print(my_list[:])

#Prints section of list
print(my_list[0:2])

#Reverses list back to 1 2 3
my_list.reverse()
print(my_list)

#Create a reverse iterator
for item in reversed(my_list):
    print(item, end='')

print()

my_list = my_list + ['4', '5']

#Replaces everything up to, but not including, index 2, 
#and replaces with "Dog", "Cat", "Rat"
# ['1', '2', '3', '4', '5'] -> ["Dog", "Cat", "Rat", '3', '4', '5']
my_list[:2] = ["Dog", "Cat", "Rat"]
print(my_list)

#Replaces everything from index 2 to the end, including inex 2
#and replaces with "Dog", "Cat", "Rat"
# ['1', '2', '3', '4', '5'] -> ['1', '2', 'Dog', 'Cat', 'Rat']
my_list = ['1', '2', '3', '4', '5']
my_list[2:] = ["Dog", "Cat", "Rat"]
print(my_list)

