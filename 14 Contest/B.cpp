#include <iostream>

using std::string;
using std::cout;
using std::cin;

int main(){
    string str;
    cin >> str;
    int size = str.size();
    int P[size+2];
    for (int i = 0; i < size; ++i) {
        P[i] = 0;
    }
    P[0] = 0;
    P[1] = 0;

    int j = 0, i = 1;
    while(i < str.size()) {
        if (str[i] == str[j]){
            i++; j++;
            P[i] = j;
        }
        else{
            if (j > 0){
                j = P[j];
            }
            else{
                i++;
                P[i] = 0;
            }
        }
    }
    for (int i = 1; i < size+1; ++i) {
        cout << P[i] << ' ';
    }
}