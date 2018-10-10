def rev(list_in):
    first = 0
    last = len(list_in) - 1

    while first < last:
        list_in[first], list_in[last] = list_in[last], list_in[first]
        first += 1
        last -= 1

    return list_in

if __name__ == "__main__":
    l1 = [1, -2, 2, 32, 2, 1, 23, 0, 54, 0, -1]
    print(rev(l1))