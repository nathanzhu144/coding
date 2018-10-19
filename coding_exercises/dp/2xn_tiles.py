#  Nathan Zhu
#  Sunday Oct 14th, 2018, 1pm at Foundry Lofts
#  Rod cutting problem.
#
# 
#   
#   https://www.geeksforgeeks.org/tiling-problem/
#

def tiling(n, mem):
    if mem.has_key(n):
        return mem[n]

    if n is 2:
        mem[n] = 2
    elif n is 1:
        mem[n] = 1
    else:
        mem[n] = tiling(n - 1, mem) + tiling(n - 2, mem)

    return mem[n]

def tiling_function(n):
    return tiling(n, {})

if __name__ == "__main__":
    print(tiling_function(4))
    print(tiling_function(15))