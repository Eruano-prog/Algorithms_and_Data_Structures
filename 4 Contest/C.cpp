#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct List{
    struct Node* Head = nullptr;
    struct Node* Tail = nullptr;

    void enqueue(int data){
        struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
        node->data = data;
        node->next = nullptr;
        node->prev = Tail;


        if(Head == nullptr){
            Head = node;
            Tail = node;
        }
        else{
            Tail->next = node;
            Tail = node;
        }
    }

    void dequeue(){
        if(Head == nullptr) {
            cout << "*\n";
            return;
        }

        Node* Ptr = Head;
        Node* min = Ptr;

        while (Ptr->next != nullptr) {
            Ptr = Ptr->next;
            if (min->data > Ptr->data) {
                min = Ptr;
            }
        }

        Node* Prev = min->prev;
        Node* After = min->next;

        if(Prev != nullptr){
            Prev->next = min->next;
        }
        if(After != nullptr){
            After->prev = min->prev;
        }

        if(min == Head){
            Head = After;
        }
        if(min == Tail){
            Tail = Prev;
        }

        cout << min->data << '\n';
        delete min;

    }

    void decrease(int key, int value){
        struct Node* Ptr = Head;
        for (int i = 0; i < key-1; ++i) {
            Ptr = Ptr->next;
        }
        Ptr->data = value;
    }
};


int main() {
    struct List ls;

    std::string com;
    int data;

    int key, value;

    while (cin >> com){

        if (com[0] == 'p') {
            data = com[5] - 48;
//            cout << "Push " <<data << '\n';
            ls.enqueue(data);
        }
        else if (com[0] == 'e') {
//            cout << "Dequeue" << '\n';
            ls.dequeue();
        }
        else if (com[0] == 'd') {
            key = (int) com[13] - 48;
            value = (int) com[15] - 48;
//            cout << "Change " << key << " to " << value << '\n';
            ls.decrease(key, value);
        }
    }

    return 0;
}
