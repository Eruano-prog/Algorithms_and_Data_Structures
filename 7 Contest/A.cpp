#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::cin;


int main(){
    int number;
    vector<int> arr;
    vector<int> ans;
    int num;

    cin >> number;
    for (int i = 0; i< number;i++){
        cin >> num;
        arr.push_back(num);
    }
    int prev[number];
    int d[number];
    for (int i = 0; i < number; i++){
        d[i] = 1;
        prev[i] = -1;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i] & d[j] + 1 > d[i]){
                d[i] = d[j] + 1;
                prev[i] = j;
            }
        }
    }
    int pos = 0;
    int lengh = d[0];
    for (int i = 0; i < number ; i++){
        if (d[i] > lengh){
            pos = i;
            lengh = d[i];
        }
    }
    while(pos != -1){
        ans.push_back(arr[pos]);
        pos = prev[pos];
    }
    std::reverse(std::begin(ans),std::end(ans));


    cout << ans.size() << endl;
    for (int i = 0; i< ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}