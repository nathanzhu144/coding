// C++ program to find an extra element pre.sent
// in arr1[]
#include <iostream>
#include <algorithm>
#include <cmath>

int my_ceil(double a){
    int comp = (int)a;
    return (a - comp == 0) ? comp : comp + 1; 
}

// Returns index of extra element in arr1[].
// n is size of arr2[]. Size of arr1[] is
// n-1.
int find_extra(int arr1[], int arr2[], int n) {
    int start = 0;
    int end = n - 1;
    //mid has to be greater or equal to one, so no infinite loop below
    int mid = my_ceil((double)(end - start) / 2);

    while(start != end){
        //If *(arr2 + mid) == *(arr1 + mid), then difference is after
        //this location.
        if(arr1[start + mid] == arr2[start + mid]){
            start += mid;
            mid = my_ceil((double)(end - start) / 2);                  
        }
        //If *(arr2 + mid) != *(arr1 + mid), then difference is before or at
        //this location.
        else {
            end -= mid;
            mid = my_ceil((double)(end - start) / 2);
        }
    }

    return (arr1[start + mid] == arr2[start + mid]) ? n : start;
}
 
// Driver code
int main()
{
    int arr1[] =  {2, 4, 6, 8, 10, 12};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[]  =  {2, 4, 6, 8, 10, 12, 1000};
    int arr3[] = {2, 1, 4, 6, 8, 10, 12};
    int arr4[] = {2, 4, 6, -100, 8, 10, 12};
 
    // Solve is passed both arrays
    std::cout << "find_extra(arr2, arr1, n) for arr1 aginst arr2 is index: " << find_extra(arr2, arr1, n) << std::endl;
    std::cout << "find_extra(arr3, arr1, n) for arr1 aginst arr2 is index: " << find_extra(arr3, arr1, n) << std::endl;
    std::cout << "find_extra(arr4, arr1, n) for arr1 aginst arr2 is index: " << find_extra(arr4, arr1, n) << std::endl;
    
    return 0;
}