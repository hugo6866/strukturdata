#include <iostream>
using namespace std;

#define MAX 6 //Max of nodes & stack

struct Tree {
    int data;
    Tree* left;
    Tree* right;
};

struct Stack{
    Tree* data[MAX];
    int top;
};

Tree *leaf, *newNode, *root = NULL;
Stack stack;

bool isFull(){
    return (stack.top == MAX) ? true : false;
}

void push(Tree *value){
    if(!isFull()){
        stack.top++;
        stack.data[stack.top] = value;
    }
    else{
        cout << "stack penuh!";
    }
}


void initStack(){
    stack.top = -1;
}
bool isEmpty(){
    return (stack.top == -1) ? true : false;
}

void pop(){
    if(isEmpty()){
        cout << "stack masih kosong!\n";
        return ;
    }

    //stack.data[stack.top] = NULL;
    stack.top--;
}
void printStack(){
    if(isEmpty()){
    cout << "stack masih kosong!";
    return;
    }
    for(int i = 0 ; i <= stack.top;i++){
       // cout << stack.data[i] << " ";
    }
    cout << "\n";
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

Tree* createTree(int data) {
    newNode = new Tree();
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

void dfs(Tree *current){
    //Inisialisasi stack
    initStack();
    //Masukan kedalam stack
    push(current);

    //Jika tidak kosong pop
    while (!isEmpty()) {
        Tree *node = stack.data[stack.top];
        pop();
        //Print data dari node
        cout << node->data << " ";

        //Jika kanan tidak kosong
        if (node->right != NULL) {
            //push
            push(node->right);
        }
        
        //jika kiri tidak kosong
        if (node->left != NULL) {
            //pushh
            push(node->left);
        }
    }
}
int main(){
    initStack();
    leaf = createTree(0);
    addLeft(leaf, 1);
    addLeft(leaf->left, 4);
    addRight(leaf, 2);
    addRight(leaf->right, 3);
    addLeft(leaf->right, 5);
    addLeft(leaf->right->left, 6);
    dfs(leaf);
    return 0;
}