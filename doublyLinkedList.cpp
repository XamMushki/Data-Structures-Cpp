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
    void printReverseLinkedList()
    {
        Node *current = tail;
        cout << "Reverse Doubly LL: ";
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->prev; // current = NULL, if current->prev = NULL, i.e., head->prev = NULL
        }
        cout << "\n"
             << endl;
    }
    void pushAtStart(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        cout << head->data << " pushed at Start/Head." << endl;
    }
    void pushAtEnd(int data)
    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
        cout << tail->data << " pushed at End/Tail." << endl;
    }
    void pushAtIndex(int index, int data)

    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL)
        {
            cout << "No HEAD node found!!!" << endl;
            cout << data << " pushed at start/head." << endl;
            head = new_node;
            tail = new_node;
        }
        else if (index == 0)
        {
            cout << data << " pushed at index 0." << endl;
            pushAtStart(data);
        }
        else
        {
            int i = 0;
            Node *current = head;
            while (i < index)
            {
                if (current != NULL)
                {
                    if (i == index)
                    {
                        // consider 3 nodes n1 newnode currentnode
                        // n1->next = newnode
                        // newnode->prev = n1
                        // newnode->=currentnode.
                        new_node->prev = current->prev;
                        current->prev->next = new_node;
                        new_node->next = current;
                        cout << data << " pushed at Index '" << i << "'." << endl;
                        break;
                    }
                    current = current->next;
                    i++;
                }
                else
                {
                    cout << "Index out of range, storing node as tail, at index '" << i << "'." << endl;
                    pushAtEnd(data);
                    break;
                }
            }
        }
    }

    void deleteHead()
    {
        if (head != NULL)
        {
            cout << head->data << "/head node deleted." << endl;
            head->next->prev = NULL;
            head = head->next;
        }
        else
        {
            cout << "No node found!!!" << endl;
        }
    }
    void deleteTail()
    {
        if (head != NULL)
        {
            cout << tail->data << "/tail node deleted." << endl;
            tail->prev->next = NULL;
            tail = tail->prev;
        }
        else
        {
            cout << "No node found!!!" << endl;
        }
    }
    void deleteAtIndex(int index)
    {
        if (head != NULL)
        {
            if (index == 0)
            {
                deleteHead();
                cout << "At Index 0" << endl;
            }
            else
            {
                int i = 0;
                Node *current = head;
                while (current != NULL)
                {
                    if (i == index)
                    {
                        cout << current->data << "/Node deleted at index " << index << endl;
                        if (current->next == NULL)
                        {
                            deleteTail();
                        }
                        else
                        {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }
                        i = -1;
                        break;
                    }

                    current = current->next;
                    i++;
                }
                if (i = -1)
                {
                    cout << "Index out of range, No data found at index " << index
                         << ", try 'createNode(int)'" << endl;
                }
            }
        }

        else
        {
            cout << "No node found!!!" << endl;
        }
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

    dll.printReverseLinkedList();

    dll.pushAtStart(0);
    dll.printLinkedList();

    dll.pushAtEnd(7);
    dll.printLinkedList();

    dll.pushAtIndex(4, 9);
    dll.printLinkedList();

    dll.pushAtIndex(0, 3);
    dll.printLinkedList();

    dll.pushAtIndex(14, 3);
    dll.printLinkedList();

    dll.deleteHead();
    dll.printLinkedList();

    dll.deleteTail();
    dll.printLinkedList();

    dll.deleteAtIndex(0);
    dll.printLinkedList();

    dll.deleteAtIndex(6);
    dll.printLinkedList();

    dll.deleteAtIndex(9);
    dll.printLinkedList();
    return 0;
}