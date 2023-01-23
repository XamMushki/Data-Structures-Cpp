// Binary Search Tree using Linked List
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
private:
    Node *root;

public:
    BinarySearchTree()
    {
        root = NULL;
    }
    void insert(int data)

    {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;

        if (root == NULL)
        {
            root = new_node;
            cout << data << " inserted as root." << endl;
        }
        else
        {
            Node *current = root;
            while (current != NULL)
            {
                // data goes to right
                if (data < current->data)
                {

                    if (current->left != NULL)
                    {
                        current = current->left;
                    }
                    else
                    {
                        // that is, no 'left child' of the current node.
                        current->left = new_node;
                        cout << "left ";
                        break;
                    }
                }

                // greater than or equal then goes to right
                else
                {
                    if (current->right != NULL)
                    {
                        current = current->right;
                    }
                    else
                    {
                        // that is, no 'right child' of the current node.
                        current->right = new_node;
                        break;
                    }
                }
            }
            cout << data << " inserted." << endl;
        }
    }
    void printPreorder(Node *current)
    {
        if (current == NULL)
        {
            // cout << " r ";
            return;
        }

        cout << current->data << " ";

        printPreorder(current->left);

        // cout << "here "

        printPreorder(current->right);
    }
    void printInorder(Node *current)
    {
        if (current == NULL)
        {
            return;
        }
        printInorder(current->left);

        cout << current->data << " ";

        printInorder(current->right);
    }
    void printPostorder(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        printPostorder(current->left);

        printPostorder(current->right);

        cout << current->data << " ";
    }
    void printBST()
    {
        cout << "\nPreOrder Traversal: ";
        printPreorder(root);
        cout << endl;

        cout << "\nInOrder Traversal: ";
        printInorder(root);
        cout << endl;

        cout << "\nPostOrder Traversal: ";
        printPostorder(root);
        cout << endl;
    }
    void deleteItem(int item)
    {
        // delete the item in tree.
    }
    void search(int item)
    {
        // search the item.
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insert(13);
    bst.insert(5);
    bst.insert(15);
    bst.insert(2);
    bst.insert(1);
    bst.insert(7);
    bst.insert(16);
    bst.insert(14);

    bst.printBST();
    return 0;
}
