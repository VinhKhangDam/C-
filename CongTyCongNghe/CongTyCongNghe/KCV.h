#pragma once
#ifndef _KCV
#define _KCV
#include "NhanVien.h"

class KCV : public NhanVien {
private:
	int sl;
public:
	KCV(string = "", string = "", int = 0, string = "", string = "", long = 0, int = 0);
	void SetSL(int);
	int GetSL();
	void Nhap();
	void Xuat();
	long Luong();
	string GetLoai();
};


#endif // !_LTV


