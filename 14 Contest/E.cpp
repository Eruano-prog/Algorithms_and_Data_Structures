#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

bool check_name(string& str){
//    0-Not a letter 1-Big letter 2-small letter
    int aut[3][3] = {{3, 1, 3}, {3, 3, 1}, {3, 3, 3}};
    int state = 0;
    for (auto let : str) {
        int next;
        if (let >= 'a' and let <= 'z') next = 2;
        else if (let >= 'A' and let <= 'Z') next = 1;
        else next = 0;

        state = aut[state][next];
    }
    return state == 1;
}

bool check_age(string& str){
//    0-Not a number 1-number
    int aut[4][2] = {{3, 1}, {3, 2}, {3, 3}, {3, 3}};
    int state = 0;

    for (auto let : str) {

        int next;
        if (let >= 48 and let <= 57) next = 1;
        else next = 0;

        state = aut[state][next];
    }
    return state == 2;
}

bool if_array_of_int(string& str, int size, int start){
    for (int i = 0; i < size; ++i) {
        if (str[i+start] < '0' or str[i+start] > '9'){
            return false;
        }
    }
    return true;
}

bool check_phone(string& str){
//    + - 0; 7 - 1; 8 - 2; ( - 3; ) - 4; - - 5; 10int - 6; 4int - 7; 3int - 8; 2int - 9;
    int aut[18][11] = {{1, 15, 15, 17, 17, 17, 17, 17, 17, 17, 17},
                       {17, 2, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                       {17, 17, 17, 3, 17, 17, 16, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 4, 17, 17},
                       {17, 17, 17, 17, 5, 17, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 6, 17, 17, 12, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 7, 17, 17},
                       {17, 17, 17, 17, 17, 8, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 9, 17},
                       {17, 17, 17, 17, 17, 10, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 11, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 13, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 14, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 16, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17},
                       {17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17}};
    int state = 0;

    for (int i=0; i < str.size(); i++) {
        int next;
        char let = str[i];

        if (let == '+') next = 0;
        else if ((state == 0 or state == 1) and let == '7') next = 1;
        else if ((state == 0 or state == 1) and let == '8') next = 2;
        else if (let == '(') next = 3;
        else if (let == ')') next = 4;
        else if (let == '-') next = 5;
        else if (if_array_of_int(str, 10, i)) next = 6;
        else if (if_array_of_int(str, 4, i)) next = 7;
        else if (if_array_of_int(str, 3, i)) next = 8;
        else if (if_array_of_int(str, 2, i)) next = 9;
        else next = 10;


        state = aut[state][next];
        if(next == 6) i += 9;
        else if (next == 7) i += 3;
        else if (next == 8) i += 2;
        else if (next == 9) i += 1;
    }
    return state == 16 or state == 14 or state == 11;
}

bool check_address(string& str){
//    g - 0; . - 1; ABC - 2; other - 3
    int aut[7][4] = {{1, 6, 6, 6},
                     {6, 2, 6, 6},
                     {6, 6, 3, 6},
                     {6, 6, 4, 6},
                     {6, 6, 5, 6},
                     {6, 6, 6, 6},
                     {6, 6, 6, 6}};
    int state = 0;

    for (int i = 0; i < str.size() - 1; ++i) {
        char let = str[i];
        int next;

        if (let == 'g') next = 0;
        else if (let == '.') next = 1;
        else if (let <= 'Z' and let >= 'A') next = 2;
        else next = 3;

        state = aut[state][next];
    }
    return state == 5;
}

bool check_street(string& str){
//    u - 0; l - 1; . - 2; ABC - 3; abc - 4; other - 5
    int aut[6][6] = {{1, 5, 5, 5, 5, 5},
                     {5, 2, 5, 5, 5, 5},
                     {5, 5, 3, 5, 5, 5},
                     {5, 5, 5, 4, 5, 5},
                     {5, 5, 5, 5, 4, 5},
                     {5, 5, 5, 5, 5, 5}};
    int state = 0;

    for (int i = 0; i < str.size()-1; ++i) {
        char let = str[i];
        int next;

        if (let == 'u') next = 0;
        else if (let == 'l') next = 1;
        else if (let == '.') next = 2;
        else if (let >= 'A' and let <= 'Z') next = 3;
        else if (let >= 'a' and let <= 'z') next = 4;
        else next = 5;

        state = aut[state][next];
    }
    return state == 5;
}

bool check_d(string& str){
//    d - 0; . - 1; 123 - 2; other - 3
    int aut[4][4] = {{1, 3, 3, 3},
                     {3, 2, 3, 3},
                     {3, 3, 2, 3},
                     {3, 3, 3, 3}};
    int state = 0;

    for (auto let : str) {
        if (let == ',') continue;

        int next;
        if (let == 'd') next = 0;
        else if (let == '.') next = 1;
        else if (let >= '0' and let <= '9') next = 2;
        else next = 3;

        state = aut[state][next];
    }
    return state == 2;
}

int main() {
    int M;
    cin >> M;
    bool flag;
    for (int i = 0; i < M; ++i) {
        flag = true;

        cin.ignore();
        string data;
        cin >> data;

        flag *= check_name(data);

        cin.ignore();
        cin >> data;
        flag *= check_name(data);

        cin.ignore();
        cin >> data;
        flag *= check_name(data);

        cin.ignore();
        cin >> data;
        flag *= check_age(data);

        cin.ignore();
        cin >> data;
        flag *= check_phone(data);

        cin.ignore();
        cin >> data;
        flag *= check_address(data);

        cin.ignore();
        cin >> data;
        flag *= check_street(data);

        cin.ignore();
        cin >> data;
        flag *= check_d(data);

        if (flag){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
    }

    return 0;
}
