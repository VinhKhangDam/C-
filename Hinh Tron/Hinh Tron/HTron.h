#pragma once
#ifndef _Htron
#define _Htron
#include "Diem.h"

class Htron:public Diem {
private:
	Diem tam;
	double r;
public:
	~Htron();
	Htron(double = 0, double = 0, double = 0);
	Htron(const Diem&,double);
	Htron(const Htron&);
	void SetTam(const Diem&);
	void SetR(double);
	Diem GetTam() const;
	double GetR() const;
	void Nhap();
	void Xuat() const;
	void DiChuyen(double, double);
	bool KiemTraHopLe() const;
	double TinhChuVi() const;
	double TinhDienTich() const;
	friend istream& operator >> (istream&, Htron&);
	friend ostream& operator << (ostream&, const Htron&);
};

#endif // !_Htron
