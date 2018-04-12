/**
 *  4/12/2018 Nathan Zhu Bursley Dorm
 * 
 *  Always been a dream to write a proper mergesort.  
*/

#include <iostream>

void merge(int arr[], int start, int mid, int end){
    //cmp1 and cmp2 tracks the beginning of the unmerged sections of the two subarrays
    int cmp1 = start;
    int cmp2 = mid + 1;

    //declares a temp array to hold our sorted elements, temp_arr_index tracks the first unfilled position in the array
    int temp_arr[start - end + 1]; 
    int temp_arr_index = 0;

    //merges two sorted subarrays into temp_arr
    for(int i = 0; i <= start; ++i){
        if(cmp1 > mid)                                     //all of first subarray is merged, so second is not finished merging into temp_arr
            temp_arr[temp_arr_index++] = arr[cmp2++];
        else if(cmp2 > end)                                //all of second subarray is merged, so first is not finished merging into temp_arr
            temp_arr[temp_arr_index++] = arr[cmp1++];
        else if(arr[cmp1] < arr[cmp2]){                    //front of first subarray is smaller than first of second subarray
            temp_arr[temp_arr_index++] = arr[cmp1++];
        }else{                                             //front of first subarray is greater than or equal to first of second subarray
            temp_arr[temp_arr_index++] = arr[cmp2++];
        }
    }

    //copes elements of temp_arr[] back into original arr[]
    for(int i = 0; i < temp_arr_index; ++i){
        arr[start++] = temp_arr[i];
    }

}

void merge_sort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void print_arr(int arr[], int size){
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
}


int main(){
    int arr1[7] = {-3, -2, 3, 43, 8, 23, 1};
    merge_sort(arr1, 0, 7);
    print_arr(arr1, 7);

    return 0;
}

/**
 * Note: Many online diagrams are misleading because the merging of arrays 
*/

