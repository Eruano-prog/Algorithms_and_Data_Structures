#include <iostream>

using std::string;
using std::cout;
using std::cin;

bool check(string& str, int i, int j, int k){
    for (int l = 0; l < k; ++l) {
        if (str[i] == str[j]){
            i++; j++;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;

    string str;
    cin >> str;
    int i, j, k;
    int count = 0;
    for (int l = 0; l < M; ++l) {
        cin >> i >> j >> k;
        i--; j--;
        if (check(str, i, j, k)){
            count++;
        }
    }
    cout << count;
}