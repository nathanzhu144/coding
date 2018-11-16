
def longest_including_mid(arr, l, h):
    m = (l + h) / 2
    total = 0
    left_sum = float("-inf")
    right_sum = float("-inf")

    for i in range(m - 1, l - 1, -1):
        total += arr[i]
        if total > left_sum:
            left_sum = total

    left_sum = total
    total = 0

    for i in range(m + 1, h + 1):
        total += arr[i]
        if total > right_sum:
            right_sum = total

    right_sum = total


    final = max(arr[m] + left_sum + right_sum, arr[m] + left_sum, arr[m] + right_sum, arr[m])
    return final 

def longest_subarray_sum(arr):
    def helper(arr, l, h):
        if l == h: 
            return arr[l]
        mid = (l + h) / 2
        return max(longest_including_mid(arr, l, h),
                   helper(arr, l, mid - 1), helper(arr, mid + 1, h))

    return helper(arr, 0, len(arr) - 1)   


if __name__ == "__main__":
    print(longest_subarray_sum([-12, 2, 3]))
    print(longest_subarray_sum([5, -1, 2, 3]))


