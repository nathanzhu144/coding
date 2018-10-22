#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

bool is_in(string str, set<string>& dictionary){
    return dictionary.find(str) != dictionary.end();
}

bool word_break(string& str, set<string>& dictionary){
    int size = str.size();

    if(str.empty()) { return true; }
    // bool arr[size];

    // for(auto i: arr){ i = 0; }

    for (int i = 0; i < size; ++i){
        if(is_in(str.substr(0, i + 1) && word_break(dictionary, dictionary.substr(i + 1, size - i - 1)))){
            return true;
        }
    }

    return true;
}

int main(){
    return 0;
}