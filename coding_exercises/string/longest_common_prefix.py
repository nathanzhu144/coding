#  Nathan Zhu
#  October 28th, 2018 9:54 am
#  Foundry lofts 2nd floor
#  Longest common prefix (easy)
#
#  Give a list of strings, find the longest common prefix.
# 
#  https://leetcode.com/problems/longest-common-prefix
#

def longestCommonPrefix(strs):
        """
        We find the shortest string.  Then, we enumerate through
        other strings and returns false upon first char not equal.
        If all are equal, we return shortest string.

        This is easy, but coded in python.
        """
        if not strs:
            return ""
        
        # Used 2nd argument in min
        shortest = min(strs, key=len)
        
        for i, char in enumerate(shortest):
            for others in strs:
                if others[i] != char:
                    return shortest[:i]
        
        return shortest