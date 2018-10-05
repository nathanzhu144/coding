// C++ program to check if given array
// has 2 elements whose sum is equal
// to the given value
//  
//  Nathan Zhu 5/31/2018 1:08 pm
//  https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
#include <unordered_set>
#include <iterator>
#include <iostream>
#include <vector>
 
void print_pairs(std::vector<int> arr, int desired_sum){
    std::unordered_set<int> s;

    for(auto it = std::begin(arr); it != std::end(arr); ++it){
        int find_num = desired_sum - *it;
        if(find_num >= 0 && s.find(find_num) != s.end()){
            std::cout << "Pair: " << find_num << " " << desired_sum - find_num << std::endl;
        }
        s.insert(*it);
    }

}
 
/* Driver program to test above function */
int main()
{
    std::vector<int> A{1, 4, 45, 6, 10, 8, 7, 9};
    int n = 16;
 
    // Function calling
    print_pairs(A, n);
 
    return 0;
}