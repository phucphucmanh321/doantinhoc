#include "Header.h">

void StartView(HashTable& ds){
	int choose;
	cout << "\n1. Dang nhap";
	cout << "\n2. Dang ky";
	cout << "\n3. Tim kiem";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		break;
	case 2:
		Dangki(ds);
		system("cls");
		StartView(ds);
		break;
	case 3:
		int a;
		cout << "Nhap so dien thoai khach hang: ";
		cin >> a;
		ViewInfo(find(ds, a));
		system("cls");
		StartView(ds);
		break;
	default:
		break;
	}
}