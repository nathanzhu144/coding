/**
 *   Nathan Zhu
 *   6/4/2018 
 *   The purpose of this program is to max distance between two occurrences
 *   of words.
 *  
 *   https://www.geeksforgeeks.org/maximum-distance-two-occurrences-element-array/
*/

#include <vector>
#include <unordered_map>
#include <iostream> 

void find_longest_num_range(std::vector<int> arr){
    //maps each number to its index
    std::unordered_map<int, int> num_to_index;
    int longest_num = arr[0];
    int longest_dist = 0;

    for(int i = 0; i < arr.size(); ++i){
        if(num_to_index.find(arr[i]) != num_to_index.end()){
            if(i - num_to_index[arr[i]] > longest_dist){
                longest_num = arr[i];
                longest_dist = i - num_to_index[arr[i]];
            }
        }else{
            num_to_index[arr[i]] = i;
        }
    }

    std::cout << "Longest distance between " << longest_num << 
              " is " << longest_dist << std::endl;
}

int main(){

   std::vector<int> vec{3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
   find_longest_num_range(vec);

}