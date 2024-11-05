#include "Header.h"

void login(HashTable ds) {
	Nodeptr p = new NODE;
	cout << "Nhap SDT: ";
	cin >> p->KH.maKH;
	cout << "Mat khau: ";
	cin >> p->KH.matkhau;
	p->link = NULL;

	if (find(ds, p))
		GiaoDien();
	else cout << "Sai mat khau";
}
void GiaoDien() {
	int choose;
	cout << "\n1. Dang nhap";
	cout << "\n2. Dang ky";
	cout << "\n3. Tim kiem";
	cout << "\n4. Save file";
	cout << "\n5. Open file";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	
}