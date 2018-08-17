/** 
*  Nathan Zhu znathan
*  2:53 pm in Beijing, China in a KFC.  
*  
*  The problem itself is simple. Given an integer, we have several choices...
*     We can subtract one from it.
*     IF it is divisible by 2, we can divide it by 2.
*     IF it is divisible by 3, we can divide it by 3.
*
*  What is the fewest number of steps it takes to get to one?
*
*  For example, for 10, we can subtract one, and then divide by 3 twice
*  getting to one in three steps.  
*
*/

#include <vector>
#include <iostream>
using namespace std;

//////////////////////////////////////
//        Bottom up approach        //
//////////////////////////////////////

int min_step_to_one_bottom_up(int num_in){
    std::vector<int> vec;   //vector that holds values for bottom-up approach

    /*establishing base cases*/

    vec.push_back(-100); // n/a steps from 0
    vec.push_back(0);    //0 step from 1, 
    vec.push_back(1);    //1 step from 2, divide by 2
    vec.push_back(1);    //1 step from 3, divide by 3

    for(int i = 4; i <= num_in; ++i){
        vec.push_back(-100);
        vec[i] = 1 + vec[i - 1];

        //If num is divisible by 2, see if the number of ways resulting from dividing by 2 is less
        if((i % 2 == 0) && vec[i] > (1 + vec[i / 2])){
            vec[i] = 1 + vec[i / 2];
        }

        //If num is divisible by 3, see if the number of ways resulting from dividing by 3 is less
        if((i % 3 == 0) && vec[i] > (1 + vec[i / 3])){
            vec[i] = 1 + vec[i / 3];
        }
    }

    return vec[num_in];
}


  
//////////////////////////////////////
//         Top down approach        //
//////////////////////////////////////

//With recursive calls, use memoization table to see that if a call 
//has been done, then return

int main(){
    std::cout << "Minimum step for 10 is " << min_step_to_one_bottom_up(10) << std::endl;
    std::cout << "Minimum step for 7 is " << min_step_to_one_bottom_up(7) << std::endl;   
    std::cout << "Minimum step for 12323 is " << min_step_to_one_bottom_up(12323) << std::endl;

    return 0;
}