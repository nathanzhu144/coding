#include <string>

char findExtraCharcter(string strA, string strB) 
{ 
    // result store the result 
    int res = 0, i; 
  
    // traverse string A till end and  
    // xor with res 
    for (i = 0; i < strA.length(); i++) { 
  
        // xor with res 
        res ^= strA[i]; 
    } 
  
    // traverse string B till end and  
    // xor with res 
    for (i = 0; i < strB.length(); i++) { 
  
        // xor with res 
        res ^= strB[i]; 
    } 
  
    // print result at the end 
    return ((char)(res)); 
} 
  
int main() 
{ 
    // given string 
    string strA = "abcd"; 
    string strB = "cbdad"; 
    cout << findExtraCharcter(strA, strB); 
    return 0; 
} 