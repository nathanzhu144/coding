# Saturday October 6th, 2018 
# Nathan Zhu
# Hatcher Library
#
#  https://www.youtube.com/watch?v=nqlNzOcnCfs
#
#  How many sets of number in a list add up to a certain number?
#
#  Ex. [1, 2, 3] to make 4, is only one, (1, 3)
#  
#  Coin change:
#  To use a number twice, as in a coin change problem where we can use a 
#  denomination twice, we only need a slight tweak
#
#  Notes:
# 
#  Note that there cannot be repeats - as in 
#  Given a set [1, 2, 3], there are only two ways of making
#  it, specifically 


def dp(arr, total, i, memoization):
    key = (total, i)
    if key in memoization:
        return memoization[key]
    # There is 1 way to make 0
    elif total is 0:
        return 1
    # 0 ways to make neg sum
    elif total < 0:
        return 0
    # if we run out of objects to make sum with.
    # Impossible to make 8 with a set of {2, 3} for example
    elif i < 0:
        return 0
    #cannot include this object, arr[i] if subtracting leads to < 0
    elif total - arr[i] < 0:
        sum = dp(arr, total, i - 1, memoization)
    else:
        sum = dp(arr, total, i - 1, memoization) + dp(arr, total - arr[i], i - 1, memoization)
        ## Note: changing to this would be same problem as coin problem where you can use
        ##       same denomination twice
        #sum = dp(arr, total, i - 1, memoization) + dp(arr, total - arr[i], i, memoization)

    memoization[key] = sum
    return sum


def find_sets_of_num_add_up_to(arr, total):
    memoization = {}
    return dp(arr, total, len(arr) - 1, memoization)

if __name__ == "__main__":
    arr = [2, 23, 2, 20, 1, 5, 9, 13, 4]
    print find_sets_of_num_add_up_to(arr, 1)
    print find_sets_of_num_add_up_to(arr, 3)
    print find_sets_of_num_add_up_to(arr, 13)
    coin_arr = [1, 2, 3]
    print find_sets_of_num_add_up_to(coin_arr, 4)
    n10_Arr = [2, 5, 3, 6]
    print find_sets_of_num_add_up_to(n10_Arr, 10)