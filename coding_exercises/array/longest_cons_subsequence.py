#  Nathan Zhu
#  Friday November 2nd, 2018
#  Chicago, Illinois 9:15 pm in a hotel. 
#
#  Feel kind of sleepy.
#
#  The question is, given an array, find the longest consecutive subsequence.  This can be done
#  in O(n) time.
#
#  Ex. [1, 3, 2, 12, 0]  ->  has a longest cons subseq of 4
#
#  Insight: 
#
#  1. First we insert everything into a hash table (O(n))
#
#  2. Then, we go thru the numbers again.  If x is the start of a streak (x - 1) will not exist in nums
#     we can keep iterating up until the next number (y)
# 
#  Since we iterate through every streak once, we go through N elements at most.  
#  We save the length of the longest streak

def longest_cons_subsequence(arr):
    nums = set(arr)
    best = 0

    for x in nums:
        if x - 1 not in nums:
            y = x + 1
            while y in nums:
                y += 1

            best = max(y - x, best)

    return best


if __name__ == "__main__":
    print(longest_cons_subsequence([36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42]))