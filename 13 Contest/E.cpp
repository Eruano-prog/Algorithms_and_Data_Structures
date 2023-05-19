#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class Hash_table{
public:
    vector<int> array;
    int size = 10000000, count = 0;

    Hash_table(){
        array.resize(size, 0);
    }

    int Hash(int m, int i){
        return (size + i - m) % size;
    }

    void Insert(int m, int i){
        int hash = Hash(m, i);

        count += array[hash];
        array[hash]++;
    }
};

int main() {
    int N;
    cin >> N;
    Hash_table H;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        H.Insert(a, i);
    }
    cout << H.count << std::endl;
}