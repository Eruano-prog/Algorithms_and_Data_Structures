#include <iostream>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::cin;


int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    int input[N];
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }

    string ans = "a";
    char letter = 'a', next;
    for(int i = 1; i < N; i++){
        if (input[i] != 0) {
            ans += ans[input[i] - 1];
        }
        else {
            vector<bool> letters(26, false);

            int prev = input[i - 1];
            while (prev > 0) {
                letters[ans[prev] - 48] = true;
                prev = input[prev - 1];
            }

            next = letter + 1;
            while (letters[(next) - 48]) {
                next++;
            }
            ans += next;
        }
    }

    cout << ans;
}