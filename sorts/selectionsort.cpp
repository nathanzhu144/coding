#include <iostream>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int* arr, int size){
    int last = size - 1;
    for(int i = 0; i < size; ++i){
        int* largest = arr + i;
        for(int j = 0; j < last + 1; ++j){
            if(arr[j] > *largest){
                largest = arr + j;
            }
        }
        swap(largest, arr + last);
        --last;
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
    selection_sort(arr, 11);
    print(arr, 11);



}