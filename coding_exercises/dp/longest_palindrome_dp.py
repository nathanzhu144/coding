class Solution(object):
    
    def lp(self, s, i, j, mem):
        key = (i, j)
        
        if mem.has_key(key):
            return mem[key]
        
        if i is j:
            mem[key] = 1
        
        elif s[i] is s[j]:
            if j - i is 1:
                mem[key] = 2
            
            elif j - i >= 2:
                mem[key] = self.lp(s, i + 1, j - 1, mem) + 2
                
        else:
            mem[key] = 0
            lp(s, i + 1, j, mem), self.lp(s, i, j - 1, mem))
        
        return mem[key]
        
    def longestPalindrome(self, s):
        mem = {}
        self.lp(s, 0, len(s) - 1, mem)
        max_len = -1
        start = -1
        end = -1
        
        for key in mem:
            if mem[key] > max_len:
                max_len = key[1] - key[0]
                start = key[0]
                end = key[1]
                
        return s[start:end]

if __name__ == "__main__":

    soln = Solution()
    print(soln.longestPalindrome( "ABCCBAREA"))
    print(soln.longestPalindrome("AEA"))
    print(soln.longestPalindrome("AREA"))