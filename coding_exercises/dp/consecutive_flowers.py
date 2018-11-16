


def flowerBouquets(p, q, s):
    def helper(p, q, s, i, mem):
        key = i
        if mem.has_key(key):
            return mem[key]
        if i < 1:
            return 0
        # roses
        if i >= 2 and s[i] == 0 and s[i - 1] == 0 and s[i - 2] == 0:
            mem[key] = max(helper(p, q, s, i - 1, mem), helper(p, q, s, i - 3, mem) + p)
            
        # other 
        if i >= 1 and s[i] != s[i - 1]:
            mem[key] = max(helper(p, q, s, i - 2, mem) + q, helper(p, q, s, i - 1, mem))
            
        else: 
            mem[key] = helper(p, q, s, i - 1, mem)
            
        return mem[key]
    
    return helper(p, q, s, len(s) - 1, {})

if __name__ == "__main__":
    flowerBouquets(3, 3, "100011")