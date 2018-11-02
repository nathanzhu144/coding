#  Nathan Zhu
#  11:55 pm, have chinese exam and 376 exam tomorrow, but I'm doing questions
#
#  Foundry Lofts
#
#  I want to understand the sliding window technique better.  This is a classic
#  question.
#
#  The question is: Given an array and a sum, what is the length of a substring of the
#                   array that adds up to the sum
# 
#  http://blog.gainlo.co/index.php/2016/06/01/subarray-with-given-sum/
#  http://blog.gainlo.co/index.php/2017/03/03/chapter-3-practice-coding-questions-complete-guide-google-interview-preparation/
#  http://blog.gainlo.co/index.php/2016/04/08/if-a-string-contains-an-anagram-of-another-string/
#  https://www.geeksforgeeks.org/find-subarray-with-given-sum/

def pos_subarray_sum(arr, sum):
    start_index = 0
    sum_so_far = arr[0]

    # array has to iterate one past, 
    # in edge cases where sum can only be made
    # with something inclusive of last item in arr
    for i in range(1, len(arr) + 1):

        while sum_so_far > sum:
            sum_so_far -= arr[start_index]
            start_index += 1

        if sum_so_far == sum:
            return i - start_index

        #only increment if in bounds
        if i < len(arr):
            sum_so_far += arr[i]

        


if __name__ == "__main__":
    #should be 4
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 14))
    #should be 4
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 16))
    #should be 2
    print(pos_subarray_sum([1, 2, 4, 7, 3, 13, 12, 1, 2, 3], 5))
    #should be 2
    print(pos_subarray_sum([17, 2, 4, 7, 3, 13, 12, 1, 2, 3], 10))
    #should be 1
    print(pos_subarray_sum([17, 2, 4, 7, 19, 13, 12, 1, 6, 3], 3))
    #should be 1
    print(pos_subarray_sum([6, 3], 3))

