#include <iostream>
using namespace std;

// node
struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

Tree* leaf, * leaf2, * leaf3, *nodeBaru, * root = NULL;

void preOrder(Tree* current) {
    if (current != NULL) {
        cout << " " << current->data;
        preOrder(current->left);
        preOrder(current->right);
    }
}

void inOrder(Tree* current) {
    if (current != NULL) {
        inOrder(current->left);
        cout << " " << current->data;
        inOrder(current->right);
    }
}

void postOrder(Tree* current) {
    if (current != NULL) {
        postOrder(current->left);
        postOrder(current->right);
        cout << " " << current->data;
    }
}

void addRight(Tree* current, int data) {
    if (current->right != NULL) {
        cout << "Sisi kanan sudah ada\n";
    }
    else {
        nodeBaru = new Tree();
        nodeBaru->data = data;
        nodeBaru->left = NULL;
        nodeBaru->right = NULL;
        current->right = nodeBaru;
    }

}

void addLeft(Tree* current, int data) {
    if (current->left != NULL) {
        cout << "Sisi kiri sudah ada\n";
    }
    else {
        nodeBaru = new Tree();
        nodeBaru->data = data;
        nodeBaru->left = NULL;
        nodeBaru->right = NULL;
        current->left = nodeBaru;
    }
}

Tree* createTree(int data) {
    nodeBaru = new Tree();
    nodeBaru->data = data;
    nodeBaru->left = NULL;
    nodeBaru->right = NULL;
    return nodeBaru;
}

int main() {

    leaf = createTree(5);
    addLeft(leaf, 4);
    addRight(leaf, 3);
    preOrder(leaf);
    cout << "\n";
    inOrder(leaf);
    cout << "\n";
    postOrder(leaf);
    return 0;
}