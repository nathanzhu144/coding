#Learning hello world. No iostream.

def print_word_menu()
    print('Option 1: List my name letters from which index to which index?')
    print('Option 2: Replace some characters with other characters.')
    print('Option 3: ')


my_name = 'Nathan'

print('Hello world!\n')
print('My name is', my_name, 'Nathan, and I like to eat apples.')
print('I also love proofs by induction!')

person_name = input('Hi, what\'s your name?\n')


if person_name == "":
    print('I\'m sorry that your name so boring\n')
elif (person_name.lower())[0] <= 'f':
    print('I like that name.  In the future, I will use that name.')
    my_name = person_name
    print('Nice to meet you',person_name,'!\n\n')
    print('I like that name.')
    print('My name is', person_name, ', and I like to eat apples.')
    print('Thanks for your name!')
elif len(person_name) <= 5:
    print ('Bro did you know your name is only ' + str(len(person_name)) + ' characters long?')
    print('Cool story bro!\n')
    
    
print()
print('Do you want me to tell you a bit more about your name?')
tell_me_name = input('type in yes or no')
if tell_me_name == "yes":
keep_telling_me_stuff_about_name = "yes"
while keep_telling_me_stuff_about_name == "yes":
    print()

//

    
