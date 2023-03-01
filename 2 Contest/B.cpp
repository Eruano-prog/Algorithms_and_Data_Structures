#include <iostream>
#include <vector>

using std::cout;
using std::cin;

class Graph{
public:
    std::vector<std::vector<int>> verticles;

     Graph(int t){
         for (int i = 0; i < t; ++i) {
             std::vector<int> temp;
             for (int j = 0; j < t; ++j) {
                 temp.push_back(0);
             }
             verticles.push_back(temp);
         }
     }
};

int main(){
//    int N, M;
//    cin >> N >> M;

    Graph g(3);



    return 0;
}