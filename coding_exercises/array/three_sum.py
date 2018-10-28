#
#
#
#     -3   -2   -2   -1   1   2   3    4 
def threeSum(self, nums):
    nums.sort()
    returned = []
    
    #Iterate n - 2 times because we are finding triplets
    """
    The 
    """
    for i in xrange(len(nums) - 2):
        if i > 0 and nums[i - 1] == nums[i]:
            continue
            
        left = i + 1
        right = len(nums) - 1
            
        while left < right:
            total = nums[i] + nums[left] + nums[right]
                
            if total < 0:
                left += 1
                    
            elif total > 0:
                right -= 1
                    
            else total == 0:
                returned.append([nums[i], nums[left], nums[right]])
                                                                
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                        
                left += 1
                right -= 1
                    
    return returned
