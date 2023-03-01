#include <iostream>
#include <string>
#include <cmath>

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
    std::string str;
    while (cin >> str) {
        int pos = 0;
        int lg = log2(str.length());
        for (int i = 0; i <= lg; ++i) {
            if (!check_bit(str, i)) {
                pos += std::pow(2, i);
            }
        }
        if(pos != 0) invert_on_pos(str, pos);

        for (int j = 0; j < str.length(); ++j) {
            double lg = log2(j+1);
            if((int)lg != lg){
                cout << (int)str[j]-48;
            }
        }
        cout << std::endl;
    }

    return 0;
}
