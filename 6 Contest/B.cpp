#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

enum Side {
    right=0,
    left=1
};

struct Vector_node{
    int key;
    int children[2];

    Vector_node(int key, int left, int right) : key(key){
        children[0] = left;
        children[1] = right;
    }
};

struct Node{
    int key;
    int height;
    int inp_num;
    Node* children[2];

    Node(int key, Node * left, Node * right, int num) : key(key), height(0), inp_num(num){
        children[0] = left;
        children[1] = right;
    }

    Node(Vector_node * node, int num) : height(0), key(node->key), inp_num(num){
        children[0] = children[1] = nullptr;
    }
};

struct AVL_Tree{
    vector<Vector_node *> input_tree;
    vector<Vector_node *> output_tree;
    Node* root = nullptr;

    void make_tree(){
        root = new Node(input_tree[0], 0);
        v_make(root);
    }

    void v_make(Node * v){
        if (input_tree[v->inp_num]->children[0] == -1){
            v->children[0] = nullptr;
        }
        else{
            v->children[0] = new Node(input_tree[input_tree[v->inp_num]->children[0]], input_tree[v->inp_num]->children[0]);
            v_make(v->children[0]);
        }

        if (input_tree[v->inp_num]->children[1] == -1){
            v->children[1] = nullptr;
        }
        else{
            v->children[1] = new Node(input_tree[input_tree[v->inp_num]->children[1]], input_tree[v->inp_num]->children[1]);
            v_make(v->children[1]);
        }
    }

    int count_balance(Node * v){
        int t1=0, t2=0;
        if (v->children[1] != nullptr){
            t1 = v->children[1]->height;
        }
        if (v->children[0] != nullptr){
            t2 = v->children[0]->height;
        }
        return t1 - t2;
    }

    void count_height(){
        if (input_tree.empty()){
            return;
        }
        dfs(root);
    }

    void fix_height(Node * v){
        v->height = std::max(height_left(v), height_right(v)) + 1;
    }

    int height_right(Node * v){
        return v->children[1] == nullptr ? 0 : v->children[1]->height;
    }

    int height_left(Node * v){
        return v->children[0] == nullptr ? 0 : v->children[0]->height;
    }

    void dfs(Node * v){
        for (auto child : v->children){
            if (child != nullptr){
                dfs(child);
            }
        }
        fix_height(v);
    }

    Node* rotate(Node * v, int side){
        Node * u = v->children[side == Side::left ? 1 : 0];
        v->children[side == Side::left ? 1 : 0] = u->children[side == Side::left ? 0 : 1];
        u->children[side == Side::left ? 0 : 1] = v;
        fix_height(v);
        fix_height(u);
        return u;
    }

    Node * balance(Node * v){
        if (count_balance(v->children[1]) < 0){
            v->children[1] = rotate(v->children[1], Side::right);
        }
        return rotate(v, Side::left);
    }

    void make_output_tree(){
        std::queue<Node *> queue;
        queue.push(root);
        int num = 1;
        while (!queue.empty()){
            Node* v = queue.front();
            queue.pop();
            int children_num[2] = {0, 0};
            for (int i = 0; i < 2; i++){
                if (v->children[i] != nullptr){
                    queue.push(v->children[i]);
                    children_num[i] = ++num;
                }
            }
            output_tree.push_back(new Vector_node(v->key, children_num[0], children_num[1]));
        }
    }
};

int main(){
    int n;
    cin >> n;
    auto Tree = new AVL_Tree();

    for (int i = 0; i < n; i++){
        int key, left, right;
        cin >> key >> left >> right;
        Tree->input_tree.push_back(new Vector_node(key, left - 1, right - 1));
    }
    Tree->make_tree();

    Tree->count_height();
    Tree->root = Tree->balance(Tree->root);

    Tree->make_output_tree();

    cout << n << endl;
    for (Vector_node* v : Tree->output_tree){
        cout << v->key << " " << v->children[0] << " " << v->children[1] << endl;
    }
}