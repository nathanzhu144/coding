# Nathan Zhu
# Friday Nov 16th, 2018 6:06 pm
# 
# Word break problem.  Have been figuring this out for a month.
# 
# The idea is pretty simple - Can we break up a string into words given a dictionary?
#
# Ex.
# string = pineappledog   dictionary [pin, pine, apple, dog]
# 
# Can we break 
# p [ineappledog]  N - 'p' is not in dict
# pi [neappledog]  N - 'pi' is not in dict
# pin [eappledog]  Maybe - 'pin' is in our dict, we now recurse to see if wordBreak("eappledog", wordDict)
# pine [appledog]  Maybe - 'pine' is in our dict, we now recurse to see if wordBreak("appledog", wordDict)
#
#

def wordBreak(string, wordDict):
    """
    :type s: str
    :type wordDict: List[str]
    :rtype: bool
    """
    def helper(s, wordDict, mem):
        if s in mem:
            return mem[s]
        
        if not s:
            return True
        
        for i in range(0, len(s)):
            if s[0: i + 1] in wordDict:
                mem[s[i + 1:]] = helper(s[i + 1:], wordDict, mem)
                if mem[s[i + 1:]] == True:
                    return True
                
        return False
    
    return helper(string, wordDict, {})
            