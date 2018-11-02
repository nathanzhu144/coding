#  Nathan Zhu
#  October 2nd, 2018
#
#  Figuring out std::lower_bound at 12:26 am, Foundry Lofts
# 
#  Note that lower_bound is a binary search that returns the first 
#  element >= a value
#
#  So, lower_bound(5)...
#          
#  [1   2   3   3   3   6   7]
#                   ^
#
#  lower_bound(3)
#  [1   2   3   3   3   6   7]
#           ^
#
#  lower_bound(8)
#  [1   2   3   3   3   6   7]
#                           ^ returns size of arr
#
#  lower_bound(0)
#  [1   2   3   3   3   6   7]
#   ^

def lower_bound(arr, x):
    left = 0
    right = len(arr)   # not len(arr) - 1, as lower_bound can return a

    while left < right:
        mid = (left + right) / 2

        if arr[mid] >= x:
            right = mid

        # arr[mid] < x
        # Cannot include mid bc we are trying to find the first element
        # greater than or equal to x in the array
        else:
            left = mid + 1

    #left == right now
    return left

if __name__ == "__main__":
    print(lower_bound([1,   2,   3,  3,  3, 6,   7], 5))
    print(lower_bound([1,   2,   3,  3,  3, 6,   7], 3))
    print(lower_bound([1,   2,   3,  3,  3, 6,   7], 0))
    print(lower_bound([1,   2,   3,  3,  3, 6,   7], 8))