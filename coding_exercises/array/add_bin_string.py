def add_bin_string(str_1, str_2):
    i = len(str_1) - 1
    j = len(str_2) - 1

    #this is how many digits we are carrying
    carry = 0

    #we do not carry both i and j
    while i is not 0 and j is not 0:
        str1_digit = 0
        str2_digit = 0

        if i is 0:
            str2_digit = str_1[j]
        elif j is 0:
            str1_digit = str_1[i]
        
        


