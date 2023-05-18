#pragma once
#ifndef _Diem
#include <iostream>
#include <math.h>
using namespace std;
class Diem {
	private:
		double x,y;
	public:
		~Diem();
		Diem(double = 0, double = 0);
		Diem(const Diem&);
		void SetX(double);
		void SetY(double);
		void SetXY(double, double);
		double GetX() const;
		double GetY() const;
		void Nhap();
		void Xuat() const;
		void DiChuyen(double, double);
		bool KiemTraTrung(const Diem&) const;
		double TinhKhoangCach(const Diem&) const;
		Diem DiemDoiXung() const;
		bool KiemTraTamGiacHopLe(const Diem&, const Diem&) const;
		bool KiemTraTamGiacHopLe(double, double, double) const;
		double TinhChuVi(const Diem&, const Diem&) const;
		double TinhDienTich(const Diem&, const Diem&) const;
		string PhanLoai(const Diem&, const Diem&) const;
		friend istream& operator >>(istream& , Diem& );
		friend ostream& operator <<(ostream& , const Diem&);
};
#endif 
