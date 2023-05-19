#include <iostream>
#include <vector>

using std::cin;
using std::cout;

struct Node{
    int isu = -1, points = 0;
    bool deleted = false;

    Node(int k, int v): isu(k), points(v){}
    Node() = default;
};

class Hash_table{
public:
    std::vector<Node> diffs;
    int size = 80;

    Hash_table(){
        diffs.resize(size, Node());
    }

    int Hash(int key) const{
        return (key * 17) % size;
    }

    int increase_hash(int& hash){
        hash++;
        hash%=size;
        return hash;
    }

    void insert(int isu, int points){
        int hash = Hash(isu);

        if (diffs[hash].isu == -1 or diffs[hash].deleted) {
            diffs[hash].isu = isu;
            diffs[hash].points = points;
            diffs[hash].deleted = false;
            return;
        }
        hash = increase_hash(hash);

        while (diffs[hash].isu != -1 and !diffs[hash].deleted) {
            hash = increase_hash(hash);
        }
        if (diffs[hash].isu == -1 or diffs[hash].deleted) {
            diffs[hash].isu = isu;
            diffs[hash].points = points;
            diffs[hash].deleted = false;
        }
    }

    void delete_node(int key){
        int hash = Hash(key);

        if (diffs[hash].isu == key){
            diffs[hash].deleted = true;
        }

        while (diffs[hash].isu != -1) {
            hash = increase_hash(hash);
            if (diffs[hash].isu == key) {
                diffs[hash].deleted = true;
                return;
            }
        }
    }

    int find_avg(){
        int count = 0, sum = 0;

        for(int i = 0; i < size; i++){
            if(diffs[i].isu != -1 and !diffs[i].deleted){
                count++;
                sum += diffs[i].points;
            }
        }
        return count == 0 ? 0 : sum/count;
    }

    int find_max(){
        int max = 0;
        for(int i = 0; i < size; i++){
            if(diffs[i].isu != -1 and !diffs[i].deleted){
                max = std::max(max, diffs[i].points);
            }
        }
        return max;
    }
};

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int M, Q;
    char com;
    int group, isu, points;
    cin >> M >> Q;
    std::vector<Hash_table> groups;
    groups.resize(M+1);

    for(int i = 0; i < Q; i++) {
        cin >> com >> group;
        if (com == '+') {
            cin >> isu >> points;
            groups[group].insert(isu, points);
        } else if (com == '-') {
            cin >> isu;
            groups[group].delete_node(isu);
        } else if (com == 'm') {
            cout << groups[group].find_max() << "\n";
        }
        else if (com == 'a'){
            cout << groups[group].find_avg() << "\n";
        }
    }
}