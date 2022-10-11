/*
A11.2021.13937
Hafizh Hugo Harman
*/
#include<iostream>
using namespace std;
#define MAX 8

struct Antrian {
    int data[MAX];
    int head;
    int tail;
};

Antrian antre;
void create();
bool isEmpty();
bool isFull();
void enqueue(int);
int dequeue();
void tampil();
void clear();

int main() {
    //iniliasisasi queue antrian
    create();
    int pilihan = 0;
    do{

        cout << "====================================\n";
        cout << "Masukan pilihan\n";
        cout << "====================================\n";
        cout << "1. Masukan data kedalam queue (Enqueue)\n";
        cout << "2. Keluarkan data dari queue (Dequeue)\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan\t: ";
        int data = 0;
        cin >> pilihan;
        switch (pilihan) {
        case 1:
            cout << "Input Data : ";
            cin >> data;
            enqueue(data);
            break;
        case 2:
            //Mengeluarkan data dari awal data/index (first in first out/FIFO)
            dequeue();
            break;
        case 3:
            cout << "Tampilan data : ";
            tampil();
            break;
        case 4:
            clear();
        case 5:
            break;
        default:
            cout << "Pilihan tidak ditemukan! \n";
            break;
        }
    } while (pilihan != 5);

    return 0;
}

void create() {
    antre.head = antre.tail = -1;
}


bool isEmpty() {
    if (antre.tail == -1) {
        return true;
    }
    else
    {   
        return false;
    }
}

bool isFull() {
    if (antre.tail == MAX - 1) {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int data) {
    if (isEmpty()) {
        antre.head = antre.tail = 0;
        //Tambahkan kedalam data ADT
        antre.data[antre.tail] = data;
    }
    else if (isFull()) {
        cout << "Data dalam queue penuh!\n";
    }
    else
    {
        antre.tail++;
        antre.data[antre.tail] = data;
        cout << data << " dimasukkan ke antrian\n";
    }
}

int dequeue() {
    int i;
    int e = antre.data[antre.head];
    cout << "Antrian " <<  e << " dikeluarkan !\n";
    for (i = antre.head; i < antre.tail ; i++) {
        antre.data[i] = antre.data[i + 1];
    }
    antre.tail--;
    return e;
}

void clear() {
    antre.head = antre.tail = -1;
    cout << "Data telah dibersihkan!\n";
}

void tampil() {
    if (!isEmpty()) {
        for (int i = antre.head; i <= antre.tail; i++) {
            cout << antre.data[i];
        }
        cout << "\n";
    }
    else {
        cout << "Data kosong\n";
    }
}
