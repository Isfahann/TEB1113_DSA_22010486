#include <iostream>
#include <string>
using namespace std;

class Queue {
private:
    static const int SIZE = 10; 
    string array[SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    void enqueue(string name) {
        if (count == SIZE) {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % SIZE;
        array[rear] = name;
        count++;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Delete element: " << array[front] << endl;
        front = (front + 1) % SIZE;
        count--;
    }

    void display_list() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue contents: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % SIZE;
            cout << array[index];
            if (i != count - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue("Ali");
    queue.enqueue("Ahmad");
    queue.enqueue("Alice");

    queue.display_list();

    queue.dequeue();
    queue.display_list();

    return 0;
}
