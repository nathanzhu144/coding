def palindrome(arr):
    i = 0
    j = len(arr) - 1

    while i < j:
        if arr[i] is not arr[j]:
            return False
        i += 1
        j -= 1
    
    return True


if __name__ == "__main__":
    string = "abcba"
    not_palin = "abcdedba"

    print palindrome(string)
    print palindrome(not_palin)