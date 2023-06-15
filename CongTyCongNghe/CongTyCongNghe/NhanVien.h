#pragma once
#ifndef _NhanVien
#define _NhanVien
#include <iostream>
#include <string>
using namespace std;

class NhanVien {
protected:
	string mnv, ht, sdt, email;
	int tuoi;
	long lcb;
public:
	NhanVien(string="",string="",int=0,string="",string="",long=0);
	~NhanVien();
	string GetMNV();
	string GetHT();
	string GetSDT();
	string GetEmail();
	int GetTuoi();
	long GetLCB();
	void SetHT(string);
	void SetSDT(string);
	void SetEmail(string);
	void SetTuoi(int);
	void SetLCB(long);
	virtual void SetSGL(int);
	virtual void SetSL(int);
	virtual int GetSGL();
	virtual int GetSL();
	virtual void Nhap();
	virtual void Xuat();
	virtual string GetLoai() = 0;
	virtual long Luong() = 0;
};

#endif // !_NhanVien

