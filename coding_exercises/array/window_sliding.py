#  https://www.geeksforgeeks.org/window-sliding-technique/
#  Nathan Zhu
#  9:20 pm Saturday October 6th, 2018
#  
#

def find_max_sum_of_subarray(arr, window):
    window_sum = sum(arr[0:window])

    max = window_sum

    for i in range(1, len(arr) - window):
        window_sum -= arr[i - 1]
        window_sum += arr[i + window]
        if window_sum > max:
            max = window_sum

    return max


if __name__ == "__main__":
    arr = [5 , 2 , -1 , 0 , 3] 
    print(find_max_sum_of_subarray(arr, 3))
    arr2 = [1, 4, 2, 10, 2, 3, 1, 0, 20]
    print(find_max_sum_of_subarray(arr2, 4))
