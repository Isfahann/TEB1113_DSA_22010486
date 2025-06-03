/*
Name : Muhammad Isfahann Syakir bin Shahrum
ID : 22010486
*/
#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int id;
    int contact;
    string email;
};

int main() {
    Student s[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter your id: ";
        cin >> s[i].id;

        cin.ignore(); 
        cout << "Enter your name: ";
        getline(cin, s[i].name);

        cout << "Enter your contact: ";
        cin >> s[i].contact;

        cin.ignore(); 
        cout << "Enter your email: ";
        getline(cin, s[i].email);

        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << "*****************************";
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "ID: " << s[i].id << "\n";
        cout << "Name: " << s[i].name << "\n";
        cout << "Contact: " << s[i].contact << "\n";
        cout << "Email: " << s[i].email << "\n";
        cout << "*****************************";
    }
}