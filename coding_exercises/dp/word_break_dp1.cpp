#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

bool is_in(string str, set<string>& dictionary){
    if(dictionary.find(str) != dictionary.end()) { return true; }
    return false;
}

bool word_break(string str, set<string>& dictionary){
    int size = str.size();

    bool arr[size];

    for(auto i: arr){ i = 0; }

    for (int i = 1; i <= size; ++i){
        
    }


}

int main(){
    return 0;
}