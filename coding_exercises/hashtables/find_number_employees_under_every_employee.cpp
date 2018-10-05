#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iterator>

void find_num_employees(std::vector<std::pair<char, char>> input)
{
    std::unordered_map<char, std::vector<char>> manages;

    for (std::vector<std::pair<char, char>>::iterator i = std::begin(input);
         i != std::end(input); ++i)
    {
        manages[i->second].push_back(i->first);
    }

    std::vector<char, int> final_print;

    for (std::vector<std::pair<char, char>>::iterator i = std::begin(input);
         i != std::end(input); ++i)
    {   
        int num_subordinates = 0;
        //while we can still find a subordinate employee we increment
        while(manages.find(i->first) != manages.end()){
            ++num_subordinates;
            
        }
    }

}
int main()
{

    std::vector<std::pair<char, char>> employee_manager;
    //c manages a, c manages b, etc...
    employee_manager.push_back(std::make_pair('a', 'c'));
    employee_manager.push_back(std::make_pair('b', 'c'));
    employee_manager.push_back(std::make_pair('c', 'f'));
    employee_manager.push_back(std::make_pair('d', 'e'));
    employee_manager.push_back(std::make_pair('e', 'f'));
    employee_manager.push_back(std::make_pair('f', 'f'));

    return 0;
}