/**
 * Nathan Zhu August 2nd, 2018 2:46 am at KFC in Beijing, China.
 * 
 * Finding the longest common subsequence.
 * 
 * A subsequence is as defined. A subsequence is a sequence that appears in the same relative order,
 * but not necessarily contiguous. For example, in the string abcdefg, "abc", "abg", "bdf", "aeg" 
 * are all subsequences. 
 * 
 * Given two sequence of items, find the longest subsequence present in both of them.  
 * 
 * The insight here for the DP approach here is very simple.  Given two strings, 
 * if they have the same last character, that character must be part of the substring.
 * 
 * On the other hand, if the two substrings have different last characters,
 * at least one of the two last characters is not in the least common subsequence.  
 * Possibly both are not.
 * 
 * 
 * /////////////////////////////////////////////////
 * //           Implementation details            //
 * /////////////////////////////////////////////////
 * 
 * Let c[i, j] denote the length of the longest common subsequence for every 
 * of Xi and Yj. Eventually, we are interested in finding the longest
 * common subsequence of M and N, since this is the LCS of the two entire
 * strings.  The idea is the compute c[i, j] assuming that we already know 
 * the values of c[i', j'], for i' <= i and j' <= j. 
 * 
 * We can begin with obeservations...
 * 
 * Base cases:
 *  c[i, 0] = c[0, j] = 0.  If either string is empty, longest common
 *  subsequence must be empty.
 * 
 * DP steps:
 *  1. If last characters of substrings do not match, 
 *     c[i, j] = max(c[i - 1, j], c[i, j - 1])
 *  2. If last characters of substrings do match,
 *     c[i, j] = 1 + c[i - 1, j - 1]
 * 
 * 
 * 
 * 
 * */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int longest_common_subsequence(std::string str1, std::string str2){
    //Initializes a 2d vector with str2 + 1 rows and str1 + 1 cols, with all cells initialized to 0
    std::vector<std::vector<int> > matrix(str2.size() + 1, std::vector<int>(str1.size() + 1, 0));

    for


}

int main(){

}