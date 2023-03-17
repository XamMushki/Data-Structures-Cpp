#include <iostream>
using namespace std;

// Stack using Array and Class
const int MAX_SIZE = 5;

class Stack {
   private:
    int stack_size, top;
    int stack[MAX_SIZE];

   public:
    Stack() {
        stack_size = MAX_SIZE;
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