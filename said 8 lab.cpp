#include <iostream> 
using namespace std; 
// Node structure for linked list 
struct Node { 
int data; 
Node* next; 
}; 
// Queue structure using linked list 
class Queue { 
private: 
    Node* front; 
    Node* rear; 
    int size;  // Keep track of the number of elements 
    static const int MAX_SIZE = 5;  // Maximum size of the queue 
 
public: 
    // Constructor 
    Queue() { 
        front = nullptr; 
        rear = nullptr; 
        size = 0; 
    } 
 
    // Destructor to free memory 
    ~Queue() { 
        while (front != nullptr) { 
            Node* temp = front; 
            front = front->next; 
            delete temp; 
        } 
    } 
 
    // Check if the queue is empty 
    bool isEmpty() { 
        return (front == nullptr); 
    } 
 
    // Check if the queue is full 
    bool isFull() { 
        return (size == MAX_SIZE); 
    } 
 
    // Function to add an element at the rear of the queue 
    void enqueue(int value) { 
        if (isFull()) { 
            cout << "Queue Overflow! Cannot insert more elements." << endl; 
            return; 
        } 
 
        Node* newNode = new Node; 
        newNode->data = value; 
        newNode->next = nullptr; 
 
        if (rear == nullptr) {  // If the queue is empty 
            front = rear = newNode; 
        } else { 
            rear->next = newNode; 
            rear = newNode; 
        } 
        size++; 
    } 
 
    // Function to remove an element from the front of the queue 
    int dequeue() { 
        if (isEmpty()) { 
            cout << "Queue Underflow! No elements to remove." << endl; 
            return -1; 
        } 
 
        Node* temp = front; 
        int data = front->data; 
        front = front->next; 
 
        if (front == nullptr) {  // If the queue becomes empty 
            rear = nullptr; 
        } 
 
        delete temp; 
        size--; 
        return data; 
    } 
 
    // Function to display the queue elements 
    void display() { 
        if (isEmpty()) { 
            cout << "Queue is empty!" << endl; 
            return; 
        } 
 
        Node* temp = front; 
        cout << "Queue elements: "; 
        while (temp != nullptr) { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } 
        cout << endl; 
    } 
}; 
 
int main() { 
    Queue queue1, queue2; 
    int choice, value; 
 
    do { 
        cout << "\nMenu:\n"; 
        cout << "1. Enqueue to Queue 1\n"; 
        cout << "2. Dequeue from Queue 1 and Enqueue to Queue 2\n"; 
        cout << "3. Dequeue from Queue 2\n"; 
        cout << "4. Display Queue 1\n"; 
        cout << "5. Display Queue 2\n"; 
        cout << "6. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
        case 1: 
            if (!queue1.isFull()) { 
                cout << "Enter the value to enqueue in Queue 1: "; 
                cin >> value; 
                queue1.enqueue(value); 
            } else { 
                cout << "Queue 1 is full!" << endl; 
            } 
            break; 
 
        case 2: 
            if (!queue1.isEmpty()) { 
                value = queue1.dequeue(); 
                cout << "Dequeued " << value << " from Queue 1." << endl; 
                if (!queue2.isFull()) { 
                    queue2.enqueue(value); 
                    cout << "Enqueued " << value << " to Queue 2." << endl; 
                } else { 
                    cout << "Queue 2 is full! Cannot enqueue." << endl; 
                } 
            } 
            break; 
 
        case 3: 
            if (!queue2.isEmpty()) { 
                value = queue2.dequeue(); 
                cout << "Dequeued " << value << " from Queue 2." << endl; 
            } 
            break; 
 
        case 4: 
            cout << "Queue 1: "; 
            queue1.display(); 
            break; 
 
        case 5: 
            cout << "Queue 2: "; 
            queue2.display(); 
            break; 
 
        case 6: 
            cout << "Exiting..." << endl; 
            break; 
 
        default: 
            cout << "Invalid choice! Try again." << endl; 
        } 
    } while (choice != 6); 
 
    return 0; 
} 

