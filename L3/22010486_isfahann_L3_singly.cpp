#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;

    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_item(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next_pointer = node;
            tail = node;
        }
    }

    void display_list() {
        Node* currNode = head;
        while (currNode != nullptr) {
            cout << currNode->name << " ";
            currNode = currNode->next_pointer;
        }
        cout << endl;
    }

    void delete_value(const string& name) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->name == name) {
                if (prev == nullptr) {
                    // Deleting head
                    head = curr->next_pointer;
                } else {
                    prev->next_pointer = curr->next_pointer;
                }

                if (curr == tail) {
                    tail = prev;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next_pointer;
        }
    }
};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Alice");

    LinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);

    std_list.display_list(); 

    std_list.delete_value("Ahmad");

    std_list.display_list(); 

    return 0;
}
