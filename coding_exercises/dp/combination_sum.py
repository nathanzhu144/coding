def combinationSum(candidates, target):
    def helper(candidates, i, set_so_far, target, mem, returned):
        if target == 0:
            returned.append(set_so_far)
            return

        if i < 0:
            return

        if target < 0:
            return

        else:
            helper(candidates, i - 1, set_so_far +
                    [candidates[i]], target - candidates[i], mem, returned)
            helper(candidates, i - 1, set_so_far,
                    target, mem, returned)
            return
    returned = []
    helper(candidates, len(candidates) - 1, [], target, {}, returned)
    return returned


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
    print(combinationSum([2, 3, 6, 7], 7))
    print flowerBouquets(2, 3, "000100")
