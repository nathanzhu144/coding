def longest_increasing_subsequence(arr):
    if not arr:
        return 0

    # mem length arr
    #LiS ending at index 0 is 1
    mem = [1 for index in arr]

    mem[0] = 1

    for i in range(len(arr)):
        for j in range(i):
            if arr[j] < arr[i] and mem[j] + 1 > mem[i]:
                mem[i] = mem[j] + 1

    return max(mem)

        

# longest increasing subsequence
#   -- 2 5 4 3 -3 -2

def longest_subarray_sum(arr):
    def helper(arr, l, h):
        if l == h: return arr[l]
        mid = (l + h) / 2
        return max(longest_including_mid(arr, l, h),
                   helper(arr, l, mid), helper(arr, mid + 1, h)
                               
#  2 3 -4, 2 3
def longest_including_mid(arr, l, h):
    m = (l + h) / 2
    total = 0
    left_sum = float("-inf")
    right_sum = float("-inf")

    for i in arr[l : m: -1]:
        total += arr[i]
        if total > left_sum:
            total = left_sum

    left_sum = total
    total = 0

    for i in arr[m + 1: h + 1]:
        total += arr[i]
        if total > right_sum:
            total = right_sum

    right_sum = total

    return arr[m] + left_sum + right_sum


