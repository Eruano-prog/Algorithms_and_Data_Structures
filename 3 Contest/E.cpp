#include <iostream>
using std::cin;
using std::cout;

struct Node{
    int data;
    struct Node *next;
};

struct List{
    struct Node* Top = nullptr;
    struct Node* Max = nullptr;
    int max_value = -100000;

    void add(int data){
        struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
        node->data = data;
        node->next = Top;
        Top = node;

        if (max_value < data) { max_value = data;}
        struct Node* max_node = (struct Node*) malloc(sizeof(struct Node*));
        max_node->data = max_value;
        max_node->next = Max;
        Max = max_node;

    }
    void take(){
        struct Node *temp = Top;
        Top = Top->next;
        free(temp);

        struct Node *temp_m = Max;
        Max = Max->next;
        max_value = Max->data;
        free(temp_m);
    }

    int max(){
        if(not_empty()){
            if(max_value > Max->data){

            }
            return Max->data;
        }
        else{
            return NULL;
        }
    }

    int not_empty(){
        return Top != nullptr;
    }


};

struct Queue{
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
    struct List stack;
    struct Queue res;

    int N;
    cin >> N;
    char com;
    int data;
    int count = 0;

    for (int i = 0; i < N; ++i) {
        cin >> com;

        if(com == '+'){
            cin >> data;
            stack.add(data);
        }
        else if (com == '-'){
            stack.take();
        }
        else if (com == 'm'){
            res.enqueue(stack.max());
            count++;
            cin >> com >> com;
        }
    }

    for (int i = 0; i < count; ++i) {
        cout << res.dequeue() << "\n";
    }

    return 0;
}
