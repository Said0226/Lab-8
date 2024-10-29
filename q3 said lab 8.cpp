#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    static const int MAX_SIZE = 5;

public:
    Queue() : front(NULL), rear(NULL), size(0) {}
    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty() { return front == NULL; }
    bool isFull() { return size == MAX_SIZE; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        Node* newNode = new Node{value, NULL};
        if (rear) rear->next = newNode;
        else front = newNode;
        rear = newNode;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return -1;
        }
        Node* temp = front;
        int data = front->data;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
        size--;
        return data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (Node* temp = front; temp; temp = temp->next)
            cout << temp->data << " ";
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            value = queue.dequeue();
            if (value != -1) cout << "Dequeued: " << value << endl;
            break;
        case 3:
            queue.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}

