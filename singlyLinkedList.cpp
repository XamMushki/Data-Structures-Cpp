#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void createNode(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }
    void printLinkedList()
    {
        Node *current_node = head;
        cout << "Linked List: ";
        while (current_node != NULL)
        {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    void deleteFirst()
    {
        if (head != NULL)
        {
            cout << "Head node '" << head->data << "' deleted." << endl;
            head = head->next;
        }
        else
        {
            cout << "Nothing to delete at head!!!" << endl;
        }
    }
    void deleteLast()
    {
        if (tail != NULL)
        {
            cout << "Tail node '" << tail->data << "' deleted." << endl;
            ;
            Node *current_node = head;
            while (head != NULL)
            {
                if (current_node->next == tail)
                {
                    current_node->next = NULL;
                    tail = current_node;
                    break;
                }
                current_node = current_node->next;
            }
        }
        else
        {
            cout << "Nothing to delete at tail!!!" << endl;
        }
    }
    void deleteNodeAt(int index)
    {
        if (head != NULL)
        {
            Node *current_node = head;
            int i = 0;
            if (i == index)
            {
                deleteFirst();
            }

            while (i < index)
            {
                if (current_node == NULL)
                {
                    cout << "No node found at Index '" << index << "'." << endl;
                    break;
                }
                if (i == index - 1)
                {
                    cout << "Node at index '" << index << "' with value '"
                         << current_node->next->data << "' deleted." << endl;
                    current_node->next = current_node->next->next;
                }
                current_node = current_node->next;
                i++;
            }
        }
        else
        {
            cout << "Nothing to delete, no Node available!!!" << endl;
        }
    }

    void pushNodeAtEnd(int data)
    {
        // same as the createNode() function.
        createNode(data);
    }
    void pushNodeAtStart(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            // if part is same as createNode
            // else{} part is different.

            new_node->next = head;
            head = new_node;
            cout << "New Node '" << head->data << "' pushed as head node." << endl;
        }
    }
    void pushNodeAtIndex(int index, int data)
    {
        Node *current_node = head;
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;

        int i = 0;
        if (head == NULL)
        {
            cout << "Head Node not found, new node create as head." << endl;
            createNode(data);
        }
        else if (index == 0)
        {
            pushNodeAtStart(data);
        }
        else
        {

            while (current_node != NULL)
            {
                if (i == index - 1) //-1 because we cannot move backwards, as there (no prev. option only next.).
                {
                    new_node->next = current_node->next;
                    current_node->next = new_node;
                    break;
                }
                if (current_node->next == NULL)
                {
                    // that is, index out of range, storing the node as tail.
                    cout << "Index out of range, storing node as the tail, at index '" << i + 1 << "'." << endl;
                    pushNodeAtEnd(data);
                    break;
                }

                current_node = current_node->next;
                i++;
            }
        }
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.createNode(1);
    sll.createNode(2);
    sll.createNode(3);
    sll.createNode(4);
    sll.createNode(5);
    sll.createNode(6);
    sll.createNode(7);
    sll.printLinkedList();

    sll.deleteFirst();
    sll.printLinkedList();

    sll.deleteLast();
    sll.printLinkedList();

    sll.deleteNodeAt(13); // No Node at index 13

    sll.deleteNodeAt(3);
    sll.printLinkedList();

    sll.pushNodeAtStart(13);
    sll.pushNodeAtStart(24);
    sll.printLinkedList();

    sll.pushNodeAtEnd(11);
    sll.printLinkedList();

    sll.pushNodeAtIndex(5, 5);
    sll.printLinkedList();

    sll.pushNodeAtIndex(0, 5);
    sll.printLinkedList();

    sll.pushNodeAtIndex(10, 14);
    sll.printLinkedList();
    return 0;
}