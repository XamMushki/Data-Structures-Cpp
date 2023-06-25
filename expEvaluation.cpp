// Evaluating Expressions
#include <math.h>

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

// Prefix Notation
/*
Exp: + * + 2 3 3 - 4 7
    = + * (2+3) 3 (4-7)
    = + (5*3)  (-3)
    = 15 + (-3)
    = 12
 */

// Implementing Stack

struct stack {
    int data;
    stack *next;
};
void push(int data, stack **top) {
    stack *temp = new stack();
    temp->data = data;
    temp->next = NULL;
    if (*top == NULL) {
        *top = temp;
    } else {
        temp->next = *top;
        *top = temp;
    }
}
int pop(stack **top) {
    if (*top == NULL) {
        cout << "Invalid Expression, result not accurate.";
        return 1;
    }
    stack *temp = *top;
    int data = (*top)->data;
    *top = (*top)->next;
    delete (temp);
    return data;
}
// Evaluating Prefix Expression
int evaluatePrefix(string exp) {
    stack *top = NULL;
    int i = exp.size() - 1;  // length/number of elements in string expression
    // i is used to scan from right to left, i.e, i--
    for (i; i >= 0; i--) {
        if (isdigit(exp[i])) {
            // char at index i in 'exp' is a digit
            push(exp[i] - '0', &top);  // pushing integer of the value at index i

        } else {
            int operand1 = pop(&top);
            int operand2 = pop(&top);
            int new_operand = 0;
            switch (exp[i]) {
                case '+':
                    new_operand = operand1 + operand2;
                    break;
                case '-':
                    new_operand = operand1 - operand2;
                    break;
                case '*':
                    new_operand = operand1 * operand2;
                    break;
                case '/':
                    new_operand = operand1 / operand2;
                    break;
                case '^':
                    new_operand = pow(operand1, operand2);
                    break;
                default:
                    break;
            }
            push(new_operand, &top);
        }
    }
    return pop(&top);  // int
}
int evaluatePostfix(string exp) {
    stack *top = NULL;
    for (int i = 0; i < exp.size(); i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0', &top);
        } else {
            int op1 = pop(&top);
            int op2 = pop(&top);
            int new_op;
            switch (exp[i]) {
                case '+':
                    new_op = op2 + op1;
                    break;
                case '-':
                    new_op = op2 - op1;
                    break;
                case '*':
                    new_op = op1 * op2;
                    break;
                case '/':
                    new_op = op2 / op1;
                    break;
                case '^':
                    new_op = pow(op2, op1);
                    break;
                default:
                    break;
            }
            push(new_op, &top);
        }
    }
    return pop(&top);
}

bool isPostfix(string exp) {
    if (isdigit(exp[0]) && !isdigit(exp[exp.size() - 1])) {
        return true;
    }
    return false;
}
bool isPrefix(string exp) {
    if (!isdigit(exp[0]) && isdigit(exp[exp.size() - 1])) {
        return true;
    }
    return false;
}
int main() {
    // string exp = "++23*42";
    while (true) {
        string input;
        cout << "Enter Expresssion or enter 'exit' to exit\n>> ";
        cin >> input;
        if (input == "exit") {
            break;
        } else if (isPrefix(input)) {
            cout << "\nPrefix Evaluation" << endl;
            cout << input << " = " << evaluatePrefix(input) << endl;

        } else if (isPostfix(input)) {
            cout << "\nPostfix Evaluation" << endl;
            cout << input << " = " << evaluatePrefix(input) << endl;
        } else {
            cout << "Invalid expression!!!" << endl;
        }
        cout << endl;
    }

    return 0;
}