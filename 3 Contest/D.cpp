#include <iostream>
using std::cin;
using std::cout;

struct Node{
    int data;
    struct Node *next;
};

struct Stack{
    struct Node* Top = nullptr;

    void add(int data){
        struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
        node->data = data;

        node->next = Top;
        Top = node;

    }
    int take(){
        struct Node *temp = Top;
        Top = Top->next;
        int n = temp->data;
        free(temp);
        return n;
    }
};

int main() {
    char c;
    struct Stack stack;

    while(cin.get(c)){
        if(c == '+'){
            int temp;
            temp = stack.take() + stack.take();
            stack.add(temp);
        }
        else if(c == '-'){
            int temp;
            temp = stack.take() - stack.take();
            stack.add(-temp);
        }
        else if(c == '*'){
            int temp;
            temp = stack.take() * stack.take();
            stack.add(temp);
        }
        else if (c == '\n'){
            break;
        }
        else{
            stack.add(c - '0');
        }
        getchar();
    }

    cout << stack.take();
    return 0;
}
