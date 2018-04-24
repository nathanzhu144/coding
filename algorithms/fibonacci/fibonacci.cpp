#include <iostream>

// int fib(int n)
//  {
//    /* just like the array you declared in your solution */
//    int f[n+1];
//    int i;

//    /* set up the base cases, just like how you set f[0] to 1*/
//   f[0] = 0;
//   f[1] = 1;

//    for (i = 2; i <= n; i++)
//    {
//        /* using previously solved problem to solve further problems*/
//        f[i] = f[i-1] + f[i-2];
//    }
//      /*return the final result*/
//    return f[n];
// }

/*Global array initialized to 0*/
long long a[1000000] = {0};

// long long fib(long long n)
// {
//     /*base case*/
//     if (n <= 1) 
//         return 1;
//     /*if fib(n) has not been computed, compute it*/
//     if (a[n] == 0) {
//         a[n] = fib(n - 1) + fib(n - 2);
//     }
//     /*Otherwise, simply get a[n] and return it*/
//     return a[n];
// }  


 unsigned long long fib(int n)
 {
   /* just like the array you declared in your solution */
   unsigned long long f[n+1];
   int i;

   /* set up the base cases, just like how you set f[0] to 1*/
  f[0] = 0;
  f[1] = 1;

   for (i = 2; i <= n; i++)
   {
       /* using previously solved problem to solve further problems*/
       f[i] = f[i-1] + f[i-2];
   }
     /*return the final result*/
   return f[n];
}

int main(){
    std::cout << fib(93);
    return 0;
}