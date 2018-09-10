import os
#import stmplib

def find_file(name, path):
    result = []
    for root, dirs, files in os.walk(path):
        if name in files:
            result.append(os.path.join(root, name))
    return result

def return_password(password_file_name):
    email_pw = "password_not_successful"
    findpw = find_file(password_file_name, "/home")

    if len(findpw) is not 1:
        raise Exception('Multiple password files found')
    else:
        with open(findpw[0], "r") as file:
            email_pw = file.read()

def main():
    email_pw = "password_not_successful"
    findpw = find_file("pw.txt", "/home")
    if len(findpw) is not 1:
        raise Exception('Multiple password files found')
    else:
        with open(findpw[0], "r") as file:
            email_pw = file.read()

    print(email_pw)




   #


if __name__ == '__main__':
    main()