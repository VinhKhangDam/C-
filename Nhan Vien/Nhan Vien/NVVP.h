#pragma once
#ifndef _NVVP
#define _NVVP
#include "NV.h"

class NVVP :public NV {
private:
	int songay;
public:
	NVVP(string = "", string = "", int = 0);
	void SetSoNgay(int);
	int GetSoNgay();
	void Nhap();
	void Xuat();
	long Luong();
	friend istream& operator>>(istream&, NVVP&);
	friend ostream& operator<<(ostream&, NVVP&);
};

#endif // !_NVVP
