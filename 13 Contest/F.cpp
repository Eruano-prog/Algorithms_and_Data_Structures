#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;

struct Node{
    long int hash_1, hash_2, count;

    Node(int h_1 = -1, int h_2 = -1, int c = 0): hash_1(h_1), hash_2(h_2), count(c){}
};

class Hash_table{
public:
    vector<Node> table_1;
    vector<Node> table_2;
    int size = 1000000;

    Hash_table(){
        table_1.resize(size);
        table_2.resize(size);
    }

    int Hash_1(const string& s) const{
        unsigned long hash = 0;
        for (char i : s) {
            hash = (108301 * hash + i) % 2147483646;
        }
        return hash % size;
    }

    int Hash_2(const string& s) const{
        unsigned long hash = 0;
        for (char i : s) {
            hash = (hash * 27627 + i) % 2147483646;
        }
        return hash % size;
    }

    bool Insert(long int hash_1, long int hash_2, int count=1){

        if (table_1[hash_1].hash_1 == hash_1 and table_1[hash_1].hash_2 == hash_2){
            table_1[hash_1].count++;
            return true;
        }
        if (table_2[hash_2].hash_1 == hash_1 and table_2[hash_2].hash_2 == hash_2){
            table_2[hash_2].count++;
            return true;
        }

        if (table_1[hash_1].hash_1 == -1){
            table_1[hash_1].hash_1 = hash_1;
            table_1[hash_1].hash_2 = hash_2;
            table_1[hash_1].count = count;
            return true;
        }
        if (table_2[hash_2].hash_1 == -1){
            table_2[hash_2].hash_1 = hash_1;
            table_2[hash_2].hash_2 = hash_2;
            table_2[hash_2].count = count;
            return true;
        }

        int temp_h1 = table_1[hash_1].hash_1;
        int temp_h2 = table_1[hash_1].hash_2;
        int temp_c = table_1[hash_1].count;
        table_1[hash_1].hash_1 = hash_1;
        table_1[hash_1].hash_2 = hash_2;
        table_1[hash_1].count = count;
        if(Insert(temp_h1, temp_h2, temp_c)){
            return true;
        }

        table_1[hash_1].hash_1 = temp_h1;
        table_1[hash_1].hash_2 = temp_h2;
        table_1[hash_1].count = temp_c;

        temp_h1 = table_2[hash_2].hash_1;
        temp_h2 = table_2[hash_2].hash_2;
        temp_c = table_2[hash_2].count;
        table_2[hash_2].hash_1 = hash_1;
        table_2[hash_2].hash_2 = hash_2;
        table_2[hash_2].count = count;

        if(Insert(temp_h1, temp_h2, temp_c)){
            return true;
        }

        table_2[hash_2].hash_1 = temp_h1;
        table_2[hash_2].hash_2 = temp_h2;
        table_2[hash_2].count = temp_c;
        return false;
    }

    int get_count(int hash_1, int hash_2){
        if (table_1[hash_1].hash_1 == hash_1 and table_1[hash_1].hash_2 == hash_2){
            return table_1[hash_1].count;
        }

        if (table_2[hash_2].hash_1 == hash_1 and table_2[hash_2].hash_2 == hash_2){
            return table_2[hash_2].count;
        }
        return -1;
    }
};

int main() {
    int N;
    std::cin >> N;

    Hash_table H;

    std::pair<unsigned int, unsigned int> hashes[N*3];

    string str;
    for (int i = 0; i < 3*N; ++i) {
        cin >> str;
        hashes[i] = std::make_pair(H.Hash_1(str), H.Hash_2(str));
        H.Insert(hashes[i].first, hashes[i].second);
    }

    int count, cur;
    for (int i = 0; i < 3; ++i) {
        count = 0;
        for (int j = 0; j < N; ++j) {
            cur = i*N + j;
            if (H.get_count(hashes[cur].first, hashes[cur].second) == 1){
                count += 3;
            }
            if (H.get_count(hashes[cur].first, hashes[cur].second) == 2){
                count += 1;
            }
        }
        cout << count << ' ';
    }
    return 0;
}
