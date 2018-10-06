#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void sort01(std::vector<int>& vec){
    int left = 0;
    int right = vec.size() - 1;
    while(left < right){
        if(vec[left] == 0){
            ++left;
        }
        else{
            while(right >= 0 && vec[right] == 1){
                --right;
            }
            swap(vec[left], vec[right]);
        }
    }
}

void sort012(vector<int>& vec){
    int left = 0;                  //rightmost 0
    int right = vec.size() - 1;     //rightmost 2
    int middle = 0;                //rightmost 1

    while(middle <= right){
        if(vec[middle] == 0){
            swap(vec[middle], vec[left]);
            ++left;
            ++middle;
        }
        else if(vec[middle] == 1){
            //swap(vec[middle], vec[left]);
            ++middle;
        }
        else if(vec[middle] == 2){
            swap(vec[middle], vec[right]);
            --right;
        }
    }
}

void print_vec(vector<int> vec){
    for(auto i: vec){
        std::cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> a = {1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1};
    print_vec(a);
    sort01(a);
    print_vec(a);
    vector<int> b = {2, 2, 0, 0, 1, 0, 0, 2, 1, 0, 2, 1};
    print_vec(b);
    sort01(b);
    print_vec(b);

}