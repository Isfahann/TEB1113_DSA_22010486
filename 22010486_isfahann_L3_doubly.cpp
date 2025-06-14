#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add_item(const string& name) {
        Node* node = new Node(name);
        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    void display_list() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->name << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void delete_value(const string& name) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (curr == head) {
                    head = curr->next;
                    if (head) head->prev = nullptr;
                } else {
                    curr->prev->next = curr->next;
                }

                if (curr == tail) {
                    tail = curr->prev;
                    if (tail) tail->next = nullptr;
                } else if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                }

                delete curr;
                return;
            }

            curr = curr->next;
        }
    }
};

int main() {
    DoublyLinkedList std_list;

    std_list.add_item("Ali");
    std_list.add_item("Ahmad");
    std_list.add_item("Alice");

    std_list.display_list(); 

    std_list.delete_value("Ahmad");

    std_list.display_list(); 

    return 0;
}
