
# Finds equilibrium point of an array in O(n) time and no extra space
# https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
# October 6th, 2018 Nathan Zhu
# Starbucks on State Street, Ann Arbor
def equilibrium(arr):
    leftsum = 0
    rightsum = sum(arr)

    #
    for i in range(len(arr)):
        rightsum -= arr[i]
        if leftsum - rightsum is 0:
            print(i, " ")
        leftsum += arr[i]
    
    return -1

if __name__ == "__main__":
    arr = [-7, 1, 5, 2, -4, 3, 0 ]
    equilibrium(arr)
