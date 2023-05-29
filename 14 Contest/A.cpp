#include <iostream>
#include <queue>

using std::string;
using std::cout;
using std::cin;

int Hash(const string& str, int size){
    int hash = 0;
    for (int i = 0; i < size; i++) {
        hash = hash * 2 + str[i];
    }
    return hash;
}

int main(){
    string str, name;
    cin >> str;
    cin >> name;
    int name_s = name.size();
    int def_pow = 2;
    for (int i = 1; i < name_s; ++i) {
        def_pow *= 2;
    }

    int hash_name = Hash(name, name_s),
        cur_hash = Hash(str, name_s);

    std::queue<int> ans;
    int count = 0;
    for (int i = 0; i < (str.size() - name_s + 1); ++i) {
        if (hash_name == cur_hash){
            ans.push(i);
            count++;
        }
        cur_hash = ((cur_hash * 2) - ((int)str[i] * def_pow) + (str[i+name_s]));
    }
    cout << count << '\n';
    while(!ans.empty()){
        cout << ans.front() << ' ';
        ans.pop();
    }
}
