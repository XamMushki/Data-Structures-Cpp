#include <iostream>
using namespace std;

struct Tree {
    int data;
    struct Tree *left, *right;
};

void insert(struct Tree **root) {
    struct Tree *temp = new Tree;
    struct Tree *new_node = new Tree;
    int data;
    cout << "enter data: ";
    cin >> data;

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    if (*root == NULL) {
        *root = new_node;
        cout << "Root Inserted" << endl;
    } else {
        temp = *root;
        while (true) {
            if (data < temp->data) {
                // go to left
                if (temp->left == NULL) {
                    temp->left = new_node;
                    return;
                }
                temp = temp->left;
            } else if (data > temp->data) {
                // go to right
                if (temp->right == NULL) {
                    temp->right = new_node;
                    return;
                }
                temp = temp->right;
            }
        }
    }
}
void preorder(struct Tree *root) {
    if (root != NULL) {
        cout << root->data << ", ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Tree *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << ", ";
        inorder(root->right);
    }
}
void postorder(struct Tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ", ";
    }
}
int main() {
    struct Tree *root = NULL;
    int choice;
    while (true) {
        cout << "1. Insert\n2. Traversal\n3. Exit\n>>>";
        cin >> choice;
        if (choice == 1) {
            insert(&root);
        } else if (choice == 2) {  // Traversal
            // preorder
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            // inorder
            cout << "inorder Traversal: ";
            inorder(root);
            cout << endl;
            // postorder
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << "\n"
                 << endl;

        } else {
            break;
        }
    }
    return 0;
}