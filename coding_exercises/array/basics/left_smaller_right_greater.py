# Nathan Zhu
# Hatcher Library, UM, Oct 7th, 2018
# 3:34 pm after lunch
# https://practice.geeksforgeeks.org/problems/unsorted-array/0
#
# In an unsorted array of size N, find the first element in the array where 
# all the left elements are smaller and the right elements to it are greater
#
# This can be done in O(N) time.
#
# First, we make an array called max_element_left_of_index
# It measures the largest array element so far in the array
#
#                       arr = [3, 4,-1, 2, 5, 9, 0]
# max_element_left_of_index = [3, 4, 4, 4, 5, 9, 9]
#
# Then, we move right to left, storing the current minimum element
#
# If an array index i is smaller than the current minium element from
# right side and is larger than max_element_left_of_index[i], it is true.

def left_smaller_right_larger(arr):
    #checks arr length > 0
    if len(arr) is 0:
        return -1

    max_element_left_of_index = [arr[0]]

    #iterate left to right, finding largest element up to index
    for i in range(1, len(arr)):
        max_element_left_of_index.append(max(arr[i], max_element_left_of_index[i - 1]))

    right_min = arr[-1]

    #iterate right to left, returning at the first element where
    #element is larger than all elements to left and
    #element is smaller than all eleemtns to right
    for i in range(0, len(arr), -1):
        if arr[i] > max_element_left_of_index[i] and arr[i] < right_min:
            return i
        if arr[i] < right_min:
            right_min = arr[i]
    
    return -1

if __name__ == "__main__":
    arr = [5, 1, 4, 3, 6, 8, 10, 7, 9]
    print(left_smaller_right_larger(arr))



