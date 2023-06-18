#include <iostream>
int **arr;
struct Node{
    int data;
    Node *leftchild,*rightchild;
    Node(int val){
        leftchild = nullptr;
        rightchild = nullptr;
        data = val;
    }
};

Node * filltree(Node *root, int val, int pos){
    if (root == nullptr){
        root = new Node(val);}
    if (arr[pos][1] == 0 and arr[pos][2] == 0) return root;
    else if (arr[pos][2]==0){
        root->leftchild = filltree(root->leftchild,arr[arr[pos][1]-1][0],  arr[pos][1]-1);
    }
    else if (arr[pos][1]==0){
        root->rightchild =filltree(root->rightchild,arr[arr[pos][2]-1][0], arr[pos][2]-1);}
    else{
        root->leftchild = filltree(root->leftchild,arr[arr[pos][1]-1][0],  arr[pos][1]-1);
        root->rightchild =filltree(root->rightchild,arr[arr[pos][2]-1][0], arr[pos][2]-1);}

    return root;
}

bool check_tree_in_range(Node* nod, int min, int max) {
    if (nod == nullptr)
        return true;
    if (nod->data <= min)
        return false;
    if (nod->data >= max)
        return false;

    return check_tree_in_range(nod->rightchild, nod->data, max) && check_tree_in_range(nod->leftchild, min, nod->data);
}

int main() {


    int N;
    std::cin >> N;

    Node *tree = nullptr;

    arr = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++ ){
        arr[i] = (int*) malloc(3*sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
        std::cin >> arr[i][2];
    }

    if (N == 0 || N == 1) {
        std::cout << "YES";
        return 0;
    }

    tree = filltree(tree,arr[0][0],0);

    if (check_tree_in_range(tree, INT_MIN, INT_MAX)){
        std::cout<< "YES";
    }
    else{
        std::cout<< "NO";
    }

    return 0;
}