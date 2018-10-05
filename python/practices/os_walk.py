import os
#import stmplib


# Requires: 
# Modifies:
# Effects:
def find_file(name, path):
    result = []
    for root, dirs, files in os.walk(path):
        if name in files:
            result.append(os.path.join(root, name))
    return result

# Requires: 
# Modifies:
# Effects:
def return_password(password_file_name):
    email_pw = "password_not_successful"
    findpw = find_file(password_file_name, "/home")

    #If multiple passwords are found, throw exception
    if len(findpw) != 1:
        raise Exception('Multiple password files found')
    else:
        with open(findpw[0], "r") as file:
            email_pw = file.read()

    return email_pw

def main():
    email_password = return_password("pw.txt")
    print(email_password)







if __name__ == '__main__':
    main()