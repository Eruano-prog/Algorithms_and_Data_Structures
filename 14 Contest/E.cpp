#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::regex;
using std::cout;
using std::cin;

bool isValidFullName(const string& fullName) {
    // Формат ФИО: Первая буква каждого слова должна быть заглавной, только латинские буквы
    regex regex("^[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+ $");
    return regex_match(fullName, regex);
}

bool isValidAge(const string& age) {
    // Формат возраста: 2 цифры
    regex regex("^[0-9]{2}$");
    return regex_match(age, regex);
}

bool isValidPhoneNumber(const std::string& phoneNumber) {
    // Формат номера телефона:
    // +7(967)645-7442
    // +79676567442
    // 79676557542
    // 89686557442
    // +7(967)-666-74-42
    regex regex1(R"(^\+?\d{1,2}\(?\d{3}\)?[-\d]{7,10}$)");
//    regex regex2(R"(^\+?\d{1,2}\(?\d{3}\)?[-\d]{7,10}$)");
    return std::regex_match(phoneNumber, regex1);
}

bool isValidAddress(const string& address) {
    // Формат адреса: g.XXX ul.XXX d.XXXXXX
    regex reg(R"(^g\.[A-Z]{3}, ul\.[A-Z][a-z]+, d\.[0-9][0-9]+ $)");
    return regex_match(address, reg);
}

int main() {
    int N;
    cin >> N;

    string str;
    for (int i = 0; i < N; ++i) {
        string full_name, age, phone, address;
        for (int j = 0; j < 3; ++j) {
            cin >> str;
            full_name += str + ' ';
        }

        cin >> age;

        cin >> phone;

        for (int j = 0; j < 3; ++j) {
            cin >> str;
            address += str + ' ';
        }

        cout << '\n' << isValidFullName(full_name);
        cout << '\n' << isValidAge(age);
        cout << '\n' << isValidAddress(address);
//        if (isValidFullName(full_name) and isValidAge(age) and isValidAddress(address)){
//            cout << "YES\n";
//        }
//        else{
//            cout << "NO\n";
//        }
    }

    return 0;
}
