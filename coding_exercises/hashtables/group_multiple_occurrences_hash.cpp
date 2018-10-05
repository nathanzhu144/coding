/**
 * Nathan Zhu 5/31/2018 3:07 pm Nathan Fenner's Lab
 *  
 * https://www.geeksforgeeks.org/group-multiple-occurrence-of-array-elements-ordered-by-first-occurrence/
 * 
 * The purpose of this program is to use a hash table to
 * efficiently group all elements in an array by an order
 * defined by the first occurrence of the element.
*/

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> group_by_first_occurrence(int *arr, int size)
{
    std::unordered_map<int, int> num_count;
    for (int i = 0; i < size; ++i)
    {
        if (num_count.find(arr[i]) == num_count.end())
        {
            num_count[arr[i]] = 1;
        }
        else
        {
            ++num_count[arr[i]];
        }
    }

    std::vector<int> return_vector;
    for (int i = 0; i < size; ++i)
    {
        if (num_count.find(arr[i]) != num_count.end())
        {
            for (int j = 0; j < num_count.find(arr[i])->second; ++j)
            {
                return_vector.push_back(arr[i]);
            }
            num_count.erase(num_count.find(arr[i]));
        }
    }

    return return_vector;
}

int main()
{

    int arr[15] = {23, 2, 23, 3, 43, 23, 3, 3, 4, 3, 10, 12, 12, -1, 3};
    std::vector<int> grouped_vector = group_by_first_occurrence(arr, 15);
    for(auto& i: grouped_vector){
        std::cout << i << " ";
    }
    return 0;
}