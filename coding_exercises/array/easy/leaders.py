

def find_leaders(arr):
    leader_list = [arr[-1]]
    max = arr[-1]

    for i in xrange(len(arr) - 1, 0, -1):
        if arr[i] > max:
            max = arr[i]
            leader_list.append(arr[i])

    return leader_list

if __name__ == "__main__":
    arr = [16,17,4,3, 5, 2]
    print(find_leaders(arr))