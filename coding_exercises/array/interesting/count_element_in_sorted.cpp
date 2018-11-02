
#include <vector>
#include <iostream>

using namespace std;

/*
*   Nathan Zhu
*   Panera Bread 1:45 pm 
*   Sunday Oct 28th, 2018
*
*   https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*
*   The question:
*    Suppose that you have a sorted vector.  We want to ask, what is the first index of a
*                                            given element n?  What is the last index?
*                                            This can be done in log(N) time with binary search.
*  
*   To find first occurrence of an element in a vector, do a regular
*   binary search and when you find the element, you do this:
* 
*   1. Store current index (in case this is first occurr)
*
*   2. Change right to mid - 1, so we can possibly find earlier elements
*
*
*   ... to find last occurence, you modify step 2, change left to mid + 1
*/


int find_first_of(vector<int> &nums, int target)
{
    if (nums.size() == 0)
    {
        return -1;
    }

    int left = 0;
    int right = nums.size() - 1;
    int returned = -1;

    while (left <= right)
    {
        int med = (left + right) / 2;

        if (nums[med] == target)
        {
            //THIS IS ONLY DIFF BETWEEN THIS AND BINARY SEARCH
            returned = med;
            right = med - 1;
        }
        else if (nums[med] < target)
        {
            left = med + 1;
        }
        else
        {
            right = med - 1;
        }
    }

    return returned;
}

int find_last_of(vector<int> &nums, int target)
{
    if (nums.size() == 0)
    {
        return -1;
    }

    int left = 0;
    int right = nums.size() - 1;
    int returned = -1;

    while (left <= right)
    {
        int med = (left + right) / 2;

        if (nums[med] == target)
        {
            //THIS IS ONLY DIFF BETWEEN THIS AND BINARY SEARCH
            returned = med;
            left = med + 1;
        }
        else if (nums[med] < target)
        {
            left = med + 1;
        }
        else
        {
            right = med - 1;
        }
    }

    return returned;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> returned;

    returned.push_back(find_first_of(nums, target));
    returned.push_back(find_last_of(nums, target));

    return returned;
}


int main(){
    vector<int> temp = {1, 2, 2, 2, 4, 4, 6, 8, 8, 8, 10, 12, 15};
    vector<int> first_to_last = searchRange(temp, 8);
    cout << "Eights start at " << first_to_last[0] << " and end at " << first_to_last[1] << endl;

    return 0;
}