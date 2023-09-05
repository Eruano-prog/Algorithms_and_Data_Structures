#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;


struct Node{
    int key;
    int height;
    int children[2];

    Node(int key, int left, int right) : key(key), height(0){
        children[0] = left;
        children[1] = right;
    }
};

struct AVL_Tree{
    std::vector<Node *> tree;

    int balance(int v){
        int t1=0, t2=0;
        if (tree[v]->children[1] != -1){
            t1 = tree[tree[v]->children[1]]->height;
        }
        if (tree[v]->children[0] != -1){
            t2 = tree[tree[v]->children[0]]->height;
        }
        return t1 - t2;
    }

    int height_right(Node *v){
        return v->children[1] == -1 ? 0 : tree[v->children[1]] -> height;
    }

    int height_left(Node *v){
        return v->children[0] == -1 ? 0 : tree[v->children[0]] -> height;
    }

    void count_h(Node * v){
        for (int child : v->children){
            if (child != -1){
                count_h(tree[child]);
            }
        }
        v->height = std::max(height_left(v), height_right(v)) + 1;
    }
};

int main(){

    int n;
    cin >> n;
    auto avl = new AVL_Tree();

    for (int i = 0; i < n; i++)
    {
        int key;
        int left, right;
        cin >> key >> left >> right;
        avl->tree.push_back(new Node(key, left-1, right-1));
    }

    if (!avl->tree.empty()){
        avl->count_h(avl->tree[0]);
    }

    for (int i = 0; i < avl->tree.size(); i++){
        cout << avl->balance(i) << std::endl;
    }
}