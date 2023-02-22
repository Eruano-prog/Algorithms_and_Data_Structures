#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

struct Node{
    int data;

    Node *parent, *left, *right;

    Node(int dat, Node *p, Node *l, Node *r){
        data = dat;
        parent = p;
        left = l;
        right = r;
    }
};


class List{
    Node *Head = nullptr;
    int* arr;

public:
    List(int n){
        int arr[n]
    }

    void build_tree(int* arr, int N){
        for (int i = 0; i < N; ++i) {
            cout << arr[i];
        }

    }

private:
    Node* add_node(Node *node){

    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    int arr[N];
    Node* indexes[N];
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    List ls;
    ls.build_tree(arr, N);

    return 0;
}
