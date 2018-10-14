#
#  Longest palindrome subsequence
#  
#  Note that i <= j at all times, and i and j represent
#  indices within the string.  Specifically represents longest
#  palindrome substring between two indices i and j
#
#  string is string passed in every time
#
#
#  mem is a memoization table

def lps(string, i, j, mem):
    key = (i, j)


    # Case 1: Two characters at start and end of the sequence
    #         string[i] ... string[j] have the same char
    if string[i] is string[j]:
        # Case 1A: Palindrome of length 1
        if i is j:
            mem[key] = 1
            return 1
        # Case 1B: Two char, Ex. "BB", "$$"
        elif j - i is 1:
            mem[key] = 2
            return 2
        # Case 1C: More than one apart, Ex. A[BCB]A
        elif j - i >= 1:
            # Can find in hash table
            if mem.has_key((i + 1, j - 1)):
                mem[key] = 2 + mem[(i + 1, j - 1)]
                return mem[key]
            # Cannot find in hash table
            else:
                mem[key] = 2 + lps(string, i + 1, j - 1, mem)
                return mem[key]
    # Case 2: Two characters at start and end of the sequence
    #         string[i] ... string[j] have diff characters
    else:
        # Case 2A: Length 1
        if i is j:
            mem[key] = 0
            return 0

        # Case 2B: More than length 1
        leftMin1 = 0
        rightMin1 = 0
        if mem.has_key((i, j - 1)):
            leftMin1 = mem[(i, j - 1)]
        else:
            leftMin1 = lps(string, i, j - 1, mem)
        if mem.has_key((i + 1, j)):
            rightMin1 = mem[(i + 1, j)]
        else:
            rightMin1 = lps(string, i + 1, j, mem)

        mem[key] = max(leftMin1, rightMin1)
        return mem[key]

def longest_sub_palindrome(string):
    mem = dict()
    return lps(string, 0, len(string) - 1, mem)

if __name__ == "__main__":
    print(longest_sub_palindrome("ABCDEEAB"))
    print(longest_sub_palindrome("GEEKSFORGEEKS"))
    print(longest_sub_palindrome("BBABCBCAB"))
    print(longest_sub_palindrome("BBBANNANNABANNNANANASDASDFASDOREROCKDOGFCOGOGGGGGGASSAEOOEOABCBCAB"))