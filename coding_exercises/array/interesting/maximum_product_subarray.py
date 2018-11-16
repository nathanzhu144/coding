#  maximum_product_subarray.py
#  Nathan Zhu Nov 4th, 2018, on Greyhound bus in Chicago IL
#  We just got our greyhound delayed by like 4 hours.  Saw Jung, Abdullah, and Jesse's brother
#
#
#  The key insight here is simple.  We are trying to find the maximum product subarray
#   
#  Let imax and imin be the maximum and minimum products ending at index i.
#
#  At index 0, imax and imin are both arr[0], since the minimum and max products ending at i is that
#
#  Then, if we get a negative number, we swap the two variables because the imax will become imin.
#  This is true because if we multiple the greatest product so far by the next neg number, it CAN 
#  become the smallest negative number.  Likewise, if we multiply the smallest product we have so far
#  by the next neg number, we CAN get the largest product.
# 
#  To get the greatest magnitudes we do max(imax * arr[i], arr[i])
#                          and          min(imin * arr[i], arr[i])
#
#  

def find_max_product_subarray(arr):
    if not arr:
        return 0

    imax = arr[0]
    imin = arr[0]
    returned = arr[0]

    # WE GO FROM 1 -> len, not 0 -> len
    for i in range(1, len(arr)):
        #swap imax and imin if multiplied number < 0
        if arr[i] < 0:
            imax, imin = imin, imax

        #we get maximum value for imax, and minimum for imin for
        #greatest magnitude
        imax = max(imax * arr[i], arr[i])
        imin = min(imin * arr[i], arr[i])

        #maximum is not guaranteed to end at index i, so we 
        #keep track of the biggest maximum ending from 0 -> i
        returned = max(returned, imax)

    return returned

if __name__ == "__main__":
    print(find_max_product_subarray([-3, 4, -7, 1, 0 , 15]))
    print(find_max_product_subarray([0, 2, 0]))

