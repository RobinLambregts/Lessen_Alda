#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* leftchild;
    Node* rightchild;

    // Constructor to initialize a node with a given value
    Node(int val) : value(val), leftchild(nullptr), rightchild(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    // Helper function for inserting a node into the binary tree
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->leftchild = insert(node->leftchild, value);
        } else {
            node->rightchild = insert(node->rightchild, value);
        }
        return node;
    }

    // Helper function for in-order traversal
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->leftchild);
            cout << node->value << " ";
            inorderTraversal(node->rightchild);
        }
    }

    // Helper function for searching a node in the binary tree
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->leftchild, value);
        } else {
            return search(node->rightchild, value);
        }
    }

public:
    // Constructor to initialize the binary tree with an empty root
    BinaryTree() : root(nullptr) {}

    // Public method to insert a value into the binary tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to perform in-order traversal
    void inorderTraversal() {
        inorderTraversal(root);
        cout << endl;
    }

    // Public method to search for a value in the binary tree
    bool search(int value) {
        return search(root, value);
    }

    int min_value(){
        Node *current = root;
        return minimum(root)->value;
    }

    Node* minimum(Node* node) {
        return node->leftchild ? minimum(node->leftchild) : node;
    }

    void between(Node* node, vector<int> &values, int min, int max) {
        if (node == nullptr) {return;}
        if (node->value > min) {
            between(node->leftchild, values, min, max);
        }
        if (node->value >= min && node->value <= max) {
            values.push_back(node->value);
        }
        if (node->value < max) {
            between(node->rightchild, values, min, max);
        }
    }

    vector<int> interval(int min, int max) {
        vector<int> result;

        Node *current = root;
        between(current, result, min, max);

        return result;
    }

    bool trueTree(Node* node, int min, int max) {
        if (node == nullptr) {
            return true;
        }

        if (node->value <= min || node->value >= max) {
            return false;
        }

        return trueTree(node->leftchild, min, node->value) &&
                trueTree(node->rightchild, node->value, max);
    }

    bool trueTree() {
        return trueTree(root, INT_MIN, INT_MAX);
    }
};

int main() {
    BinaryTree tree;

    // Insert some values into the binary tree
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(17);

    Node min = tree.min_value();
    cout << "min value: " << min.value << endl;

    vector<int> intervalResult = tree.interval(6, 16);
    cout << "interval result (6, 16): ";
    for (int i = 0; i < intervalResult.size(); i++) {
        cout << intervalResult[i] << " ";
    }

    cout << endl;

    cout << "boom check: " << tree.trueTree() << endl;

    return 0;
}