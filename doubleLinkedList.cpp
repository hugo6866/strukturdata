#include <iostream>
using namespace std;

struct Mahasiswa {
	string NIM;
	string nama;
	int umur;
	Mahasiswa* prev; 
	Mahasiswa* next;
};

Mahasiswa *mhsBaru, *head, *cur;

void buatLinkedList(string, string, int);
void printAll();
void tambahDepan(string, string, int);
void tambahBelakang(string, string, int);
void deleteAll();
void hapusIndex(int);
void tambahIndex(int,string,string,int);
void hapusDepan();
void hapusBelakang();

int main() {
	int answer = 0;
	string NIM, nama;
	int umur;
	int index;
	do {
		cout << "========= Menu Linkedlist =========\n";
		cout << "1. Buat Linkedlist\n";
		cout << "2. Tambah depan \n";
		cout << "3. Tambah belakang \n";
		cout << "4. Hapus depan\n";
		cout << "5. Hapus belakang\n";
		cout << "6. Tambah index\n";
		cout << "7. Hapus index\n";
		cout << "8. Tampilkan data\n";
		cout << "9. Keluar\n";
		cin >> answer;
		switch (answer) {
		case 1:
			
			cout << "Buat linkedlist\n";
			cout << "NIM : ";
			cin >> NIM;
			cout << "Nama : ";
			cin >> nama;
			cout << "Umur : ";
			cin >> umur;
			buatLinkedList(NIM, nama, umur);
			break;
		case 2:
			
			cout << "Tambah depan\n";
			cout << "NIM : ";
			cin >> NIM;
			cout << "Nama : ";
			cin >> nama;
			cout << "Umur : ";
			cin >> umur;
			tambahDepan(NIM, nama, umur);
			break;
		case 3:
			cout << "Tambah belakang\n";
			cout << "NIM : ";
			cin >> NIM;
			cout << "Nama : ";
			cin >> nama;
			cout << "Umur : ";
			cin >> umur;
			tambahBelakang(NIM, nama, umur);
			break;
		case 4:
			cout << "Hapus depan\n";
			hapusDepan();
			break;
		case 5:
			cout << "Hapus belakang\n";
			hapusBelakang();
			break;
		case 6:
			cout << "Tambah index\n";
			cout << "Index: ";
			cin >> index;
			cout << "NIM : ";
			cin >> NIM;
			cout << "Nama : ";
			cin >> nama;
			cout << "Umur : ";
			cin >> umur;
			tambahIndex(index, NIM, nama, umur);
			break;
		case 7:
			cout << "Hapus index\n";
			cout << "Index: ";
			cin >> index;
			hapusIndex(index);
			break;
		case 8:
			cout << "Tampilkan data\n";
			printAll();
			break;
        case 9:
			return 0;
			break;
		default:
			cout << "Menu tidak ditemukan!\n";
		}
	} while (answer != 9);
	return 0;
}

void buatLinkedList(string NIM, string nama, int umur) {
	mhsBaru = new Mahasiswa();
	mhsBaru->NIM = NIM;
	mhsBaru->nama = nama;
	mhsBaru->umur = umur;
	mhsBaru->prev = NULL; 
	mhsBaru->next = NULL;
	head = mhsBaru;
	cur = mhsBaru;
}

bool isEmpty() {
	return (head == NULL) ? true : false;
}

void printAll() {
	cur = head;
	int num = 1;
	while (cur != NULL) {
		cout << "Data ke " << num << "\n";
		cout << "NIM: " << cur->NIM << "\n";
		cout << "Nama: " << cur->nama << "\n";
		cout << "Umur: " << cur->umur << "\n";
		cout << "\n";
		cur = cur->next;
		num++;
	}
}

void tambahDepan(string NIM, string nama, int umur) {
	mhsBaru = new Mahasiswa();
	mhsBaru->NIM = NIM;
	mhsBaru->nama = nama;
	mhsBaru->umur = umur;
	
	mhsBaru->prev = NULL; 
	mhsBaru->next = head; 
	if (head != NULL) { 
		head->prev = mhsBaru; 
	}
	head = mhsBaru; 
}
void tambahBelakang(string NIM, string nama, int umur) {
	cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	mhsBaru = new Mahasiswa();
	mhsBaru->NIM = NIM;
	mhsBaru->nama = nama;
	mhsBaru->umur = umur;
	mhsBaru->prev = cur;
	mhsBaru->next = NULL;
	cur->next = mhsBaru;
	cur = mhsBaru;
}

void deleteAll() {
	cur = head;
	while (cur != NULL) {
		Mahasiswa* temp = cur;
		cur = cur->next;
		delete temp;
	}
	head = NULL;
	cur = NULL;
}

void hapusDepan() {
	if (isEmpty()) {
		cout << "Linkedlist kosong!\n";
	}
	else {
		Mahasiswa* temp = head;
		head = head->next; 
		if (head != NULL) { 
			head->prev = NULL; 
		}
		delete temp;
	}
}

void hapusBelakang() {
	Mahasiswa* hapus, * bantu;
	if (isEmpty() == 0) {
		if (head->next != NULL) {
			bantu = head;
			while (bantu->next->next != NULL) {
				bantu = bantu->next;
			}
			hapus = bantu->next;
			bantu->next = NULL;
			hapus->prev = NULL;
			delete hapus;
			cur = bantu;
		}
		else {
			head = NULL;
			cur = NULL;
		}
	}
	else printf("Masih kosong\n");
}


void tambahIndex(int index, string NIM, string nama, int umur) {
	Mahasiswa* temp = new Mahasiswa();
	temp->NIM = NIM;
	temp->nama = nama;
	temp->umur = umur;
	
	if (index == 0) { 
		tambahDepan(NIM, nama, umur);
		return;
	}
	
	Mahasiswa* cur = head;
	for (int i = 0; i < index; i++) {
		if (cur == NULL) { 
			cout << "Index tidak valid!\n";
			return;
		}
		cur = cur->next;
	}
	
	temp->prev = cur->prev; 
	temp->next = cur; 
	cur->prev->next = temp; 
	cur->prev = temp; 
}

void hapusIndex(int index) {
	if (index == 0) {
		hapusDepan();
		return;
	}
	
	Mahasiswa* cur = head;
	for (int i = 0; i < index; i++) {
		if (cur == NULL) { 
			cout << "Index tidak valid!\n";
			return;
		}
		cur = cur->next;
	}
	
	cur->prev->next = cur->next; 
	if (cur->next != NULL) { 
		cur->next->prev = cur->prev; 
	}
	
	delete cur;
}

