#include <iostream>
#include <string>
using namespace std;

// Student class  
class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    // Constructor 
    Student() : reg_no(0), st_name(""), cgpa(0.0) {}

    // Function to input student details 
    void input() {
        cout << "Enter Registration Number: ";
        cin >> reg_no;
        cin.ignore();  // Clear the newline character from the input buffer
        cout << "Enter Student Name: ";
        getline(cin, st_name);
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    // Function to output student details 
    void output() const {
        cout << "----------------------------------" << endl;
        cout << "Student Details:" << endl;
        cout << "Registration Number: " << reg_no << endl;
        cout << "Name: " << st_name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "----------------------------------" << endl;
    }
};

// Stack class to implement stack operations 
class Stack {
private:
    Student* arr; // Pointer to dynamic array of Student objects 
    int top; // Index of top of stack 
    int capacity; // Total capacity of stack 

public:
    // Constructor to initialize stack with user-defined size 
    Stack(int size) {
        arr = new Student[size];
        capacity = size;
        top = -1; // Stack is initially empty 
    }

    // Destructor to free dynamically allocated memory 
    ~Stack() {
        delete[] arr;
    }

    // Function to add an object to the stack (push) 
    void push(const Student& s) {
        if (top == capacity - 1) {
            cout << "Error: Stack Overflow! Cannot add more students." << endl;
            return;
        }
        arr[++top] = s; // Add student to stack 
        cout << "Success: Student pushed onto the stack." << endl;
    }

    // Function to remove an object from the stack (pop) 
    void pop() {
        if (top == -1) {
            cout << "Error: Stack Underflow! No students to remove." << endl;
            return;
        }
        cout << "Success: Student removed from the stack." << endl;
        arr[top--].output(); // Display and remove student 
    }

    // Function to check if the stack is empty 
    bool isEmpty() const {
        return top == -1;
    }

    // Function to check if the stack is full 
    bool isFull() const {
        return top == capacity - 1;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;
    cin.ignore();  // Clear newline character after reading size

    Stack stack(size); // Create stack of user-defined size 
    Student s;
    int choice;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a Student" << endl;
        cout << "2. Remove a Student" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!stack.isFull()) {
                s.input();  // Input student details 
                stack.push(s);  // Push student to stack 
            } else {
                cout << "Error: Stack is full! Cannot add more students." << endl;
            }
            break;
        case 2:
            stack.pop();  // Pop student from stack 
            break;
        case 3:
            cout << "Exiting the program. Thank you!" << endl;
            break;
        default:
            cout << "Error: Invalid choice. Please try again!" << endl;
        }
    } while (choice != 3);

    return 0;
}

