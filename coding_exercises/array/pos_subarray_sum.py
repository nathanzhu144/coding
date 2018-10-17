#  Nathan Zhu
#  11:55 pm, have chinese exam and 376 exam tomorrow, but I'm doing questions
#
#  Foundry Lofts
#
#  I want to understand the sliding window technique better.  This is a classic
#  question.
# 
#  http://blog.gainlo.co/index.php/2016/06/01/subarray-with-given-sum/

def pos_subarray_sum(arr, sum):
    start_index = 0
    sum_so_far = 0

    for i in range(len(arr)):
        sum_so_far += arr[i]

        if sum_so_far == sum:
            return i - start_index

        if sum_so_far > sum:
            sum_so_far -= arr[start_index]
            start_index += 1


if __name__ == "__main__":
    #should be 3
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 14))
    #should be 4
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 16))
    #should be 2
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 5))
