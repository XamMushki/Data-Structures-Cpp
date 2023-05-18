#include <iostream>
using namespace std;

struct stack {
    int data;
    stack *next;
};

bool isEmpty(struct stack **top) {
    return (*top == NULL);
}
void push(struct stack **top, int data) {
    struct stack *temp = new stack;
    temp->data = data;
    temp->next = NULL;

    if (*top == NULL) {
        *top = temp;
    } else {
        temp->next = *top;
        *top = temp;
    }
}
void pop(struct stack **top) {
    if (isEmpty(top)) {
        cout << "Stack Underflow!" << endl;
        return;
    }
    struct stack *toFreeMem = *top;

    int popped = (*top)->data;
    *top = (*top)->next;

    cout << popped << endl;

    delete toFreeMem;  // to free the allocated memory;
}
int main() {
    struct stack *top = NULL;
    push(&top, 2);
    push(&top, 4);
    push(&top, 6);
    push(&top, 8);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    pop(&top);
    push(&top, 10);
    push(&top, 12);
    push(&top, 14);
    pop(&top);
    pop(&top);
    pop(&top);

    return 0;

    delete top;
}