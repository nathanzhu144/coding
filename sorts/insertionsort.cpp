#include <iostream>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort(int* arr, int size){

    for(int i = 1; i < size; ++i){
        int ptr1 = i - 1;
        int ptr2 = i;

        if(arr[i] >= arr[ptr1]){ continue; }

        while(arr[ptr2] <= arr[ptr1] && ptr1 != -1){
            swap(arr + ptr2, arr + ptr1);
            ptr1--;
            ptr2--;
        }

 
    }
}

void print(int* arr, int size){
    int *last = arr + size;
    while(arr != last){
       std::cout << *arr << " ";
       ++arr;
    }
}


int main(){

    int arr[11] = {-2, -34, 4, 34, 20, 3, -100, 4, 3, 89, -1};
    insertion_sort(arr, 11);
    print(arr, 11);



}