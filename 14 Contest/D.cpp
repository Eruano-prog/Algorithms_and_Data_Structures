#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::cin;

struct Node{
    string data;
    int weight=1;

    Node *l = nullptr, *r = nullptr, *p = nullptr;
};

class Tree{
public:
    Node* Head;

    void Insert(const string& key){
        Node* cur = Head;
        if (cur == nullptr){
            Head = new Node;
            Head->data = key;
            return;
        }
        while (cur != nullptr){
            if (key <= cur->data){
                cur->weight++;
                if (cur->l == nullptr) break;
                else cur = cur->l;
            }
            if (key > cur->data){
                cur->weight++;
                if (cur->r == nullptr) break;
                else cur = cur->r;
            }
        }
        if (key < cur->data){
            cur->l = new Node;
            cur->l->data = key;
            cur->l->p = cur;
        }
        if (key > cur->data){
            cur->r = new Node;
            cur->r->data = key;
            cur->r->p = cur;
        }
    }

    string get(int index){
        Node* cur_node = Head;
        int cur_indx = 0;
        int weight_l = cur_node->l == nullptr ? 0 : cur_node->l->weight;
        while(cur_indx + weight_l + 1 != index){
            if (cur_indx + weight_l + 1 < index){
                cur_indx = cur_indx + weight_l + 1;
                cur_node = cur_node->r;
            }
            else if (cur_indx + weight_l + 1 > index){
                cur_node = cur_node->l;
            }
            weight_l = cur_node->l == nullptr ? 0 : cur_node->l->weight;
        }
        return cur_node->data;
    }
};

int main(){
    int N;
    cin >> N;
    string str;
    Tree tree{};

    for (int i = 0; i < N; ++i) {
        cin >> str;

        if (str[0] >= '0' and str[0] <= '9'){
            int sum = 0;
            for (auto ch : str) {
                sum = (sum*10) + ch-48;
            }
            cout << tree.get(sum) << '\n';
        }
        else{
            tree.Insert(str);
        }
    }
}