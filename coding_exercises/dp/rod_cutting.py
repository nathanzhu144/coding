#  Nathan Zhu
#  Oct 14th, 2018
#  Rod cutting problem.
#
# 
#  Note: You can re-use a rod length.  For example, you could sell
#        8x 1-length rods.


def rod_cut(rod_size, lengths, prices, index, memoize):
    key = (rod_size, index)

    if key in memoize:
        return memoize[key]

    # Having no rod == no profit
    # This also means that selling not all of your rod may
    # net a max profit.  To prevent that from happening, I think if
    # rod size < 0, you return neg inf
    if rod_size < 0:
        return float("-inf")
    
    if rod_size is 0:
        return 0

    if index < 0:
        return 0

    memoize[key] = max(rod_cut(rod_size - lengths[index], lengths, prices, index, memoize) 
                       + prices[index],
                       rod_cut(rod_size, lengths, prices, index - 1, memoize))

    return memoize[key]


def rod_cutting(rod_size, lengths, prices):
    memoize = {}
    return rod_cut(rod_size, lengths, prices, len(prices) - 1, memoize)


if __name__ == "__main__":
    lengths = [1, 2, 3, 4,  5,  6,  7,  8]
    prices_1 = [1, 5, 8,  9, 10, 17, 17, 20]
    prices_2 = [3, 5, 8,  9, 10, 17, 17, 20]

    #should be 22
    print(rod_cutting(8, lengths, prices_1))

    #should be 24
    print(rod_cutting(8, lengths, prices_2))
