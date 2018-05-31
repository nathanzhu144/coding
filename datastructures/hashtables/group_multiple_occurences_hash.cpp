#include <iostream>
#include <unordered_map>
#include <vector>


std::vector<int> group_by_first_occurrence(int* arr, int size){
    std::unordered_map<int, int> num_count;
    for(int i = 0; i < size; ++i){
        if(num_count.find(arr[i]) == num_count.end()){
           num_count[arr[i]] = 1;
        }else{
            ++num_count[arr[i]];
        }
    }

    std::vector<int> return_vector;
    for(int i = 0; i < size; ++i){
        if(num_count.find(arr[i]) != num_count.end()){
            for(int i = 0; i < num_count.find(arr[i]) -> first; ++i){
                return_vector.push_back(arr[i]);
            num_count.erase(arr[i]);
            }
        }
    
    }

    return return_vector;
}

int main(){

    int arr[15] = {23, 2, 23, 3, 43, 23,3, 3, 4,3, 10, 12, 12, -1};
    std::vector<int> grouped_vector = group_by_first_occurrence(arr, 15);
    return 0;
}