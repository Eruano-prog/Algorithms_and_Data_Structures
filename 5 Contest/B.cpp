#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int **array;

struct Node{
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
};

bool check(Node* nod, int min, int max) {
    if (nod == nullptr)
        return true;
    if (nod->data <= min)
        return false;
    if (nod->data >= max)
        return false;

    return check(nod->right, nod->data, max) && check(nod->left, min, nod->data);
}

struct Node* createTree(struct Node* root, int data, int pos) {
    if (root == nullptr) {
        Node* node = new Node;
        node->data = data;
        root = node;
    }

    if (array[pos][1] == 0 and array[pos][2] == 0) {
        return root;
    }
    else if (array[pos][2] == 0) {
        root->left = createTree(root->left, array[array[pos][1]-1][0], array[pos][1]-1);
    }
    else if (array[pos][1] == 0) {
        root->right = createTree(root->right, array[array[pos][2]-1][0], array[pos][2]-1);
    }
    else {
        root->left = createTree(root->left, array[array[pos][1]-1][0], array[pos][1]-1);
        root->right = createTree(root->right, array[array[pos][2]-1][0], array[pos][2]-1);
    }
    return root;
}

int main() {

    int n;
    cin >> n;

    if (n == 0){
        cout << "YES" << endl;
        return 0;
    }

    array = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i < n; ++i) {
        array[i] = (int*) malloc(3*sizeof(int));
    }

    for (int i = 0; i < n; ++i) {
        cin >> array[i][0];
        cin >> array[i][1];
        cin >> array[i][2];
    }

    Node *tree = nullptr;
    tree = createTree(tree, array[0][0], 0);

    if (check(tree, INT_MIN, INT_MAX)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
