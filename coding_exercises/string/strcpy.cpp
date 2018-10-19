/**
 *  Nathan Zhu
 *  Thursday October 28th, 2018
 * 
 *  My attempt to write strcpy.
 * 
 *  Why does my recursive strcpy not work?
 */

#include <iostream>

using namespace std;

//Iterative strcpy
void mycpy(char* destination, char* source){
    while(*source){
        *(destination++) = *(source++);
    }
    *destination = '\0';
}

//Recursive string copy
void mycpyrec(char* dest, char* source){
    *dest = *source;

    if(*dest == '\0'){ return; }

    mycpyrec(dest + 1, source + 1);
}

//Recursive reverse print
void rev_print(char* str){
    if(*str == '\0') return;
    cout << str;
    
    rev_print(str++);
}

int main(){
    char a[] = "Mogger";
    char b[] = "Doggee";
    char temp[15];

    char c[] = "slowersloth";
    char d[] = "@#@#232323ere";

    mycpy(temp, b);
    mycpy(b, a);
    cout << b << endl;
    mycpy(b, temp);
    cout << b << endl;

    mycpyrec(b,a);
    cout << b << endl;
    mycpyrec(b, temp);
    cout << b << endl;

    rev_print(d);
    rev_print(c);

}