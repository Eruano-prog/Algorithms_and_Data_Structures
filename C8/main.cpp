#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;


bool check_bit(std::string const &string, int const &i){
    int res=0, k=0;
    int start = std::pow(2, i);

    for (int j = start; j <= string.length(); j += start*2) {
        for (k = 0; ((j+k <= string.length()) || (k < start)); ++k) {
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

int main() {
    int t;
    cin >> t;
    std::string str;

    cin >> str;
    int pos=0;
    int lg = log2(str.length());
    for (int i = 0; i <= lg; ++i) {
        if (!check_bit(str, i)){
            pos += std::pow(2, i);
            cout << i << std::endl;
        }
    }
    cout << pos;
    return 0;
}
