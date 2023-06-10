#include "NVSX.h"

NVSX::NVSX(string ht,string ns,long lcb,int ssp): NV(ht,ns),luongcoban(lcb),sosanpham(ssp) {}

void NVSX::SetLuongCoBan(long lcb) {
	lcb = luongcoban;
}

void NVSX::SetSoSanPham(int ssp) {
	ssp = sosanpham;
}

long NVSX::GetLuongCoBan() {
	return luongcoban;
}

int NVSX::GetSoSanPham() {
	return sosanpham;
}

void NVSX::Nhap() {
	NV::Nhap();
	do {
		cout << "Nhap luong co ban cua nhan vien san xuat: ";
		cin >> luongcoban;
		cout << "Nhap so san pham nhan vien san xuat lam duoc: ";
		cin >> sosanpham;
	} while (luongcoban < 0 || sosanpham < 0);
}

void NVSX::Xuat() {
	NV::Xuat();
	cout << "\nLuong co ban cua nhan vien san xuat la: " << luongcoban << "\nSo san pham nguoi do lam duoc la: " << sosanpham
		<< "\nLuong cua nhan vien la: " << Luong() << endl;
}

long NVSX::Luong() {
	return luongcoban + sosanpham * 5000;
}

istream& operator>>(istream& in, NVSX& m) {
	m.NVSX::Nhap();
	return in;
}

ostream& operator<<(ostream& out, NVSX& m) {
	m.NV::Xuat();
	out << "\nLuong co ban cua nhan vien san xuat la: " << m.luongcoban << "\nSo san pham nguoi do lam duoc la: " << m.sosanpham
		<< "\nLuong cua nhan vien la: " << m.Luong() << endl;
	return out;
}