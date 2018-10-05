/**
 *   Nathan Zhu
 *   5/31/2018 
 *   The purpose of this program is to find all the missing elements in a 
 *   number range with a hash table.
 *  
 *   https://www.geeksforgeeks.org/find-missing-elements-of-a-range/s
*/

#include <iostream>
#include <unordered_set>
#include <vector>


std::vector<int> find_missing_in_range(int* arr, int size, int low, int high){
    std::unordered_set<int> not_missing;
    std::vector<int> return_vec;
    for(int i = 0; i < size; ++i){
        not_missing.insert(arr[i]);
    }

    for(int i = low; i <= high; ++i){
        if(not_missing.find(i) == not_missing.end()){
            return_vec.push_back(i);
        }
    }

    return return_vec;
}
int main(){
    int arr[15] = {23, 2, 23, 3, 43, 23, 3, 3, 4, 3, 10, 12, 12, -1, 3};
    std::vector<int> temp = find_missing_in_range(arr, 15, -100, 70);
    for(auto& i: temp){
        std::cout << i << " ";
    }
    return 0;
}