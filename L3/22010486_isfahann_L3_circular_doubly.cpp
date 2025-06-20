#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next_pointer;
    Node* prev_pointer;

    Node(string name) {
        this->name = name;
        this->next_pointer = nullptr;
        this->prev_pointer = nullptr;
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
            head->next_pointer = head;
            head->prev_pointer = head;
        } else {
            node->prev_pointer = tail;
            node->next_pointer = head;
            tail->next_pointer = node;
            head->prev_pointer = node;
            tail = node;
        }
    }

    void display_list() {
        if (head == nullptr) return;

        Node* currNode = head;
        do {
            cout << currNode->name << " --> ";
            currNode = currNode->next_pointer;
        } while (currNode != head);
        cout << head->name << endl;
    }

    void display_reverse_list() {
        if (tail == nullptr) return;

        Node* currNode = tail;
        do {
            cout << currNode->name << " --> ";
            currNode = currNode->prev_pointer;
        } while (currNode != tail);
        cout << tail->name << endl;
    }

};

int main() {
    Node* node1 = new Node("Ali");
    Node* node2 = new Node("Ahmad");
    Node* node3 = new Node("Alice");
    Node* node4 = new Node("Hamza");

    LinkedList std_list;

    std_list.add_item(node1);
    std_list.add_item(node2);
    std_list.add_item(node3);
    std_list.add_item(node4);

    cout << "Forward: ";
    std_list.display_list();  

    cout << "Reverse: ";
    std_list.display_reverse_list();  

    return 0;
}

