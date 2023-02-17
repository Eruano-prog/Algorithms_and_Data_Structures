#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using std::cout;
using std::cin;


bool check_bit(std::string const &string, int const &i){
    int res=0, k=0;
    int start = std::pow(2, i);

    for (int j = start; j <= string.length(); j += start*2) {
        for (k = 0; ((j+k <= string.length()) && (k < start)); ++k) {
            res += string[j-1+k]-48;
        }
    }

    if (res%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

void invert_on_pos(std::string &string, int const &pos){
    if (string[pos-1] == '0'){
        string[pos-1] = '1';
    }
    else{
        string[pos-1] = '0';
    }
}

int main() {
    int t;
    cin >> t;
    std::queue<std::string> ans;
    std::string str;
    for (int k = 0; k < t; ++k) {
        cin >> str;
        int pos = 0;
        int lg = log2(str.length());
        for (int i = 0; i <= lg; ++i) {
            if (!check_bit(str, i)) {
                pos += std::pow(2, i);
            }
        }
        invert_on_pos(str, pos);

        ans.push(str);
    }

    for (int i = 0; i < t; ++i) {
        str = ans.front();
        for (int j = 0; j < str.length(); ++j) {
            double lg = log2(j+1);
            if((int)lg != lg){
                cout << str[j];
            }
        }
        cout << std::endl;
        ans.pop();
    }

    return 0;
}
