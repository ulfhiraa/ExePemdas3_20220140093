#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Penerbit {
public: 
	string namaPenerbit;
};

class Pengarang {
public:
	string namaPengarang;
	vector<string> bukuDikarang; // vector 
	Penerbit* penerbit; // object dereference
};

class Buku {
public:
	string judulBuku;
	Pengarang* pengarang;
};

int main() {
	Penerbit gamaPress;
	gamaPress.namaPenerbit = "Gama Press";

	Penerbit intanPariwara;
	intanPariwara.namaPenerbit = "Intan Pariwara";

	Pengarang joko;
	joko.namaPengarang = "Joko";
	joko.penerbit = &gamaPress; // object reference  

	Pengarang lia;
	lia.namaPengarang = "Lia";
	lia.penerbit = &gamaPress;

	Pengarang giga;
	giga.namaPengarang = "Giga";
	giga.penerbit = &gamaPress;

	Pengarang asroni;
	asroni.namaPengarang = "Asroni\nGiga";
	asroni.penerbit = &intanPariwara;

	Buku fisika;
	fisika.judulBuku = "Fisika";
	fisika.pengarang = &joko;
	joko.bukuDikarang.push_back(fisika.judulBuku); // buat menaruh file dipaling belakang

	Buku algoritma;
	algoritma.judulBuku = "Algoritma";
	algoritma.pengarang = &joko;
	joko.bukuDikarang.push_back(algoritma.judulBuku);

	Buku basisdata;
	basisdata.judulBuku = "Basisdata";
	basisdata.pengarang = &lia;
	lia.bukuDikarang.push_back(basisdata.judulBuku);

	Buku dasarPemrograman;
	dasarPemrograman.judulBuku = "Dasar Pemrograman";
	dasarPemrograman.pengarang = &asroni;
	asroni.bukuDikarang.push_back(dasarPemrograman.judulBuku);

	Buku matematika;
	matematika.judulBuku = "Matematika";
	matematika.pengarang = &giga;
	giga.bukuDikarang.push_back(matematika.judulBuku);

	Buku multimedia1;
	multimedia1.judulBuku = "Multimedia 1";
	multimedia1.pengarang = &giga;
	giga.bukuDikarang.push_back(multimedia1.judulBuku);

	//1
	cout << "Daftar pengarang pada penerbit Gama Press: " << endl;
	for (Pengarang* pengarang : { &joko, &lia, &giga }) {
		if (pengarang->penerbit->namaPenerbit == "Gama Press") {
			cout << pengarang->namaPengarang << endl;
		}
	}

	//2
	cout << "\nDaftar pengarang pada penerbit Intan Pariwara : " << endl;
	for (Pengarang* pengarang : { &asroni, &giga }) {
		if (pengarang->penerbit->namaPenerbit == "Intan Pariwara") {
			cout << pengarang->namaPengarang << endl;
		}
	}

	//3
	cout << "\nDaftar penerbit yang diikuti Giga : " << endl;
	for (Penerbit* penerbit : { &gamaPress, &intanPariwara }) {
		if (penerbit->namaPenerbit == "Gama Press", "Intan Pariwara") {
			cout << penerbit->namaPenerbit << endl;
		}
	}

	// 4
	cout << "\nDaftar buku yang dikarang Joko : " << endl;
	for (string buku : joko.bukuDikarang) {
		cout << buku << endl;
	}

	//4 pt2
	cout << "\nDaftar buku yang dikarang Lia : " << endl;
	for (string buku : lia.bukuDikarang) {
		cout << buku << endl;
	}

	//5
	cout << "\nDaftar buku yang dikarang Asroni :" << endl;
	for (string buku : asroni.bukuDikarang) {
		cout << buku << endl;
	}

	//5 pt2
	cout << "\nDaftar buku yang dikarang Giga : " << endl;
	for (string buku : giga.bukuDikarang) {
		cout << buku << endl;
	}

	return 0;
}