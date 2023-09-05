#include <vector>
#include <queue>
#include <iostream>

using std::vector;
using std::endl;
using std::cout;
using std::cin;

enum Side{
    right=0,
    left=1
};

struct Input_Node{
    int key;
    int children[2];

    Input_Node(int key, int left, int right) : key(key){
        children[0] = left;
        children[1] = right;
    }
};

struct Node{
    int key;
    int height;
    int inp_num;
    Node* children[2];

    Node(int key, Node * left, Node * right, int num) : key(key), height(1), inp_num(num){
        children[0] = left;
        children[1] = right;
    }

    Node(Input_Node * node, int num) : height(1), key(node->key), inp_num(num){
        children[0] = children[1] = nullptr;
    }
};

struct AVL_Tree{
    vector<Input_Node *> input_tree;
    vector<Input_Node *> output_tree;
    Node* root = nullptr;

    void make_tree(){
        root = new Node(input_tree[0], 0);
        dfs_make(root);
    }

    void dfs_make(Node * v){
        for (int i = 0; i < 2; i++){
            if (input_tree[v->inp_num]->children[i] == -1){
                v->children[i] = nullptr;
            }
            else{
                v->children[i] = new Node(input_tree[input_tree[v->inp_num]->children[i]], input_tree[v->inp_num]->children[i]);
                dfs_make(v->children[i]);
            }
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
        

        dfs(root);
    }

    void fix_height(Node * v){
        int right = v->children[1] == nullptr ? 0 : v->children[1]->height;
        int left = v->children[0] == nullptr ? 0 : v->children[0]->height;

        v->height = std::max(left, right) + 1;
    }

    void dfs(Node * v){
        for (auto child : v->children){
            if (child != nullptr){
                dfs(child);
            }
        }
        fix_height(v);
    }

    Node * rotate(Node * v, int side){
        Node * u = v->children[side == Side::left ? 1 : 0];
        v->children[side == Side::left ? 1 : 0] = u->children[side == Side::left ? 0 : 1];
        u->children[side == Side::left ? 0 : 1] = v;
        fix_height(v);
        fix_height(u);
        return u;
    }

    Node * balance(Node* v){
        fix_height(v);
        if (count_balance(v) > 1){
            if (count_balance(v->children[1]) < 0){
                v->children[1] = rotate(v->children[1], Side::right);
            }
            return rotate(v, Side::left);
        }
        if (count_balance(v) < -1){
            if (count_balance(v->children[0]) > 0){
                v->children[0] = rotate(v->children[0], Side::left);
            }
            return rotate(v, Side::right);
        }
        return v;
    }

    void make_output_tree(){
        std::queue<Node *> queue;
        queue.push(root);
        int num = 1;
        while (!queue.empty()){
            Node * v = queue.front();
            queue.pop();
            int children_num[2] = {0, 0};
            for (int i = 0; i < 2; i++){
                if (v->children[i] != nullptr){
                    queue.push(v->children[i]);
                    children_num[i] = ++num;
                }
            }
            output_tree.push_back(new Input_Node(v->key, children_num[0], children_num[1]));
        }
    }

    Node * insert(Node * root, int key){
        if (root == nullptr){
            return new Node(key, nullptr, nullptr, static_cast<int>(input_tree.size()+1));
        }
        root->children[key < root->key ? 0 : 1] = insert(root->children[key < root->key ? 0 : 1], key);
        return balance(root);
    }
};

int main(){

    int n;
    cin >> n;
    auto avl = new AVL_Tree();

    for (int i = 0; i < n; i++){
        int key, left, right;
        cin >> key >> left >> right;
        avl->input_tree.push_back(new Input_Node(key, left-1, right-1));
    }

    int key;
    cin >> key;

    if (n == 0){
        cout << 1 << '\n' << key << ' ' << 0 << ' ' << 0 << endl;
        return 0;
    }

    avl->make_tree();
    avl->count_height();
    avl->root = avl->insert(avl->root, key);
    avl->make_output_tree();

    cout << n + 1 << endl;
    for (auto v : avl->output_tree){
        cout << v->key << ' ' << v->children[0] << ' ' << v->children[1] << endl;
    }
}