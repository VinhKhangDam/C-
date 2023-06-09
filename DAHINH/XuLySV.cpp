#include "SV.h"

SV::~SV() {}

SV::SV(string ms, string ht, string khoa, double dtb) : MSSV(ms), Name(ht), Khoa(khoa), DiemTB(dtb) {}

string SV::GetMSSV() { return MSSV; }

string SV::GetName() { return Name; }

string SV::GetKhoa() { return Khoa; }

double SV::GetDiemTB() { return DiemTB; }

void SV::SetName(string ht) { Name = ht; }

void SV::SetKhoa(string khoa) { Khoa = khoa; }

void SV::SetDiemTB(double dtb) { DiemTB = dtb; }

void SV::SetDRL(int drl) { return; }

void SV::SetSBV(int sbv) { return; }

int SV::GetDRL() { return -1; }

int SV::GetSBV() { return -1; }

void SV::Nhap()
{
    cin.ignore();
    cout << "Nhap ma so sinh vien: ";
    getline(cin, MSSV);
    cout << "Nhap ho va ten: ";
    getline(cin, Name);
    cout << "Nhap khoa: ";
    getline(cin, Khoa);
    cout << "Nhap diem trung binh: ";
    cin >> DiemTB;

}

void SV::Xuat()
{
    cout << "MSSV: " << MSSV << "\nHo va ten: " << Name << "\nKhoa: " << Khoa << "\nDiem trung binh: " << DiemTB << "\n";
}