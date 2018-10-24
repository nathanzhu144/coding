#  Nathan Zhu
#  11:31 pm, Tuesday October 23rd
#  At Willow Tree
#  
#  Trying to figure out the water container problem.
#  https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation
#
#  The water container problem is that you have a vector of walls/
#  Rain falls on the walls, and form lakes.  So, which two walls would
#  contain most water between them?
#
#                    
#  | |           |    
#  | |     |     |  
#  | |     |     |   |
#
#  The idea is simple.
# 
#  1. The widest container is a good candidate because it is the widest
#     and the height is the min of the last wall and first wall.
#
#  2. All other containers are less wide and need a higher wall to hold
#     more water.
#
#  3. The smaller of the first and last walls cannot hold more water, so
#     can be removed from consideration.
#
#  https://leetcode.com/problems/container-with-most-water/discuss/6100/Simple-and-clear-proofexplanation

def water(walls):
    i = 0
    j = len(walls) - 1
    max_water = 0

    while i < j:
        max_water = max(max_water, (j - i) * min(walls[i], walls[j]))
        
        if walls[i] < walls[j]:
            i += 1
        else:
            j -= 1

    return max_water

if __name__ == "__main__":
    print(water([1,8,6,2,5,4,8,3,7]));