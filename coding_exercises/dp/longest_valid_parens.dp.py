#  Nathan Zhu
#  7:10 am, Wednesday October 31st.  
#
#  https://leetcode.com/problems/longest-valid-parentheses/discuss/14133/My-DP-O(n)-solution-without-using-stack
#
#  Never thought that I'd wake up at 4:45 am to do a leetcode DP problem on my 20th Halloween
#
#  The idea is simple. This is a DP hard problem.  Prob can be solved much easier with a stack
#
#  Suppose that index n is the longest valid parens ending at index n, with p(i) giving length of longest parens
#  ending at this index
#
#    Case 1: 
#        s[i] = "("
#        p(i) = 0
#         
#        True because a parens sequence cannot end with this character
#
#    Case 2: 
#        s[i] = ")"
#
#          Case 2A  s[i - 1] = "(" 
#
#          p(i) = p(i - 2) + 2
#
#          Ex. ( ( ) ) ( )
#                        ^                  
#              0 0 2 4 0 6
#
#
#          Case 2B s[i - 1] = ")" AND s[i - p(i - 1) - 1] = "("
#               In this case, we have find a new parens surrounding old parens,
#               Note that since we create a greater parens, we have to add old
#               parens that it might touch now.
# 
#          p(i) = p(i - 1) + 2 + p(i - p(i - 1) - 2)
#                                ^ possible new parens it can touch
#                   
# touch this parens*              
#            Ex. ( ( ) ) ( ( ) )
#                          ^
#                0 0 2 4 0 0 2 8
#
#                p(last) = p(last - 1) + 2 + p(last - p(last - 1) - 2)
#                        = 2 + 2 + 4 = 8
#  
#

def longestValidParentheses(s):
    """
    :type s: str
    :rtype: int
    ((()
    """
    if len(s) < 2:
        return 0

    longest = [0 for i in range(len(s))]
    
    if s[0] == '(' and s[1] == ')':
        longest[1] = 2
        
    for i in range(2, len(s)):
        if(s[i] == '('):
            longest[i] = 0
        if(s[i] == ')'):
            if(s[i - 1] == "("):
                longest[i] = longest[i - 2] + 2
            if(i - longest[i - 1] - 1 >= 0 and \
                s[i - 1] == ")" and s[i - longest[i - 1] - 1] == "("):
                longest[i] = longest[i - 1] + 2
                
                if i - longest[i - 1] - 2 >= 0:
                    longest[i] += longest[i - longest[i - 1] - 2]
                
    return max(longest)


if __name__ == "__main__":
    print(longestValidParentheses("()()"))
    print(longestValidParentheses("(()))())("))
    print(longestValidParentheses("()(())"))
    print(longestValidParentheses("(()())"))