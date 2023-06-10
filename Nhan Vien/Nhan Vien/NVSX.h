#pragma once
#ifndef _NVSX
#define _NVSX
#include "NV.h"

class NVSX :public NV {
private:
	long luongcoban;
	int sosanpham;
public:
	NVSX(string="", string="", long=0, int=0);
	void SetLuongCoBan(long);
	void SetSoSanPham(int);
	long GetLuongCoBan();
	int GetSoSanPham();
	void Nhap();
	void Xuat();
	long Luong();
	friend istream& operator>>(istream&, NVSX&);
	friend ostream& operator<<(ostream&, NVSX&);
};

#endif // !_NVSX
