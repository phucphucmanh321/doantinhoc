#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;
const int MAX = 10;
struct Khachhang {
	int maKH;
	string tenkh;
	string taikhoan;
	string matkhau;
};
struct NODE {
	Khachhang KH;
	NODE* link;
};
typedef NODE* Nodeptr;
struct HashTable {
	Nodeptr HashTable[MAX];
};
int hash_funct(int data);
void insert(HashTable& table, int data);
Nodeptr find(HashTable table, int data);
bool CheckPhoneNum(int a);
void Dangki(HashTable& ds);

//View
void ViewInfo(Nodeptr p);
void StartView(HashTable &ds);