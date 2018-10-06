#  Nathan Zhu 
#  October 6th, 2018
#  State Street Starbucks, Ann Arbor, MI
#
#  The purpose of this program is to find the maximum increasing subsequence sum in an array
#
#  https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0
#  https://www.youtube.com/watch?v=99ssGWhLPUE
# 
def max_sum_increasing_subsequence(arr):
    mem = arr[:]

    for i in range(1, len(arr)):
        for j in range(0, i):
            if arr[j] < arr[i] and mem[j] + arr[i] > mem[i]:
                mem[i] = mem[j] + arr[i]
    
    return max(mem)

if __name__ == "__main__":
    arr = [4, 6, 1, 3, 8, 4, 6]
    print(max_sum_increasing_subsequence(arr))