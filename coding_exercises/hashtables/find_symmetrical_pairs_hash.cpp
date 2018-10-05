//  Nathan Zhu 5/31/2018 1:58 pm
//  https://www.geeksforgeeks.org/given-an-array-of-pairs-find-all-symmetric-pairs-in-it/
//  The purpose of this program is to find all symmetrical pairs
//  in an array in O(n) time with a hash table
//
//
#include <unordered_map>
#include <iostream>

void find_symmetric_pairs(int arr[][2], int size)
{
    std::unordered_map<int, int> possible_pairs;

    for (int i = 0; i < size; ++i)
    {
        int first = arr[i][0];
        int second = arr[i][1];

        if (possible_pairs.find(second) != possible_pairs.end() && possible_pairs[second] == first)
        {
            std::cout << "Found symmetric pair "
                      << first << " " << second << std::endl;
        }
        else
        {
            possible_pairs[first] = second;
        }
    }
}


// Drive method
int main()
{
    int arr[5][2];
    arr[0][0] = 11;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 5;
    arr[2][1] = 10;
    arr[3][0] = 40;
    arr[3][1] = 30;
    arr[4][0] = 10;
    arr[4][1] = 5;
    find_symmetric_pairs(arr, 5);
}
