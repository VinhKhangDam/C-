#include "NhanVien.h"

NhanVien::NhanVien(string mnv,string ht,int tuoi,string sdt,string email,long lcb):mnv(mnv),ht(ht),tuoi(tuoi),sdt(sdt),email(email),lcb(lcb) {}

NhanVien::~NhanVien() {}

string NhanVien::GetMNV() {
	return mnv;
}

string NhanVien::GetHT() {
	return ht;
}

int NhanVien::GetTuoi() {
	return tuoi;
}

string NhanVien::GetSDT() {
	return sdt;
}

string NhanVien::GetEmail() {
	return email;
}

long NhanVien::GetLCB() {
	return lcb;
}

void NhanVien::SetHT(string ht) {
	this->ht = ht;
}

void NhanVien::SetTuoi(int t) {
	t = tuoi;
}

void NhanVien::SetSDT(string sdt) {
	this->sdt = sdt;
}

void NhanVien::SetEmail(string em) {
	em = email;
}

void NhanVien::SetLCB(long lcb) {
	this->lcb = lcb;
}

void NhanVien::SetSGL(int sgl) { return; }

void NhanVien::SetSL(int sl) { return; }

int NhanVien::GetSGL() { return -1; }

int NhanVien::GetSL() { return -1; }

void NhanVien::Nhap() {
	cin.ignore();
	cout << "Nhap ma nhan vien: ";
	getline(cin, mnv);
	cout << "Nhap ho ten nhan vien: ";
	getline(cin, ht);
	cout << "Nhap tuoi: ";
	cin >> tuoi;
	cin.ignore();
	cout << "Nhap so dien thoai: ";
	getline(cin, sdt);
	cout << "Nhap email: ";
	getline(cin, email);
	cout << "Nhap luong co ban: ";
	cin >> lcb;
}

void NhanVien::Xuat() {
	cout << "Ma nhan vien: " << mnv << "\nHo ten nhan vien: " << ht << "\nTuoi: " << tuoi << "\nSo dien thoai: " << sdt
		<< "\nEmail: " << email << "\nLuong co ban cua nhan vien: " << lcb << "\n";
}