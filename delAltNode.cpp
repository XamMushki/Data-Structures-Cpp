// Delete alternate nodes in a linked list

#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
};

class LinkedList {
   public:
    void insert(int data, struct Node **head) {
        struct Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if (*head == NULL) {
            *head = temp;
            cout << data << " inserted as head." << endl;
        } else {
            Node *current = *head;
            while (true) {
                if (current->next == NULL) {
                    current->next = temp;
                    cout << data << " inserted." << endl;
                    return;
                }
                current = current->next;
            }
        }
    }

    void deleteAlternateNodes(struct Node **head) {
        if (*head == NULL || (*head)->next == NULL) {
            return;
        }
        Node *prev = *head;
        Node *current = (*head)->next;
        while (prev != NULL && current != NULL) {
            prev->next = current->next;
            prev = prev->next;
            if (prev != NULL) {
                current = prev->next;
            }
        }
    }

    void show(struct Node *head) {
        cout << "Linked List: ";
        while (head != NULL) {
            cout << head->data << ", ";
            head = head->next;
        }
        cout << endl;
    }
};
int main() {
    struct Node *head = NULL;
    // struct Node *tail = NULL;
    LinkedList ll = LinkedList();
    int data;
    while (true) {
        cout << "Enter \'-1\' when done." << endl;
        cout << "Enter Number: ";
        cin >> data;
        if (data == -1) {
            break;
        }
        ll.insert(data, &head);
    }
    ll.show(head);
    ll.deleteAlternateNodes(&head);
    cout << "After Deleting every alternate node: " << endl;
    ll.show(head);
    return 0;
}