#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::cin;
using std::endl;

void next_letter(std::string const &string, int &iter, int &num, char &letter){
    letter = string[iter];
    iter++;
    while(iter < string.length() & string[iter] < 64){
        num = num * 10 + string[iter] - 48;
        iter++;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    std::string sentM, sentS;
    cin >> sentM >> sentS;

    int num1=0, num2=0, minim, diffs;
    char let1, let2;
    int it1=0, it2=0;
    while(it1 < n || it2 < m){
        if(num1 == 0) next_letter(sentM, it1, num1, let1);
        if(num2 == 0) next_letter(sentS, it2, num2, let2);

        minim = std::min(num1, num2);

        if(let1 != let2){
            diffs += minim;
        }
        num1 -= minim;
        num2 -= minim;

    }

    if (diffs > k){
        cout << "No";
    }
    else{
        cout << "Yes";
    }

    return 0;
}
