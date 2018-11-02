#  Searching for an element in a sorted linked list that has been rotated.
#  1. Find the pivot.
#  2. With binary search
#
#  [8, 15, 16, 19, 21, 1, 2, 3]
#              ^    ^
#
#  if arr[left] > arr[right]
#  pivot is in between arr[left] and arr[right]
#  
#  if arr[left] < arr[mid]
#  pivot is not in between left and mid
#  We search in right part of array: left must be set to mid
#
#  Left is NOT mid + 1, this is because the last element of the increasing subsequence could be pivot.
#  
#  arr[left] >= mid
#  if arr[right] > arr[mid]
#  pivot is not in between right and mid
#  We search in left part array: right = mid - 1
#
#  https://leetcode.com/problems/search-in-rotated-sorted-array/discuss/14435/Clever-idea-making-it-simple

def find_in_rotated_arr(arr, x):
    if not arr: return -1
    
    l = 0
    r = len(arr) - 1

    while(l < r):
        mid = (l + r) / 2

        if arr[mid] > arr[r]:
            l = mid + 1
        
        elif arr[mid] < arr[r]:
            r = mid - 1
        else:
            break

    #l should be the rotated point
    if x < arr[0]:
        return bin_search(arr, x, l, len(arr) - 1)
    else:
        return bin_search(arr, x, 0, l)

def bin_search(arr, x, start, end):
    if not arr: return -1

    left = start
    right = end

    while left <= right:
        middle = (left + right) / 2
        
        if arr[middle] == x:
            return middle
        
        if arr[middle] > x:
            right = middle - 1

        if arr[middle] < x:
            left = middle + 1

    return -1   

if __name__ == "__main__":
    print(find_in_rotated_arr([8, 15, 16, 19, 21, 1, 2, 3], 15))
    print(find_in_rotated_arr([8, 15, 16, 19, 21, 1, 2, 3], 8))
    print(find_in_rotated_arr([8, 15, 16, 19, 21, 1, 2, 3], 1))
    print(find_in_rotated_arr([8, 15, 16, 19, 21, 1, 2, 3], 3))
    print(find_in_rotated_arr([8, 15, 16, 19, 21, 1, 2, 3], 21))
    print(find_in_rotated_arr([4,5,6,7,0,1,2], 0))
