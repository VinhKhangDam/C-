#pragma once
#ifndef _NV
#define _NV
#include <iostream>
#include<math.h>
#include <string>
using namespace std;

class NV {
protected:
	string name;
	string ngaysinh;
public:
	NV(string = "", string = "");
	~NV();
	void SetName(string);
	void SetNgaySinh(string);
	string GetName();
	string GetNgaySinh();
	void Nhap();
	void Xuat();
	friend istream& operator>>(istream&, NV&);
	friend ostream& operator<<(ostream&, const NV&);
};

#endif // !_NV
