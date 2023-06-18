#include <iostream>
using std::cin;
using std::cout;
using std::string;

struct Node{
    char data;
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
    char take(){
        struct Node *temp = Top;
        Top = Top->next;
        char n = temp->data;
        delete temp;
        return n;
    }
    void clean_stack(){
        while (Top != nullptr){
            take();
        }
    }
};

int main(void)
{
    struct Stack stack;

    while (true){
        string c;
        getline(cin, c);

        if (c.empty()){
            break;
        }

        int flag = 1;
        for (char i : c){
            if (i == '(' or i == '['){
                stack.add(i);
            }
            else{
                if (stack.Top == nullptr){
                    flag = 0;
                    break;
                }

                char last = stack.take();
                if (last == '(' && i == ')'){
                    continue;
                }
                if (last == '[' && i == ']'){
                    continue;
                }
                flag = 0;
                break;
            }
        }

        if (flag == 1 && stack.Top == nullptr){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }

        stack.clean_stack();
    }
    return 0;
}
