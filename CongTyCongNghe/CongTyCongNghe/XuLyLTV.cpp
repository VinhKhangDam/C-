#include "LTV.h"

LTV::LTV(string mnv,string ht,int tuoi,string sdt,string email,long lcb,int sgl): NhanVien(mnv,ht,tuoi,sdt,email,lcb),sgl(sgl) {}

void LTV::SetSGL(int sgl) { this->sgl = sgl; }

int LTV::GetSGL() { return sgl; }

void LTV::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so gio lam them: ";
	cin >> sgl;
}

void LTV::Xuat() {
	NhanVien::Xuat();
	cout << "So gio lam them: " << sgl << "\n" << "Luong cua nhan vien: " << Luong() << "\n";
}

long LTV::Luong() {
	return lcb + sgl * 200000;
}

string LTV::GetLoai() {
	return "LTV";
}