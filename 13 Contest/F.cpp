#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

class Hash_table{
public:
    vector<std::pair<int, int>> array;
    int size = 10000000, count = 0;

    Hash_table(){
        array.resize(size);
    }

    int Hash(string s){
        int hash;
        for (char i : s) {
            hash += i;
        }
        return hash % size;
    }

    void Insert(std::string s){
        int hash = Hash(s);
        
        array[hash].second++;
    }
};

int main() {
    int N;
    std::cin >> N;

    Hash_table H;

    vector<string> first, second, third;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < ; ++j) {
            
        }
    }
    
    return 0;
}
