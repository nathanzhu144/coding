/*
*/
#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store;
        
        for(unsigned int i = 0; i < nums.size(); ++i){
            store.insert(std::make_pair(nums[i], i));
        }
        
        for(unsigned int j = 0; j < nums.size(); ++j){
            if(store.find(target - nums[j]) != store.end()){
                vector<int> a;
                a.push_back(store.find(target - nums[j])->second);
                a.push_back(j);
                return a;
            }
        }
}

int main(){
    vector<int> a = {3, 2, 4};
    vector<int> b = twoSum(a, 6);

    std::cout << "Indices " << b[0] << " " << b[1] << std::endl;
}