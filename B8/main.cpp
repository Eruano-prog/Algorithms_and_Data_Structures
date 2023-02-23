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
            P->parent = V;
            if (V->left != nullptr) V->left->parent = P;
            V->left = P;
        }
        else{
            P->right = V->right;
            P->parent = V;
            if (V->right != nullptr) V->right->parent = P;
            V->right = P;
        }
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    List ls;
    int k;
    for (int i = 0; i < N; ++i) {
        cin >> k;
        ls.push_vec(k);
    }
    ls.build_tree();

    ls.change_pos(2);
    ls.change_pos(3);
    ls.change_pos(2);

    return 0;
}
