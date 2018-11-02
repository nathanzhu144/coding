#
#  1. Find the pivot.
#  2.  With binary search
#
#  [8, 15, 16, 19, 21, 1, 2, 3]
#  
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
#  

def find_x_in_

def bin_search(arr, x, start, end):
    left = start
    right = end

    while left <= right:
        middle = (left + right) / 2
        