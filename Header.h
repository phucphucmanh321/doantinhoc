#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 10;
struct Khachhang {
	char maKH[11];
	char tenkh[50];
	char matkhau[50];
};
struct NODE {
	Khachhang KH;
	NODE* link;
};
typedef NODE* Nodeptr;
struct HashTable {
	Nodeptr HashTable[MAX];
};
void GiaoDien();
void login(HashTable ds);
void Xuat(HashTable ds);
int hash_funct(char data);
void insert(HashTable& table, Nodeptr kh);
bool find(HashTable table, Nodeptr p);
bool CheckPhoneNum(const char a[]);
void Dangki(HashTable& ds);
void ghiStructVaoFile(const char* filename, HashTable ds);
void docStructTuFile(const char* filename, HashTable& ds);
void initializeHashTable(HashTable& ds);
//View
void ViewInfo(Nodeptr p);
void StartView(HashTable &ds);