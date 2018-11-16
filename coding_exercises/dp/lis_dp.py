#  longest_increasing_subsequence.py
#  Nathan Zhu
#  Friday Nov 9th, 2018
#
#  Longest increasing subseq is the longest sequence in an array
#  that is increasing.  However, the numbers in longest increasing
#  may not be 
# 
# 
def longest_increasing_subsequence(arr):
    if not arr:
        return 0

    # mem length arr
    #LiS ending at index 0 is 1
    mem = [1 for index in arr]

    for i in range(len(arr)):
        for j in range(i):
            if arr[j] < arr[i] and mem[j] + 1 > mem[i]:
                mem[i] = mem[j] + 1

    return max(mem)

if __name__ == "__main__":
    print(longest_increasing_subsequence([5, 3, 4, -1, 5, -2, 8]))
    print(longest_increasing_subsequence([5, -2, 4, -1, -1, -2, 8]))
    print(longest_increasing_subsequence([5, 3, 4, -1, 5, -2, 8, 9, -4, 6, 10]))

