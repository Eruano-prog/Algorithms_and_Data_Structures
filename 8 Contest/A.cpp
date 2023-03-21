#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


struct Node{
    int data;

    Node *parent= nullptr, *left= nullptr, *right= nullptr;

    Node(int dat){
        data = dat;
    }
};


class List{
    Node *Head = nullptr;
    vector<Node*> nodes;

public:
    vector<int> output;
    void push_vec(int data){
        Node* pnode = new Node(data);
        nodes.push_back(pnode);
    }

    void build_tree(){
        Head = add_node(0);
    }

    void change_pos(int n){
        change(nodes[n]);
    }

    void fill_output(){
        LRN_out(Head);
    }

private:
    Node* add_node(int count){
        if (count>0) {
            nodes[count]->parent = nodes[(count - 1) / 2];
        }
        if ((count*2)+1 < nodes.size()) {
            nodes[count]->left = add_node((count * 2) + 1);
        }
        if ((count*2)+2 < nodes.size()){
            nodes[count]->right = add_node((count*2)+2);
        }
        return nodes[count];
    }

    void change(Node* V){
        if (Head == V) return;

        Node* P = V->parent;
        if (P->parent != nullptr){
            Node* PP = P->parent;
            if (P == PP->left){
                PP->left = V;
                V->parent = PP;
            }
            else{
                PP->right = V;
                V->parent = PP;
            }
        }

        if(V == P->left){
            P->left = V->left;
            V->parent = P->parent;
            P->parent = V;
            if (V->left != nullptr) V->left->parent = P;
            V->left = P;
        }
        else{
            P->right = V->right;
            V->parent = P->parent;
            P->parent = V;
            if (V->right != nullptr) V->right->parent = P;
            V->right = P;
        }
        while(Head->parent != nullptr){
            Head = Head->parent;
        }
    }

    void LRN_out(Node* node){
        if (node->left != nullptr) LRN_out(node->left);
        if (node->right != nullptr) LRN_out(node->right);
        output.push_back(node->data);
    }

};

int main() {
    int N, Q;
    cin >> N >> Q;
    List counts;
    int k;
    for (int i = 0; i < N; ++i) {
        cin >> k;
        counts.push_vec(k);
    }
    counts.build_tree();

    for (int i = 0; i < Q; ++i) {
        cin >> k;
        counts.change_pos(k - 1);
    }

    counts.fill_output();

    cin >> N >> Q;
    List letters;
    char letter;
    for (int i = 0; i < N; ++i) {
        cin >> letter;
        letters.push_vec(letter);
    }
    letters.build_tree();

    for (int i = 0; i < Q; ++i) {
        cin >> k;
        letters.change_pos(k - 1);
    }

    letters.fill_output();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < counts.output[i]; ++j) {
            cout << (char)letters.output[i];
        }
    }
    return 0;
}
