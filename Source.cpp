﻿#include "Header.h"

int hash_funct(const char* data) {
	return data[9] - '0';
}
void initializeHashTable(HashTable& ds) {
	for (int i = 0; i < MAX; i++)
		ds.HashTable[i] = NULL;
}
void insert(HashTable& table, Nodeptr kh) {
	int index = hash_funct(kh->KH.maKH);
	Nodeptr p = new NODE;
	p = kh;
	if (table.HashTable[index] == NULL)
	{
		table.HashTable[index] = p;
		return;
	}
	p->link = table.HashTable[index];
	table.HashTable[index] = p;
}
bool find(HashTable table,Nodeptr p) {
	int Index = hash_funct(p->KH.maKH);
	Nodeptr p1 = table.HashTable[Index];
	while (p1 != NULL) {
		if (strcmp(p1->KH.tenkh, p->KH.tenkh)&&strcmp(p1->KH.matkhau,p->KH.matkhau))
		{
			return true;
		}
		p1 = p1->link;
	}
	return false;
}
void ViewInfo(Nodeptr p) {
	cout << "\nSDT: " << p->KH.maKH;
	cout << "\nHo ten khach hang: " << p->KH.tenkh;
	cout << "\nMat khau: " << p->KH.matkhau;
	system("pause");
}
bool CheckPhoneNum(const char a[]) {
	for (int i = 0; i < 10; i++)
		if (!isdigit(a[i]))
			return false;
	return true;
}
void Xuat(HashTable ds) {
	for (int i = 0; i < MAX; i++) {
		Nodeptr p = ds.HashTable[i];
		cout << "\nDanh sach tai chi so: " << i << ":\n";
		if (p == NULL) {
			cout << "khong co du lieu tai chi so nay.\n";
			continue;
		}
		while (p != NULL) {
			cout << p->KH.maKH << " " << p->KH.tenkh << " " << p->KH.matkhau << endl;
			p = p->link;
		}
	}
}
void Dangki(HashTable &ds) {
	Nodeptr kh = new NODE;
	kh->link = NULL;
	//cin.ignore();
	cout << "So dien thoai: ";
	cin>>kh->KH.maKH;
	while (!CheckPhoneNum(kh->KH.maKH))
	{
		system("cls");
		cout << "Nhap lai so dien thoai 10 so: ";
		cin >> kh->KH.maKH;
	}
	cin.ignore();
	cout << "Nhap ho ten: ";
	cin.getline(kh->KH.tenkh, 50);
	cin.ignore();
	cout << "Mat khau: ";
	cin >> kh->KH.matkhau;
	cin.ignore();
	insert(ds, kh);
}

void ghiStructVaoFile(const char* filename, HashTable ds) {
	ofstream ofs;
	ofs.open(filename, ios::binary);
	if (!ofs.is_open())
		cout << "\nKhong the ghi file !";
	for (int i = 0; i < MAX; i++)
	{
		int count = 0;
		Nodeptr p = ds.HashTable[i];
		Nodeptr temp = p;
		while (temp != NULL) {
			count++;
			temp = temp->link;
		}
		ofs.write((char*)&count, sizeof(count));
		while (p != NULL)
		{
			ofs.write((char*)&p->KH, sizeof(Khachhang));
			p = p->link;
		}
	}
	ofs.close();
	cout << "\nGhi thanh cong!! ";
	system("pause");
}

void docStructTuFile(const char* filename, HashTable &ds) {
	ifstream ifs;
	ifs.open(filename, ios::binary);
	if (!ifs.is_open())
		cout << "\nKhong doc duoc file !!";
	for (int i = 0; i < MAX; i++) {
		int count = 0;
		ifs.read((char*)&count, sizeof(count));
		for (int j = 0; j < count; j++)
		{
			Khachhang kh;
			ifs.read((char*)&kh, sizeof(Khachhang));
			Nodeptr p = new NODE;
			p->KH = kh;
			p->link = NULL;
			insert(ds, p);
		}
	}
	ifs.close();
	cout << "\nDoc thanh cong !!";
	system("pause");
}