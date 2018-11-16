#  Nathan Zhu
#  Friday Nov 16th, 2018
#  4:20 pm at Dude with Ambi
#
#  This is a leetcode hard problem.
#
#  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute 
#  how much water it is able to trap after raining.
#
#    #       #
#    # #   # #   #
#  # # # # # # # # 
# [1,3,2,1,2,3,1,2]
#
# [1,3,3,3,3,3,3,3]  left_arr
# [3,3,3,3,3,3,2,2]  right_arr
#
#  Rain can fill 5 blocks
#
# 
#  The intuition to solve this problem in O(n) time and O(n)
#  space is simple.
#
#  1. We track the highest so far from the left.   
#  2. We track the highest so far from the right.  
#
#  The amount of water carried at any index i in the array is the 
#  min of highest so far from left and highest so far from right.
#

def trap(height):
    left_arr = []
    right_arr = []
    
    local_max = 0
    for i in height:
        if i > local_max: local_max = i
        left_arr.append(local_max)
        
    local_max = 0
    for i in height[::-1]:
        if i > local_max: local_max = i
        right_arr.insert(0, local_max)
        
    returned = 0
    for i in xrange(0, len(height)):
        returned += min(left_arr[i], right_arr[i]) - height[i]
        
    return returned

if __name__ == "__main__":
    print(trap([1,3,2,1,2,3,1,2]))