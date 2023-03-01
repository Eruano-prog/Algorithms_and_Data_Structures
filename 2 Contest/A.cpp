#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using std::cout;
using std::cin;


int main(){
    int n;
    cin >> n;
    std::vector<std::string> ans;

    ans.emplace_back("0");
    ans.emplace_back("1");

    for (int i = 0; i < n-1; ++i) {
        int k = ans.size();
        for (int j = k-1; j >= 0; --j) {
            ans.push_back("1" + ans[j]);
            ans[j] = "0" + ans[j];
        }
    }
    for (std::string str:ans) {
        cout << str << std::endl;
    }
    return 0;
};