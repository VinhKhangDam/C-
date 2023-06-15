#include "KCV.h"

KCV::KCV(string mnv, string ht, int tuoi, string sdt, string email, long lcb, int sl) : NhanVien(mnv, ht, tuoi, sdt, email, lcb), sl(sl) {}

void KCV::SetSL(int sl) { this->sl = sl; }

int KCV::GetSL() { return sl; }

void KCV::Nhap() {
	NhanVien::Nhap();
	cout << "Nhap so loi phat hien duoc: ";
	cin >> sl;
}

void KCV::Xuat() {
	NhanVien::Xuat();
	cout << "So loi phat hien duoc: " << sl << "\n" << "Luong cua nhan vien: " << Luong() << "\n";
}

long KCV::Luong() {
	return lcb + sl * 50000;
}

string KCV::GetLoai() {
	return "KCV";
}