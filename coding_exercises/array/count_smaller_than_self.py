# https://leetcode.com/problems/count-of-smaller-numbers-af
#  
#  Nathan Zhu
#  Friday Nov 2nd, 2018
#  This is a leetcode hard problem.  
# 
#  The problem statement is as follows:
# 
#  Given an integer array, like 
#  [2, 3, 15, -1, 2]
# 
#  Return an array, with each element in that array representing
#  the number of elements that come after it with a smaller value.
#
#  We can just use two for loops with n^2 time.  Here's a cooler way.
#
#  
#  1. We start from the back. 
# 
#  2. We create a new list to store elements from back.
#
#  3. This list is kept sorted, and when we take a new element out
#     by doing a binary search, we can find the number of elements 
#     farther back that are smaller than it.
#
#  We can go from n^2 to nlogn time
def count_numbers_after_self(arr):
    sorted_arr = []
    returned = [0 for i in arr]

    index = len(arr) - 1
    for i in arr[::-1]:
        returned[index] = binary_search_insert(sorted_arr, i)
        index -= 1

    return returned


#  insert x in sorted arr, and return where it should be
#  Modified lower_bound with insertion
def binary_search_insert(sorted_arr, x):
    left = 0
    right = len(sorted_arr)

    while left < right:
        middle = (left + right) / 2

        if sorted_arr[middle] >= x:
            right = middle
        
        else:
            left = middle + 1

    #inserting item into lower_bound, in sorted position
    sorted_arr.insert(left, x)

    #left is always the number of elements less than x
    return left if sorted_arr[left] == x else left
            

if __name__ == "__main__":
    l1 = count_numbers_after_self([12, 2, 3, 11, -1, 12, 11, 11, -1])
    print(l1)