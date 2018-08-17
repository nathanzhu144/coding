/**
 * Nathan Zhu
 * znathan
 * August 3rd, 2018 who knows what time, lol, in the middle of the air above Arizona or 
 *                  something.  I took a nap, and then am not sure how long it is until
 *                  we get to San Jose.
 * 
 * The purpose of this program is to create a DP solution that finds the longest
 * palindrome that is a subsequence in a string.
 * 
 * 
 * Problem:
 *    Let X[1...N], N > 1 be the string, and then define
 *    L(i, j) as the length of the longest substring from X[i...j].
 * 
 * */

#include <map>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

unordered_map<std::pair<int, int>, int> table;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int L(std::string &string_in, int i, int j)
{
    //the max palindrome of a 0-length string is 0
    if (i == j)
    {
        return 0;
    }
    //Two letters are equal.
    if (string_in[i] == string_in[j])
    {
        //Case where indices are one apart
        //Ex. abcAAms, where i and j are 3, 4 respectively
        if (i + 1 == j)
        {
            return 2;
        }
        //Case where indices are more than one apart.
        else
        {
            //L(i + 1, j - 1) has not been solved yet, so recurse
            if (table.find(std::make_pair(i, j)) == table.end())
            {
                table[std::make_pair(i, j)] = 2 + L(string_in, i + 1, j - 1);
            }
            //L(i + 1, j - 1) has been solved yet, so lookup
            else
            {
                table[std::make_pair(i, j)] = 2 + table[std::make_pair(i + 1, j - 1)];
            }
            return table[std::make_pair(i, j)];
        }
    }
    //Two letters are not equal
    else
    {
        int left;
        int right;
        if (table.find(std::make_pair(i + 1, j)) == table.end())
        {
            left = L(string_in, i + 1, j);
        }
        else
        {
            left = table[std::make_pair(i + 1, j)];
        }
        if (table.find(std::make_pair(i, j - 1)) == table.end())
        {
            left = L(string_in, i, j - 1);
        }
        else
        {
            left = table[std::make_pair(i, j - 1)];
        }
        return max(left, right);
    }
}

int find_longest_palindrome_subsequence(std::string &string_in)
{
    return L(string_in, 0, string_in.length() - 1);
}
int main()
{
    std::cout << find_longest_palindrome_subsequence("ABCBCA");
}
