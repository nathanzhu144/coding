/**
 * Thursday, October 25th, 2018.  
 * https://leetcode.com/problems/sort-characters-by-frequency 
 *  
 *  How to sort all characters in a string by frequency.
 *  
 *  EABBAAS -> AAABBSE
 */

#include <iostream>
#include <string>
#include <map>
#include <queue>


using namespace std;

struct Key
{
  public:
    int num;
    char letter;
};

bool operator<(const Key& key1, const Key& key2)
{
    return key1.num < key2.num;
}

string frequencySort(string s)
{
    string str = "";
    map<char, int> letters;

    for (unsigned int i = 0; i < s.size(); ++i)
    {
        if (letters.find(s[i]) == letters.end())
        {
            letters[s[i]] = 1;
        }
        else
        {
            letters[s[i]]++;
        }
    }

    priority_queue<Key> pq;
    for (auto i = letters.begin(); i != letters.end(); ++i)
    {
        pq.push(Key{i->second, i->first});
    }

    while (!pq.empty())
    {
        Key temp = pq.top();
        pq.pop();

        for (int i = 0; i < temp.num; ++i)
        {
            str += temp.letter;
        }
    }

    return str;
}

int main(){
    cout <<  frequencySort("ASDFASDFASDFWEWEEEEE");
    return 0;
}