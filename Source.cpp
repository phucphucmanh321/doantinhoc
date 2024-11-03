#include "Header.h"

int hash_funct(int data) {
	return data % 10;
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
Nodeptr find(HashTable table, int a) {
	int index = hash_funct(a);
	Nodeptr p = table.HashTable[index];
	while (p != NULL) {
		if (p->KH.maKH == a)
		{
			return p;
		}
		p = p->link;
	}
	return NULL;
}
void ViewInfo(Nodeptr p) {
	cout << "\nSDT: " << p->KH.maKH;
	cout << "\nHo ten khach hang: " << p->KH.tenkh;
	cout << "\nTai khoan: " << p->KH.taikhoan;
	cout << "\nMat khau: " << p->KH.matkhau;
	system("pause");
}
bool CheckPhoneNum(string a) {
	if (a.length() != 9) return false;
	for (char ch : a)
		if (!isdigit(ch))
			return false;
	return true;
}
void Dangki(HashTable &ds) {
	Nodeptr kh = new NODE;
	cout << "So dien thoai: ";
	cin>>kh->KH.maKH;
	/*while (!CheckPhoneNum(to_string(kh->KH.maKH)))
	{
		system("cls");
		cout << "Nhap lai so dien thoai 10 so: ";
		cin >> kh->KH.maKH;
		cout << "\n";
	}*/
	cout << "Nhap ho ten: ";
	cin >> kh->KH.tenkh;
	cout << "Nhap ten tai khoan: ";
	cin >> kh->KH.taikhoan;
	cout << "Nhap mat khau: ";
	cin >> kh->KH.matkhau;
	insert(ds, kh);
	cout << "\nThem thanh cong !!!";
	system("pause");
}