#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
 * Nathan Zhu
 * Wednesday Oct 24th,  8:31 pm
 * 
 * Foundry lofts, with Renying chen, she is doing 370.  
 * I have a 370 exam soon, but also an interview tomorrow.
 * 
 * Basically, we iterate through a string, and store each individual
 * char in a hash table and link it to the index where it is found.
 * If we find a repeat, we jump to the index after which the first
 * char is found, and update that char for which new index it is found at.
 */
//  AB C -> Z BA
//  ^subseq begin index 0
//
//  First, dictionary looks like
//    A - 0, B - 1, C - 2 ...
//
//  Then, we see a B, after Z, and the start of
//  our longest sequence goes from index 0 to index 2,
//  since we take dict['B'] + 1.
//
//  Then, we go to the next letter and see the letter A
//  When we see A, we should ignore it since our subsequence
//  actually begins after the A, we should ignore it despite
//  the fact it is still in our dictionary. We will still update
//  last found A's index to next index, but we will not move
//  beginning of our subseq before the current beginning.
//
//  AB C -> Z BA
//     ^subseq begin index 2

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> dict;
    int longest_length = 0;
    int length = 0;
    int start = 0;              //Start of 

    for (unsigned int i = 0; i < s.size(); ++i)
    {
        //If repeat char
        if (dict.find(s[i]) != dict.end())
        {
            //Checks to see 
            if (dict[s[i]] + 1 > start)
            {
                start = dict[s[i]] + 1;
            }

            //Updates 
            dict[s[i]] = i;

            //
            if (length > longest_length)
            {
                longest_length = length;
            }

            //
            length = i - start + 1;
        }
        //If char is unique
        else
        {
            //Insert into dict and increment length
            dict[s[i]] = i;
            ++length;
        }
    }

    //Necessary, longest substr can occur ending at last char of string
    if (length > longest_length)
    {
        longest_length = length;
    }

    return longest_length;
}

int main()
{
    cout << lengthOfLongestSubstring("abba");
    cout << lengthOfLongestSubstring(" ");
    cout << lengthOfLongestSubstring("abbasdasdf");

    return 0;
}