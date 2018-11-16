#  Nathan Zhu
#  October 24th, 2018
#  Generating all pairs of valid parenthesis.  
# 
#  Easier than it seems with recursive backtracking.
#
#  Basically we check if right < left, for right parens at every stack frame
# 

def parens_helper(all_perms, string, left, right, n):
    if len(string) == 2 * n:
        all_perms.append(string)

    if left < n:
        parens_helper(all_perms, string + "(", left + 1, right, n)

    if right < left:
        parens_helper(all_perms, string +  ")", left, right + 1, n)

    return all_perms

def genparens(n):
    return parens_helper([], "", 0, 0, n)


if __name__ == "__main__":
    perms = genparens(13)
    for i in perms:
        print(i)