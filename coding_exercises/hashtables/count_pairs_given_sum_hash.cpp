#include <iostream>
#include <unordered_set>
#include <iterator>
#include <utility>
#include <vector>

std::vector<std::pair<int, int>> find_pairs(std::vector<int> input, int sum){
    std::vector<std::pair<int, int>> return_vec;
    std::unordered_set<int> previous_nums;

    for(std::vector<int>::iterator i = std::begin(input); i != std::end(input); ++i){
        int possible_other_part_of_sum = sum - *i;
        if(previous_nums.find(possible_other_part_of_sum) != previous_nums.end()){
            return_vec.push_back(std::make_pair(*i, possible_other_part_of_sum));
        }
        previous_nums.insert(*i);
    }

    return return_vec;
}
int main(){
    std::vector<int> inputvec{23, 23, 2, 3, 3, 0, 4, 1, 7, 2, 2, 3, 5};

    std::vector<std::pair<int, int> > temp = find_pairs(inputvec, 5);

    for(auto& i: temp){
        std::cout << i.first << " " << i.second << std::endl;
    }

    std::cout <<"Size is " << temp.size();
}