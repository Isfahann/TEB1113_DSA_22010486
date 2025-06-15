#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    string contact;  
    string email;
};

int main() {
    Student s[5];
    
    for (int i = 0; i < 5; i++) {
        cout << "Enter your id: ";
        cin >> s[i].id;
        cin.ignore();  // clears newline after integer input

        cout << "Enter your name: ";
        getline(cin, s[i].name);

        cout << "Enter your contact: ";
        getline(cin, s[i].contact);

        cout << "Enter your email: ";
        getline(cin, s[i].email);

        cout << endl;
    }

    for (int i = 0; i < 5; i++) {
        cout << "*****************************\n";
        cout << "Student " << i + 1 << ":\n";
        cout << "ID: " << s[i].id << "\n";
        cout << "Name: " << s[i].name << "\n";
        cout << "Contact: " << s[i].contact << "\n";
        cout << "Email: " << s[i].email << "\n";
        cout << "*****************************\n";
    }

    return 0;
}
