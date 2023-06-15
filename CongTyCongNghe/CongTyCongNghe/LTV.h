#pragma once
#ifndef _LTV
#define _LTV
#include "NhanVien.h"

class LTV : public NhanVien {
private:
	int sgl;
public:
	LTV(string = "", string = "", int = 0, string = "", string = "", long = 0, int = 0);
	void SetSGL(int);
	int GetSGL();
	void Nhap();
	void Xuat();
	long Luong();
	string GetLoai();
};


#endif // !_LTV

