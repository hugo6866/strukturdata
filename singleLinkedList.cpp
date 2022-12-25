#include <iostream>
using namespace std;

struct Mahasiswa {
	string NIM;
	string nama;
	int umur;
	Mahasiswa* next;
};


Mahasiswa *mhsBaru, *head, *cur;
void buatLinkedList(string, string, int);
void printAll();
void tambahDepan(string, string, int);
void tambahBelakang(string, string, int);void hapusIndex(int);

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
	mhsBaru->next = NULL;
	head = mhsBaru;
}

bool isEmpty() {
	return (head == NULL) ? true : false;
}


void printAll() {
	cur = head;
	int num = 1;
	while (cur != NULL) {
		cout << "Data ke " << num << "\n";
		cout << "NIM : " << cur->NIM << endl;
		cout << "Nama : " << cur->nama << endl;
		cout << "Umur : " << cur->umur << endl;
		cur = cur->next;
		num++;
	}
}

void deleteAll() {
	Mahasiswa* bantu, * hapus;
	bantu = head;
	while (bantu != NULL) {
		hapus = bantu;
		bantu = bantu->next;
		delete hapus;
	}
	head = NULL;
}

void hapusDepan() {
	Mahasiswa* hapus;
	if (isEmpty() == 0) {
		if (head->next != NULL) {
			hapus = head;
			head = head->next;
			delete hapus;
		}
		else {
			head = NULL;
		}
	}
	else cout << "Masih kosong\n";
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
			delete hapus;
		}
		else {
			head = NULL;
		}
	}
	else printf("Masih kosong\n");
}

void tambahDepan(string NIM, string nama, int umur) {
	mhsBaru = new Mahasiswa();
	mhsBaru->NIM = NIM;
	mhsBaru->nama = nama;
	mhsBaru->umur = umur;
	mhsBaru->next = head;
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
	mhsBaru->next = NULL;
	cur->next = mhsBaru;
}

void tambahIndex(int index, string NIM, string nama, int umur) {
	Mahasiswa* temp = new Mahasiswa();
	temp->NIM = NIM;
	temp->nama = nama;
	temp->umur = umur;
	temp->next = NULL;
	
	if (index == 0) { // add to front
		tambahDepan(NIM, nama, umur);
		return;
	}
	
	// find node at index
	Mahasiswa* cur = head;
	for (int i = 0; i < index - 1; i++) {
		if (cur == NULL) { 
			cout << "Index tidak valid!\n";
			return;
		}
		cur = cur->next;
	}
	
	temp->next = cur->next;
	cur->next = temp;
}

void hapusIndex(int index) {
	Mahasiswa* hapus;
	int i;
	if (isEmpty() == 0) {
		if (index == 1) {
			hapus = head;
			head = head->next;
			delete hapus;
		}
		else {
			Mahasiswa* bantu = head;
			for (i = 1; i < index-1; i++) {
				if (bantu->next == NULL) {
					break;
				}
				bantu = bantu->next;
			}
			if (bantu->next != NULL) {
				hapus = bantu->next;
				bantu->next = hapus->next;
				delete hapus;
			}
		}
	}
	else printf("Masih kosong\n");
}

