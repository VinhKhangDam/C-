#pragma once
#ifndef _CongTy
#define _CongTy
#include "NhanVien.h"
#include "LTV.h"
#include "KCV.h"

class CongTy {
private:
	NhanVien** nv;
	int sluong;
public:
	CongTy();
	~CongTy();
	int GetSLuong();
	void Nhap();
	NhanVien* Nhap1();
	void Xuat();
	long LuongTrungBinh();
	void NhanVienCoLuongThapHon();
	void TimNhanVienCoMucLuongToiThieu(long);
};

#endif // !_CongTy
