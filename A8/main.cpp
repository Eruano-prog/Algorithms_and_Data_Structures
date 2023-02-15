#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    char ch, letter;
    int count = 0;
    std::vector<char> SentM;
    int number = 0;
    cin >> letter;

    for (int i = 0; i < n-1; ++i) {
        cin >> ch;
        if (ch > 64){
            for (int j = 0; j < number; ++j) {
                SentM.push_back(letter);
            }
            letter = ch;
            count += number;
            number = 0;
        }
        else{
            number = number * 10 + ch - 48;
        }
    }
    count += number;
    for (int j = 0; j < number; ++j) {
        SentM.push_back(letter);
    }


    std::vector<char> SentS;
    number = 0;
    cin >> letter;
    int diffs = 0;

    int i = 0;
    while (i < count){
        cin >> ch;
        if (ch < 64) {
            number = number * 10 + ch - 48;
            continue;
        }
        else{
            for (int j = 0; j < number; ++j) {
                if(SentM[i] != letter){
                    diffs
                }
            }
        }
    }


    return 0;
}
