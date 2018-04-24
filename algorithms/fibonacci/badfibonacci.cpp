#include  <iostream>

long long fib(int n)
{
    /*base case*/
    if (n == 1) 
        return 1;
    if (n == 0){
        return 0;
    }
    return fib(n-1) + fib(n -2 );
}  


int main(){
    std::cout << fib(43);
    return 0;
}