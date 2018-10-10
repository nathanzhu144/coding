def add_bin_string(str_1, str_2):
    i = len(str_1) - 1
    j = len(str_2) - 1
    final_bit_sum = []

    #this is how many digits we are carrying
    carry = 0

    while i >= 0 or j >= 0:
        str1_digit = "0"
        str2_digit = "0"

        # If i is not part of str_1
        # 
        if i < 0:
            str2_digit = str_2[j]
            j -= 1
        elif j < 0:
            str1_digit = str_1[i]
            i -= 1
        else:
            str1_digit = str_1[i]
            str2_digit = str_2[j]
            i -= 1
            j -= 1
        
        total = int(str1_digit) + int(str2_digit) + carry

        if total >= 1:
            final_bit_sum.append(total % 2)
            carry = total - 1
        else:
            final_bit_sum.append(0)
            carry = 0

    while carry is not 0:
        final_bit_sum.append(carry % 2)
        carry -= 1

    return final_bit_sum[::-1]


if __name__ == "__main__":
    print(add_bin_string("1111", "1000"))
    print(add_bin_string("1111", "11111"))
    print(add_bin_string("10110", "1010110"))