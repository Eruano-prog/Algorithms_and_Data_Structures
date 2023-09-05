#include <iostream>
#include <string>
#include <regex>

using std::regex_match;
using std::string;
using std::regex;
using std::cout;
using std::cin;

bool isValidName(const string& fullName) {
    // Формат ФИО: Первая буква каждого слова должна быть заглавной, только латинские буквы
    regex reg("^[A-Z][a-z]+?");
    return regex_match(fullName, reg);
}

bool isValidAge(const string& age) {
    // Формат возраста: 2 цифры
    regex reg("[0-9]{2}");
    return regex_match(age, reg);
}

bool isValidPhoneNumber(const string& phoneNumber) {
    // Формат номера телефона:
    // +7(967)645-7442
    // +79676567442
    // 79676557542
    // 89686557442
    // +7(967)-666-74-42
    regex pattern(R"((\+?7|8)\(\d{3}\)-?\d{3}-?\d{2}-?\d{2})");
    return regex_match(phoneNumber, pattern);
}

bool isValidAddress(const string& address) {
    // Формат адреса: g.XXX ul.XXX d.XXXXXX
    regex reg(R"(g\.[A-Z]{3}, ul\.[A-Z][a-z]+, d\.[0-9]\d+$)");
    return regex_match(address, reg);
}

int main() {
    int N;
    cin >> N;
    cin.ignore();

    string str;
    for (int i = 0; i < N; ++i) {
        bool flag = true;

        string name, age, phone, address;

        std::getline(cin, str);

        int j = 0;
        while (str[j] != ' ' and j < str.size()){
            name += str[j];
            j++;
        }
        j++;
        flag = flag and isValidName(name);
        name = "";
        while (str[j] != ' ' and j < str.size()){
            name += str[j];
            j++;
        }
        j++;
        flag = flag and isValidName(name);
        name = "";
        while (str[j] != ' ' and j < str.size()){
            name += str[j];
            j++;
        }
        j++;
        flag = flag and isValidName(name);
        name = "";

        while (str[j] != ' ' and j < str.size()){
            age += str[j];
            j++;
        }
        j++;
        flag = flag and isValidAge(age);

        while (str[j] != ' ' and j < str.size()){
            phone += str[j];
            j++;
        }
        j++;
        flag = flag and isValidPhoneNumber(phone);

        for (;j < str.size(); j++) {
            address += str[j];
        }
        flag = flag and isValidAddress(address);

        if (flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
