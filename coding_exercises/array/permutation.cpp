#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;

    if (nums.size() == 0)
        return res;

    if (nums.size() == 1)
    {
        res.push_back(nums);
        return res;
    }

    permute(res, nums, 0);

    return res;
}

void permute(vector<vector<int>> res, vector<int> &nums, int pos)
{
    if (pos == nums.size())
    {
        res.push_back(nums);
        return;
    }

    for (int i = pos; i < nums.size(); i++)
    {
        swap(nums[pos], nums[i]);

        permute(res, nums, pos + 1);

        swap(nums[pos], nums[i]);
    }

    return;
}

int main()
{
    vector<int> temp {1, 2, 3, 4};
    vector<vector<int>> temp2 = permute(temp);
    return 0;
}