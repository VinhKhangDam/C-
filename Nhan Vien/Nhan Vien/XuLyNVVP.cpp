#include "NVVP.h"

NVVP::NVVP (string ht,string ns,int sn):NV(ht,ns),songay(sn) {}

void NVVP::SetSoNgay(int sn) {
	sn = songay;
}

int NVVP::GetSoNgay() {
	return songay;
}

void NVVP::Nhap() {
	NV::Nhap();
	do {
		cout << "Nhap so ngay lam viec cua nhan vien: ";
		cin >> songay;
	} while (songay < 0 || songay>365);
}

void NVVP::Xuat() {
	NV::Xuat();
	cout << "\nSo ngay lam viec cua nhan vien la: " << songay << "\nLuong cua nhan vien la: " << Luong() << endl;
}

long NVVP::Luong() {
	return songay * 100000;
}

istream& operator>>(istream& in, NVVP& m) {
	m.NVVP::Nhap();
	return in;
}

ostream& operator<<(ostream& out, NVVP& m) {
	m.NV::Xuat();
	out << "\nSo ngay lam viec cua nhan vien la: " << m.songay << "\nLuong cua nhan vien la: " << m.Luong() << endl;
	return out;
}