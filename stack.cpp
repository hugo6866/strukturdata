#include <iostream>
using namespace std;
#define MAX_STACK 8
int top = -1;
int stack[MAX_STACK];

bool isFull() {
    if (top == MAX_STACK - 1) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

void push(int data) {
    if (!isFull()) {
        top++;
        stack[top] = data;
        cout << stack[top] << " dimasukan kedalam stack!\n";
    }
    else {
        cout << "Stack penuh!\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "stack kosong\n";
    }
    else {
        cout << stack[top] << "\n";
    }
}
void pop() {
    if (!isEmpty()) {
        int e = stack[top];
        stack[top] = NULL;
        top--;
        cout << e << " dikeluarkan dari stack!\n";
    }
    else {
        cout << "Stack kosong!\n";
    }
}

void tampil() {
    cout << "Isi dari stack : \n";
    for (int i = 0; i <= top; i++) {
        cout << stack[i];
    }
    cout << "\n";
}
int main() {
    while (true) {
        int answer, angka = 0;
        cout << "Menu Stack \n";
        cout << "1. Push \n";
        cout << "2. Pop \n";
        cout << "3. Tampilkan \n";
        cout << "Input Pilihan : ";
        cin >> answer;

        switch (answer) {
        case 1:
            cout << "Input Angka : ";
            cin >> angka;
            push(angka);
            break;
        case 2:
            pop();
            break;
        case 3:
            tampil();
            break;
        default:
            break;
        }
    }

    return 0;
}