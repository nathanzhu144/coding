/**
 * Nathan Zhu August 2nd, 2018 2:46 am at KFC in Beijing, China.
 * 
 * https://www.ics.uci.edu/~eppstein/161/960229.html
 * http://www.cs.umd.edu/~meesh/351/mount/lectures/lect25-longest-common-subseq.pdf
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
 * */

#include <vector>
#include <iostream>
#include <string>

using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int longest_common_subsequence(std::string str1, std::string str2)
{
    //Initializes a 2d vector with str1 + 1 rows and str2 + 1 cols, with all cells initialized to 0
    std::vector<std::vector<int>> matrix(str1.size() + 1, std::vector<int>(str2.size() + 1, 0));

    //note, the strings are 1-indexed. when i or j is equal to 0, it means
    //an empty string. I treat an index of 1 as the first character of the string.
    for (unsigned int i = 0; i <= str1.size(); ++i)
    {
        for (unsigned int j = 0; j <= str2.size(); ++j)
        {
            //Base case, if either string is empty, LCS must be 0
            if (i == 0 || j == 0)
            {
                matrix[i][j] = 0;
            }
            //Case 2: last char of substring does match
            else if(str1[i - 1] == str2[j - 1]){
                matrix[i][j] = 1 + matrix[i - 1][j - 1];
            }
            //Case 1: last char of substring doesn't match
            else{
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    for (unsigned int i = 0; i <= str1.size(); ++i)
    {
        for (unsigned int j = 0; j <= str2.size(); ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return matrix[str1.size()][str2.size()];
}

int main()
{
    std::cout << longest_common_subsequence("dowg", "sdsogs") << std::endl;
    std::cout << longest_common_subsequence("ABRACADABRA", "YABBADABBADOO") << std::endl;
    std::cout << longest_common_subsequence("nematode knowledge", "empty bottle") << std::endl;
    std::cout << longest_common_subsequence("d", "n") << std::endl;
    std::cout << longest_common_subsequence("", "n") << std::endl;
}