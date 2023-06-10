#include "NV.h"

NV::NV(string ten,string ns): name(ten),ngaysinh(ns) {}

NV::~NV() {}

void NV::SetName(string name) {
	this->name = name;
}

void NV::SetNgaySinh(string ns) {
	ns = ngaysinh;
}

string NV::GetName() {
	return name;
}

string NV::GetNgaySinh() {
	return ngaysinh;
}

void NV::Nhap() {
	cin.ignore();
	cout << "Nhap ten cua nhan vien: ";
	getline(cin, name);
	cout << "Nhap ngay sinh cua nhan vien: ";
	getline(cin, ngaysinh);
}

void NV::Xuat() {
	cout << "Ten cua nhan vien la: " << name << "\nNgay sinh cua nhan vien la: " << ngaysinh;
}

istream& operator>>(istream& in, NV& m) {
	m.NV::Nhap();
	return in;
}

ostream& operator<<(ostream& out, const NV& m) {
	out << "Ten cua nhan vien la: " << m.name << "\nNgay sinh cua nhan vien la: " << m.ngaysinh;
	return out;
}