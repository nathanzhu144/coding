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
#
#  Base off of this...
#
#  Nathan Zhu
#  znathan
#  August 3rd, 2018 who knows what time, lol, in the middle of the air above Arizona or 
#                  something.  I took a nap, and then am not sure how long it is until
#                  we get to San Jose.
# 
#  The purpose of this program is to create a DP solution that finds the longest
#  palindrome that is a subsequence in a string.
# 
# 
#  Problem:
#     Let X[1...N], N > 1 be the string, and then define
#     L(i, j) as the length of the longest substring from X[i...j].
# 

def lps(string, i, j, mem):
    key = (i, j)

    if mem.has_key(key):
        return mem[key]

    # Case 1: Two characters at start and end of the sequence
    #         string[i] ... string[j] have the same char
    if string[i] is string[j]:
        # Case 1A: Palindrome of length 1
        # Why not i is j?
        if i == j:
            mem[key] = 1
            return 1
        # Case 1B: Two char, Ex. "BB", "$$"
        elif j - i is 1:
            mem[key] = 2
            return 2
        # Case 1C: More than one apart, Ex. A[BCB]A
        elif j - i > 1:
            mem[key] = 2 + lps(string, i + 1, j - 1, mem)
    # Case 2: Two characters at start and end of the sequence
    #         string[i] ... string[j] have diff characters
    else:
        # Case 2B: More than length 1
        mem[key] = max(lps(string, i, j - 1, mem), lps(string, i + 1, j, mem))
    
    return mem[key]

def longest_sub_palindrome(string):
    mem = dict()
    return lps(string, 0, len(string) - 1, mem)

if __name__ == "__main__":
    print(longest_sub_palindrome("ABCDEEAB"))
    print(longest_sub_palindrome("bbbab"))
    print(longest_sub_palindrome("GEEKSFORGEEKS"))
    print(longest_sub_palindrome("BBABCBCAB"))
    print(longest_sub_palindrome("BBBANNANNABANNNANANASDASDFASDOREROCKDOGFCOGOGGGGGGASSAEOOEOABCBCAB"))
    print(longest_sub_palindrome("euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew"))