#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cout;
using std::cin;

struct point {
    int x = -1, y = -1;
    bool exists = false;

    point(int x=-1, int y=-1, bool e=false): x(x), y(y), exists(e) {}
};

class Hash_table{
public:
    vector<point> hashTable;
    int size = 30000;

    int Hash(int s, int m) {
        return ((s*0.618) - floor(s*0.618)) * m;
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
        int hash = Hash(x, size);
        if (!hashTable[hash].exists) {
            point p(x, y, true);
            hashTable[hash] = p;
        }
        else {
            hash = increase_hash(hash);

            while (hashTable[hash].exists) {
                hash = increase_hash(hash);
            }

            if (!hashTable[hash].exists) {
                point p(x, y, true);
                hashTable[hash] = p;
            }
        }

        int yHash = Hash(y, size);
        if (!hashTable[yHash].exists) {
            point p(x, y, true);
            hashTable[yHash] = p;
        }
        else {
            yHash = increase_hash(yHash);

            while (hashTable[yHash].exists) {
                yHash = increase_hash(yHash);
            }

            if (!hashTable[yHash].exists) {
                point p(x, y, true);
                hashTable[yHash] = p;
            }
        }
    }

    bool checkIfExists(int x, int y) {
        int xHash = Hash(x, size);
        if (hashTable[xHash].x == x and hashTable[xHash].exists) {
            return true;
        }
        while (hashTable[xHash].exists) {
            xHash = increase_hash(xHash);
            if (hashTable[xHash].x == x and hashTable[xHash].exists) {
                return true;
            }
        }

        int yHash = Hash(y, size);
        if (hashTable[yHash].y == y and hashTable[yHash].exists) {
            return true;
        }
        while (hashTable[yHash].exists) {
            yHash = increase_hash(yHash);
            if (hashTable[yHash].y == y and hashTable[yHash].exists) {
                return true;
            }
        }
        return false;
    }

};

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N;
    cin >> N;

    Hash_table H;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        if (!H.checkIfExists(x, y)) {
            H.insert(x, y);
            count++;
        }
    }

    if (count == 3) cout << "YES";
    else cout << "NO";
}