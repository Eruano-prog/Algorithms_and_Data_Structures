#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::cout;
using std::cin;

class Field{
public:
    vector<vector<int>> infected;
    std::queue<std::pair<int, int>> queue;
    int ans = 0;
    int n, m;

    Field(int n, int m): n(n), m(m){
        infected.resize(n);
        for (int i = 0; i < n; ++i) {
            infected[i].resize(m);
        }
    }

    void read(){
        char c;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c;
                infected[i][j] = c-48;
                if (infected[i][j] == 1) {
                    queue.emplace(i, j);
                }
            }
        }
    }

    void count_iterations(){
        int i, j;
        while(!queue.empty()){
            i = queue.front().first; j = queue.front().second;
            queue.pop();
            if(i+1 < n && infected[i+1][j] == 0){
                infected[i+1][j] = infected[i][j]+1;
                queue.emplace(i+1, j);
            }
            if(i-1 >= 0 && infected[i-1][j] == 0){
                infected[i-1][j] = infected[i][j]+1;
                queue.emplace(i-1, j);
            }
            if(j+1 < m && infected[i][j+1] == 0){
                infected[i][j+1] = infected[i][j]+1;
                queue.emplace(i, j+1);
            }
            if(j-1 >= 0 && infected[i][j-1] == 0){
                infected[i][j-1] = infected[i][j]+1;
                queue.emplace(i, j-1);
            }
            ans = std::max(ans, infected[i][j]);
        }
    }

};

int main(){
    int n, m;
    cin >> n >> m;

    Field field(n, m);
    field.read();

    field.count_iterations();
    cout << field.ans;
}