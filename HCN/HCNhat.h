#pragma once
#include "Diem.h"
#ifndef _HCNHAT
class HCNhat {
	private:
		Diem A, B;
	public:
		~HCNhat();
		HCNhat(double = 1, double = 0, double = 0, double = 1);
		HCNhat(const Diem&, const Diem& );
		void SetA(const Diem&);
		void SetB(const Diem&);
		void SetAB(const Diem&, const Diem&);
		Diem GetA() const;
		Diem GetB() const;
		void Nhap();
		void Xuat() const;
		void DiChuyenHCN(double, double);
		bool KiemTraHopLe()	const;
		double TinhChuVi() const;
		double TinhDienTich() const;
		double GetRong() const;
		double GetDai() const;
		friend istream& operator >> (istream&, HCNhat&);
		friend ostream& operator << (ostream&, const HCNhat&);
};
#endif
