#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

int main(){
    int N, M;
    cin >> N >> M;
    int arr[N];

    for(int i = N - 1; i >= 0; i--)
        cin >> arr[i];

    std::queue<int> ans;

    for(int i = N / 2; i < N; i++){
        int k = 1;
        bool f = true;
        for(int j = i; j < N; j++){
            if(arr[i - k] != arr[j]) {
                f = false;
                break;
            }
            k++;
        }
        if (f)
            ans.push(i);
    }
    ans.push(N);
    while(!ans.empty()){
        cout << ans.front() << ' ';
        ans.pop();
    }
}