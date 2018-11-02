/**
 * Nathan Zhu
 * Nov 1st, 2018 7:07 pm
 * 
 * At foundry lofts figuring out how to add strings.
 * 
 */

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


string addStrings(string num1, string num2, int base)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    string returned = "";
    int carry = 0;

    while (i >= 0 || j >= 0 || carry == 1)
    {
        int sum = 0;
        if (i >= 0)
        {
            sum += (num1[i--] - '0');
        }
        if (j >= 0)
        {
            sum += (num2[j--] - '0');
        }
        sum += carry;
        carry = sum / base;
        returned += to_string(sum % base);
    }

    reverse(returned.begin(), returned.end());
    return returned;
}

string addStringsBase10(string num1, string num2)
{
    return addStrings(num1, num2, 10);
}

string addStringsBase2(string num1, string num2)
{
    return addStrings(num1, num2, 2);
}

int main(){
    cout << addStringsBase10("12341249929392", "999999999992333332323232329999992310") << endl;
    cout << addStringsBase2("11001111111110", "111111111100000000000000101010100101111111100111") << endl;
}