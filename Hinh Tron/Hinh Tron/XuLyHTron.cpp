#include "HTron.h"

Htron::~Htron() {
	cout << "Da huy mot hinh tron\n";
}

Htron::Htron(double x, double y, double r) : tam(x, y), r(r) {
	while (!KiemTraHopLe()) {
		cout << "Khong hop le . Vui long nhap lai\n";
		Nhap();
	}
}

Htron::Htron(const Diem& I, double r) : tam(I), r(r) {
	while (!KiemTraHopLe()) {
		cout << "Khong hop le . Vui long nhap lai\n";
		Nhap();
	}
}

void Htron::SetTam(const Diem& I) {
	this->tam = I;
	while (!KiemTraHopLe()) {
		cout << "Nhap lai toa do tam hinh tron\n";
		cin >> this->tam;
	}
}

void Htron::SetR(double r) {
	this->r = r;
	while (r < 0) {
		cout << "Nhap lai ban kinh hinh tron: r = ";
		cin >> this->r;
	}
}

Diem Htron::GetTam() const {
	return tam;
}

double Htron::GetR() const {
	return r;
}

void Htron::Nhap() {
	cout << "Nhap toa do tam cua hinh tron\n";
	cin >> tam;
	cout << "Nhap ban kinh hinh tron: r = ";
	cin >> r;
	while (!KiemTraHopLe()) {
		cout << "Khong hop le! Vui long nhap lai!\n";
		Nhap();
	}
}

void Htron::Xuat() const {
	cout << "Hinh tron duoc tao boi tam co toa do" << tam << " va ban kinh la " << r;
}

void Htron::DiChuyen(double dx, double dy) {
	tam.DiChuyen(dx, dy);
}

bool Htron::KiemTraHopLe() const {
	return r > 0;
}

double Htron::TinhChuVi() const {
	return r * 2 * 3.14;
}

double Htron::TinhDienTich() const {
	return r * r * 3.14;
}

istream& operator>>(istream& in, Htron& ht) {
	ht.Nhap();
	while (!ht.KiemTraHopLe()) {
		cout << "Khong hop le. Moi nhap lai\n";
		in >> ht;
	}
	return in;
}

ostream& operator << (ostream& out, const Htron& ht) {
	ht.Xuat();
	return out;
}