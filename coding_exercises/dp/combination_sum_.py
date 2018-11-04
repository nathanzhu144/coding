def combinationSum(candidates, target):
    candidates.sort()
    dp = [[[]]] + [[] for i in xrange(target)]
    for i in xrange(1, target + 1):
        for number in candidates:
            if number > i: break
            for L in dp[i - number]:
                if not L or number >= L[-1]: dp[i] += L + [number],
    return dp[target]

if __name__ == "__main__":
    print combinationSum([1, 2, 3], 3)