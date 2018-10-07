#  Nathan Zhu
#  South U Starbucks 
#  10/8/2018
#
#  https://www.geeksforgeeks.org/split-array-two-equal-sum-subarrays/

def equal_sum_subarray(arr):
    rightsum = sum(arr)
    leftsum = 0

    for i in range (0, len(arr)):
        if leftsum is rightsum:
            return i
        rightsum -= arr[i]
        leftsum += arr[i]
    return -1

if __name__ == "__main__":
    arr = [1 , 2 , 3 , 4 , 5 , 5]
    arr2 = [4, 1, 2, 3 ]

    print(equal_sum_subarray(arr))
    print(equal_sum_subarray(arr2))