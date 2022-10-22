#include <iostream>
using namespace std;
#define MAXSTACK 35
#define stackpenuh true
#define stackalfabet false
struct pesan {
	char data[MAXSTACK];
	int top;
};

pesan stackPenuh;
pesan stackAlfabet;

void fixPesan(string);
void initStack(bool);
void tampil(bool);
bool isFull(bool);
bool isEmpty(bool);
void push(char,bool);
void pop(bool);
bool isAlphabet(char);

int main() {
	/*
Si Fulan mendapat pesan dari temannya, namun pesan tersebut rusak seperti yang tertera sebagai berikut
H**AL***O**AP***AK*A**B*****A*R****

Dengan menggunakan konsep stack, bantulah Fulan menghilangkan tanda * sehingga akan muncul tulisan HALOAPAKABAR.
Ketentuan:
Jika ketemu *, maka lakukan pop, jika ketemu alfabet, lakukan push.

Hint:
1. Pesan yang diterima Fulan bisa dianggap sebagai stack yang sudah penuh
2. Buatlah satu stack tambahan untuk menampung alfabet
3. Tampilkan stack yang menampung alfabet
*/
	string text = "H**AL***O**AP***AK*A**B*****A*R***";
	//inisialisasi stack penuh dan stack penampung alfabet
	initStack(stackpenuh);
	initStack(stackalfabet);
	fixPesan(text);
	tampil(stackalfabet);

	return 0;
}

void fixPesan(string text) {
	int sizePesan = text.size();
	while (sizePesan--) {
		push(text[stackPenuh.top], stackpenuh);
	}
	while (!isEmpty(stackpenuh) && stackPenuh.data[stackPenuh.top] == '*') {
		//Pop dalam stack hanya bisa mengambil bagian atas dari stack
		pop(stackpenuh);
	}
	int index = 1;
	for (char ch : stackPenuh.data)
	{
		if (index == stackPenuh.top) break;
		push(ch, stackalfabet);
		if (ch == '*' || !isAlphabet(ch))
		{
			pop(stackalfabet);
		}
	}
}
void initStack(bool stackType) {
	auto stack = (stackType) ? stackPenuh : stackAlfabet;
	stack.top = -1;
}

bool isAlphabet(char chr) {
	int z = (int)chr;
	//Jika huruf A-Z & jika huruf a-z (ascii character number)
	return ((z >= 65 && z <= 90) || (z >= 97 && z <= 122)) ? true : false;
}
bool isFull(bool stackType) {
	return (((stackType) ? stackPenuh.top : stackAlfabet.top) == MAXSTACK - 1) ? true : false;
}

bool isEmpty(bool stackType) {
	return (((stackType) ? stackPenuh.top : stackAlfabet.top) == -1) ? true : false;
}

void push(char huruf, bool stackType) {
	auto &stack = (stackType) ? stackPenuh : stackAlfabet;
	if(isFull(stackType)){
		cout << "stack penuh!\n";
	}
	else {
		stack.top++;
		stack.data[stack.top] = huruf;
		//cout << huruf << " dimasukan kedalam " << ((stackType) ? "stackpenuh(pesan)" : "stackalfabet") << "!\n";
	}
}

void pop(bool stackType) {
	auto &stack = (stackType) ? stackPenuh : stackAlfabet;
	if (isEmpty(stackType)) {
		cout << "stack kosong !\n";
	}
	else {
		stack.data[stack.top] = NULL;
		stack.top--;
	}
}

void tampil(bool stackType) {
	auto &stack = (stackType) ? stackPenuh : stackAlfabet;
	cout << "Isi dari stack : \n";
	for (int i = 0; i <= stack.top; i++) {
		cout << stack.data[i];
	}
	cout << "\n";
}
