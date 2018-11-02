# Nathan Zhu
# November 1st, 2018
# 
# https://leetcode.com/problems/search-insert-position
#
# Several things of note in binary search.
# 
# 1. IF the element searched for is not found, the LEFT in a binary search
#    will be the position of the element if it is inserted in.
#
#  When finding lower_bound
#
# 2. There is a trick to finding first instance of a number in an array.
#
#  If number is found, we can save this number...
#  Then: right = middle - 1;
#
#  Eventually, this will exit the while loop with smallest element.
# 

def binsearch(arr, x):
    left = 0
    right = len(arr) - 1

    while left <= right:
        m = (left + right) / 2

        if arr[m] == x:
            return m
        if arr[m] > x:
            right = m - 1
        else:
            left = m + 1

    #if nothing is found return -1
    return -1

def binsearchrec_helper(arr, x, low, high):
    if low == high and arr[low] == x:
        return low
    elif low == high:
        return -1

    med = (low + high) / 2
    if arr[med] == x:
        return med

    elif arr[med] > x:
        return binsearchrec_helper(arr, x, low, med - 1)
    else:
        return binsearchrec_helper(arr, x, med + 1, high)

def binsearchrec(arr, x):
    return binsearchrec_helper(arr, x, 0, len(arr) - 1)


if __name__ == "__main__":
    arr1 = [1, 2, 4, 6, 7, 8, 11, 13, 15, 19, 20, 21, 22]
    #should be 0
    print(binsearch(arr1, 1))
    print(binsearchrec(arr1, 1))
    #should b 12
    print(binsearch(arr1, 22))
    print(binsearchrec(arr1, 22))
    #should be 2
    print(binsearch(arr1, 4))
    print(binsearchrec(arr1, 4))
    #should be 10
    print(binsearch(arr1, 20))
    print(binsearchrec(arr1, 20))
    #should be -1
    print(binsearch(arr1, 3))
    print(binsearchrec(arr1, 14))
    print(binsearch(arr1, 14))
    print(binsearchrec(arr1, 3))