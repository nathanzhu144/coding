#  12:50 am 10/7/2018 Foundry Lofts
#  Nathan Zhu
#  https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
#
#  How to change a number list to a zigzag.  Key insight here 
#  is bubblesort

def zigzag(arr):
    for i in range(0, len(arr) - 1):
        if i % 2 is 0:
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
        else:
            if arr[i] < arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]

    print(arr)

if __name__ == "__main__":
    arr = [4, 3, 7, 8, 6, 2, 1]
    zigzag(arr)