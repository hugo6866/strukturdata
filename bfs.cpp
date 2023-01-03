#include <iostream>
#include <unordered_set>

using namespace std;

#define MAX 6 //Max node

struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

struct Antrian {
    Tree* data[MAX];
    int head;
    int tail;
};

Tree* newNode, * current, * leaf, * root = NULL;

void addRight(Tree* current, int data) {
    if (current->right != NULL) {
        cout << "Kanan tidak kosong!\n";
        return;
    }
    newNode = new Tree();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    current->right = newNode;

}

void addLeft(Tree* current, int data) {
    if (current->left != NULL) {
        cout << "Kiri tidak kosong!\n";
        return;
    }
    newNode = new Tree();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    current->left = newNode;
}
Tree* createTree(int data) {
    newNode = new Tree();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Antrian antre;

void createQueue() {
    antre.head = antre.tail = -1;
}

bool isEmpty() {
    return (antre.tail == -1) ? true : false;
}

bool isFull() {
    return (antre.tail == MAX - 1) ? true : false;
}
void enqueue(Tree *data) {
    if (isEmpty()) {
        antre.head = antre.tail = 0;
    }
    else if (isFull()) {
        cout << "queue penuh!\n";
        return;
    }
    else {
        antre.tail++;
    }
    antre.data[antre.tail] = data;

}

void dequeue() {
    for (int i = antre.head; i < antre.tail; i++) {
        antre.data[i] = antre.data[i + 1];
    }
    antre.tail--;
}


void bfs(Tree* current) {
    //Inisialisasi queue
    createQueue();
    //Masukan root kedalam queue
    enqueue(current);
    //Buat variabel boolean untuk visited
    bool visited[MAX];
    for (int i = 0; i < MAX; i++) visited[i] = false;

    //Masukan data pertama menjadi visited
    visited[current->data] = true;
    cout << "BFS Spanning Tree : ";
    // While queue belum kosong
    while (!isEmpty()) {
        Tree* current = antre.data[antre.head];
        // Dequeue paling depan
        dequeue();
        // Jika node kiri bukan NULL dan belum dikunjungi
        if (current->left != NULL && !visited[current->left->data]) {
            //Print data kiri
            cout << current->left->data << " ";
            //Masukan data kiri kedalam queue
            enqueue(current->left);
            //Masukan data kiri sebagai sudah dikunjungi/visited
            visited[current->left->data] = true;
        }
        // Jika node kanan bukan NULL dan belum dikunjungi
        if (current->right != NULL && !visited[current->right->data]) {
            //Print data kanan
            cout << current->right->data << " ";
            //Masukan node kedalam queue
            enqueue(current->right);
            //Masukan data kanan sebagai sudah dikunjungi/visited
            visited[current->right->data] = true;
        }
    }
}

int main() {
    leaf = createTree(0);
    addLeft(leaf, 1);
    addLeft(leaf->left, 4);
    addRight(leaf, 2);
    addRight(leaf->right, 3);
    addLeft(leaf->right, 5);
    addLeft(leaf->right->left, 6);
    bfs(leaf);
    return 0;
}