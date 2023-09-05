#include <iostream>

using std::cin;
using std::cout;

struct Node{
    int data;
    struct Node *next;
};

struct List{
    struct Node* Head = nullptr;
    struct Node* Tail = nullptr;

    void enqueue(int data){
        struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
        node->data = data;
        node->next = nullptr;

        if(Head == nullptr){
            Head = node;
            Tail = node;
        }
        else{
            Tail->next = node;
            Tail = node;
        }
    }
    int dequeue(){
        struct Node *temp = Head;
        Head = Head->next;
        int n = temp->data;
        free(temp);
        return n;
    }
};


int main() {
    struct List ls;
    struct List res;

    int N;
    cin >> N;
    int count = 0;

    char com;
    int data;
    for(int i=0; i<N; i++){
        cin >> com;
        if(com == '+'){
            cin >> data;
            ls.enqueue(data);
        }
        else{
            int n = ls.dequeue();
            res.enqueue(n);
            count++;
        }
    }
    for (int i = 0; i < count; ++i) {
        cout << res.dequeue() << "\n";
    }

    return 0;
}
