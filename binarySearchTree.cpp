#include <iostream>
using namespace std;

struct tree {
    int data;
    struct tree *left, *right;
};
void insert(struct tree **root, int data) {
    struct tree *new_node = new tree;
    struct tree *current = new tree;
    current = *root;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL) {
        *root = new_node;
    } else {
        while (true) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = new_node;
                    return;
                }
                // that is, current has a left child.
                current = current->left;
            } else {
                // that is, new data is greater than current->data, there is no need to write the condition
                if (current->right == NULL) {
                    current->right = new_node;
                    return;
                }
                current = current->right;
            }
        }
    }
}

// RECURSIVE TRAVERSALS
void preorderRecursive(struct tree *root) {
    if (root != NULL) {
        cout << root->data << ", ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}
void inorderRecursive(struct tree *root) {
    if (root != NULL) {
        preorderRecursive(root->left);
        cout << root->data << ", ";
        preorderRecursive(root->right);
    }
}
void postorderRecursive(struct tree *root) {
    if (root != NULL) {
        preorderRecursive(root->left);
        preorderRecursive(root->right);
        cout << root->data << ", ";
    }
}

// NON RECUSIVE TRAVERSALS
struct stack {
    // Here *tree_node is the data.
    struct tree *tree_node;
    struct stack *next;
};
void push(struct stack **top, struct tree *node) {
    struct stack *temp = new stack;
    temp->tree_node = node;
    temp->next = NULL;
    if (*top == NULL) {
        *top = temp;
        return;
    } else {
        temp->next = *top;
        *top = temp;
        return;
    }
}
struct tree *pop(struct stack **top) {
    struct stack *temp_stack;
    struct tree *temp_tree;
    temp_stack = *top;
    *top = (*top)->next;
    temp_tree = temp_stack->tree_node;

    // return a tree node.
    return temp_tree;
};

// Non Recursive Preorder Traversal using stack
void preorderNonRecursive(struct tree *root) {
    struct stack *top = NULL;
    struct tree *current = root;
    struct tree *temp_tree;
    while (current != NULL || top != NULL) {
        while (current != NULL) {
            cout << current->data << ", ";
            push(&top, current);
            current = current->left;
        }
        // current is now NULL
        if (top != NULL) {
            current = pop(&top);
            current = current->right;
        }
    }
}
// Non Recursive Inorder Traversal
void inorderNonRecursive(struct tree *root) {
    struct stack *top = NULL;
    struct tree *current = root;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            push(&top, current);
            current = current->left;
        }
        if (top != NULL) {
            current = pop(&top);
            cout << current->data << ", ";
            current = current->right;
        }
    }
}
void postorderNonRecursive(struct tree *root) {
    struct stack *top = NULL;
    struct tree *current = root;
    int d;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            d = current->data;
            push(&top, current);
            current = current->left;
        }
        if (top != NULL) {
            current = pop(&top);
            if (current->right == NULL) {
                cout << current->data << ", ";
                current = NULL;
            } else if (d > current->data) {
                cout << current->data << ", ";
                current = NULL;
            } else {
                push(&top, current);
                current = current->right;
            }
        }
    }
}
// Calculate Height of a binary tree.
//Recursive
int calculateHeight(struct tree *root) {
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    // Return the maximum height between the left and right subtrees, plus 1 for the current node
    return 1 + max(leftHeight, rightHeight);
}
// Non Recursive

// Delete Tree Node Using Non Recursive Preorder Traversal
void deleteTreeNode(struct tree **root, int data) {
    struct tree *current = *root;
    struct stack *top = NULL;
    struct tree *parent = NULL;
    bool isLeftChild = false;

    while (current != NULL || top != NULL) {
        while (current != NULL) {
            if (current->data == data) {
                // Case 1: Node to delete is a leaf node.
                if (current->left == NULL && current->right == NULL) {
                    if (parent == NULL) {
                        // Deleting root node.
                        *root = NULL;
                    } else if (isLeftChild) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    delete current;  // free memory.
                    return;
                }
                // Case 2: Node to delete has a left child but not a right child.
                else if (current->left != NULL && current->right == NULL) {
                    if (parent == NULL) {
                        *root = current->left;
                    } else if (isLeftChild) {
                        parent->left = current->left;
                    } else {
                        parent->right = current->left;
                    }
                    delete current;
                    return;
                }
                // Case 3: Node to delte has a right child but not a left child.
                else if (current->left == NULL && current->right != NULL) {
                    if (parent == NULL) {
                        *root = current->right;
                    } else if (isLeftChild) {
                        parent->left = current->right;
                    } else {
                        parent->right = current->left;
                    }
                    delete current;
                    return;
                }
                // Case 4: Node to delete has both left and right children
                struct tree *successor = current->right;
                struct tree *successorParent = current;
                while (successor->left != NULL) {
                    successorParent = successor;
                    successor = successor->left;
                }

                if (successorParent == current) {
                    // The right child of the current node is the successor
                    successor->left = current->left;
                    if (parent == NULL) {
                        // Deleting the root node
                        *root = successor;
                    } else if (isLeftChild) {
                        parent->left = successor;
                    } else {
                        parent->right = successor;
                    }
                } else {
                    // Connect the left subtree of the successor node to its parent
                    successorParent->left = successor->right;
                    // Connect the left and right subtrees of the current node to the successor
                    successor->left = current->left;
                    successor->right = current->right;
                    if (parent == NULL) {
                        // Deleting the root node
                        *root = successor;
                    } else if (isLeftChild) {
                        parent->left = successor;
                    } else {
                        parent->right = successor;
                    }
                }

                delete current;
                return;
            }

            push(&top, current);
            parent = current;
            if (data < current->data) {
                current = current->left;
                isLeftChild = true;
            } else {
                current = current->right;
                isLeftChild = false;
            }
        }

        if (top != NULL) {
            current = pop(&top);
        }
    }
}
int main() {
    struct tree *root = NULL;
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 3);
    insert(&root, 9);
    insert(&root, 10);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 8);
    insert(&root, 11);
    insert(&root, 12);
    insert(&root, 13);
    // Recursive Traversal
    cout << "Recursive Traversal" << endl;
    cout << "Preorder: ";
    preorderRecursive(root);
    cout << endl;
    cout << "Inorder: ";
    inorderRecursive(root);
    cout << endl;
    cout << "PostOrder: ";
    postorderRecursive(root);
    cout << endl;

    // Non Recursive Traversal
    cout << "Non Recursive Traversal" << endl;
    cout << "Preorder: ";
    preorderNonRecursive(root);
    cout << endl;
    cout << "Inorder: ";
    inorderNonRecursive(root);
    cout << endl;
    cout << "Postorder: ";
    postorderNonRecursive(root);
    cout << endl;

    cout<<"Height of the Tree: "<<calculateHeight(root)<<" "<<endl;

    cout << "Deleting 3" << endl;
    cout << "Tree: ";
    deleteTreeNode(&root, 3);
    preorderNonRecursive(root);

    cout << endl;
    cout << "Deleting 9" << endl;
    cout << "Tree: ";
    deleteTreeNode(&root, 9);
    preorderNonRecursive(root);
    cout << endl;

    return 0;
}