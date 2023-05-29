#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;

struct point {
    int x = -1, y = -1;
    bool here = false;

    point(int x=-1, int y=-1, bool e=false): x(x), y(y), here(e) {}
};

class Hash_table{
public:
    vector<point> hashTable;
    int size = 30000;

    int Hash(int s) {
        return ((s*0.618) - floor(s*0.618)) * size;
    }

    int increase_hash(int& hash){
        hash++;
        hash%=size;
        return hash;
    }

    Hash_table(){
        hashTable.resize(size);
    }

    void insert(int x, int y) {
        int hash = Hash(x);
        if (!hashTable[hash].here) {
            point p(x, y, true);
            hashTable[hash] = p;
        }
        else {
            hash = increase_hash(hash);

            while (hashTable[hash].here) {
                hash = increase_hash(hash);
            }

            if (!hashTable[hash].here) {
                point p(x, y, true);
                hashTable[hash] = p;
            }
        }

        int hash_y = Hash(y);
        if (!hashTable[hash_y].here) {
            point p(x, y, true);
            hashTable[hash_y] = p;
            return;
        }
        hash_y = increase_hash(hash_y);

        while (hashTable[hash_y].here) {
            hash_y = increase_hash(hash_y);
        }

        if (!hashTable[hash_y].here) {
            point p(x, y, true);
            hashTable[hash_y] = p;
        }
    }

    bool check(int x, int y) {
        int hash_x = Hash(x);
        if (hashTable[hash_x].x == x and hashTable[hash_x].here) {
            return true;
        }
        while (hashTable[hash_x].here) {
            hash_x = increase_hash(hash_x);
            if (hashTable[hash_x].x == x and hashTable[hash_x].here) {
                return true;
            }
        }

        int hash_y = Hash(y);
        if (hashTable[hash_y].y == y and hashTable[hash_y].here) {
            return true;
        }
        while (hashTable[hash_y].here) {
            hash_y = increase_hash(hash_y);
            if (hashTable[hash_y].y == y and hashTable[hash_y].here) {
                return true;
            }
        }
        return false;
    }

};

int main() {

    int N;
    cin >> N;

    Hash_table H;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        if (!H.check(x, y)) {
            H.insert(x, y);
            count++;
        }
    }

    if (count == 3) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}