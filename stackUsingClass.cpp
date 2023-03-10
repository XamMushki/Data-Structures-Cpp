#include <iostream>
using namespace std;

// Stack using Array and Class

class Stack {
   private:
    int stack_size, top;
    int *stack;
    // Array name itself is a pointer, so we will treat this pointer as an array...
    // or
    // int *stack = new int[stack_size];  // This will allocate the memory dynamically
    /*  However, this 'raw' usage of 'new' is not
    recommended as you must use delete to recover
    the allocated memory.

    delete[] array;
    Better use vector<>
    */
   public:
    Stack() {
        cout << "Enter Stack Size: ";
        cin >> stack_size;
        top = stack_size - 1;  // used to keep track of the top of the stack
    }
    void push(int data) {
        if (top >= 0) {
            stack[top] = data;
            top--;
        } else {
            cout << "\nStack Overflow!!!\nTry pop()" << endl;
        }
    }
    void pop() {
        if (top < stack_size - 1) {
            top++;  // data is simply overwritten next time push() is called.
        } else {
            cout << "\nStack Underflow!!!\nTry push(int)" << endl;
        }
    }
    void printStack() {
        cout << "\nStack: " << endl;
        for (int i = top + 1; i < stack_size; i++) {
            cout << "  " << stack[i] << endl;
        }
    }
};

int main() {
    Stack s;
    int option = 0;
    do {
        cout << "\nChoose Operation: (1/2/3) \n1. push()\n2. pop()\n3. "
                "exit\nOption: ";
        cin >> option;
        switch (option) {
            case 1:
                int data;
                cout << "Enter Element: ";
                cin >> data;
                s.push(data);
                s.printStack();
                break;
            case 2:
                s.pop();
                s.printStack();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "\nIncorrect Option Choosen!!!" << endl;
                break;
        };
    } while (option != 3);

    return 0;
}