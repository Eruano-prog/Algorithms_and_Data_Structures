#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

struct Node{
    char data;
    struct Node *next;
};

struct List{
    struct Node* Head = nullptr;
    struct Node* Tail = nullptr;

    void enqueue(char data){
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
    char dequeue(){
        struct Node *temp = Head;
        Head = Head->next;
        char n = temp->data;
        free(temp);
        return n;
    }
};


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    char ch, letter;
    int count = 0;
    std::vector<char> SentM;
    int number = 0;
    cin >> letter;

    for (int i = 0; i < n-1; ++i) {
        cin >> ch;
        if (ch > 64){
            for (int j = 0; j < number; ++j) {
                SentM.push_back(letter);
            }
            letter = ch;
            count += number;
            number = 0;
        }
        else{
            number = number * 10 + ch - 48;
        }
    }
    count += number;
    for (int j = 0; j < number; ++j) {
        SentM.push_back(letter);
    }


    std::vector<char> SentS;
    number = 0;
    cin >> letter;
    int ptr = 0;
    int diffs = 0;

    for (int i = 0; i < m - 1; ++i) {
        cin >> ch;
        if (ch > 64){
            for (int j = 0; j < number; ++j) {
                if (SentM[ptr] != letter) {
                    diffs++;
                    ptr++;
                }
            }
            letter = ch;
            number = 0;
        }
        else{
            number = number * 10 + ch - 48;
        }
    }

    if (diffs < k){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
