#  Nathan Zhu
#  Friday Nov 16th, 2018 10:42 am
#
#  How to generate the power set of a set, NO DUPLICATES?
#  
#  [1, 2] -> [[], [1], [2], [1, 2]]

def gen_subsets(arr):
    def helper(arr, i, temp, returned):
        if i >= len(arr):
            returned.append(temp)
            return

        helper(arr, i + 1, temp + [arr[i]], returned)
        helper(arr, i + 1, temp, returned)

    returned = []
    helper(arr, 0, [], returned)

    return returned

print gen_subsets([1, 2, 3, 4])