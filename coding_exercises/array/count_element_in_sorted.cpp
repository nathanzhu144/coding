#include <iostream>
#include <vector>

using namespace std;

int binary_search_first(int left, int right, vector<int> arr, int x){
    int middle = (left + right) / 2;
    int result = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] == x){
            result = mid;
            right = mid - 1;
        }
        else if(arr[mid] < x){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }

    }

    //returns -1 if not found or lowest index
    return result;
}

int binary_search_last(int left, int right, vector<int> arr, int x){
    int middle = (left + right) / 2;
    int result = -1;

    while(left <= right){
        int mid = (left + right) / 2;

        if(arr[mid] == x){
            result = mid;
            left = mid + 1;
        }
        else if(arr[mid] < x){
            left = middle + 1;
        }
        else{
            right = middle - 1;
        }

    }

    //returns -1 if not found or lowest index
    return result;
}

int find_occurrences_of(int x, vector<int> arr){
    
}


int main(){
    return 0;
}