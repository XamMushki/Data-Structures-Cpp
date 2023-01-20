#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void createNode(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            // push node at end as tail.
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
    void printLinkedList()
    {
        cout << "Doubly Linked List: ";
        Node *current_node = head;
        while (current_node != NULL)
        {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << "\n"
             << endl;
    }
};

int main()
{
    DoublyLinkedList dll;
    dll.createNode(1);
    dll.createNode(2);
    dll.createNode(3);
    dll.createNode(4);
    dll.createNode(5);
    dll.createNode(6);
    dll.printLinkedList();
    return 0;
}