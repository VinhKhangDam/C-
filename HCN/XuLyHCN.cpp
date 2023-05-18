#include "HCNhat.h"
HCNhat::~HCNhat() {
	cout << "Da huy 1 hinh chu nhat!\n";
}
HCNhat::HCNhat(double xA, double yA, double xB, double yB): A(xA, yA), B(xB, yB){
	while (!KiemTraHopLe()){
		cout << "Khong hop le! Vui long nhap lai!\n";
		Nhap();
	}		
}
HCNhat::HCNhat(const Diem& A, const Diem& B ): A(A), B(B){
	while (!KiemTraHopLe()) {
		cout << "Khong hop le! Vui long nhap lai!\n";
		Nhap();
	}
}
void HCNhat::SetA(const Diem& A){
	this->A = A;
	while (!KiemTraHopLe()) {
		cout << "Nhap lai toa do diem A\n ";
		cin >> this->A;
	}
}
void HCNhat::SetB(const Diem& B){
	this->B = B;
	while (!KiemTraHopLe()) {
		cout << "Nhap lai toa do diem B\n";
		cin >> this->B;
	}
}
void HCNhat::SetAB(const Diem& A, const Diem& B){
	this->A = A;
	this->B = B;
	while (!KiemTraHopLe()){
		cout << "Khong hop le! Vui long nhap lai!\n";
		Nhap();
	}
}
Diem HCNhat::GetA() const{
	return A;
}
Diem HCNhat::GetB() const{
	return B;
}
void HCNhat::Nhap(){
	cout << "Nhap toa do diem A\n";
	cin >> A;
	cout << "Nhap toa do diem B\n";
	cin >> B;
	while (!KiemTraHopLe()) {
		cout << "Khong hop le! Vui long nhap lai!\n";
		Nhap();
	}
}
void HCNhat::Xuat() const{
	cout << "Hinh chu nhat co duong cheo duoc tao boi 2 diem A" << A << " va B" << B << '\n';
}
void HCNhat::DiChuyenHCN(double dx, double dy){
	A.DiChuyen(dx, dy);
	B.DiChuyen(dx, dy);
}
bool HCNhat::KiemTraHopLe()	const{
	return (!A.KiemTraTrung(B)) && A.GetX() != B.GetX() && A.GetY() != B.GetY();
}
double HCNhat::TinhChuVi() const{
	return (GetRong() + GetDai())*2;
}
double HCNhat::TinhDienTich() const{
	return GetRong() * GetDai();
}
double HCNhat::GetRong() const{
	return abs(A.GetX() - B.GetX());
}
double HCNhat::GetDai() const{
	return abs(A.GetY() - B.GetY());
}
istream& operator >> (istream& in, HCNhat& hcn){
	hcn.Nhap();
	while (!hcn.KiemTraHopLe()) {
		cout << "Khong hop le! Vui long nhap lai!\n";
		cin >> hcn;
	}
}
ostream& operator << (ostream& out, const HCNhat& hcn){
	hcn.Xuat();
}
