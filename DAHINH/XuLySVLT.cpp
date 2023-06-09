#include "SVLT.h"

SVLT::SVLT(string ms, string ht, string khoa, double dtb, int sbv) : SV(ms, ht, khoa, dtb), SBV(sbv) {}

int SVLT::GetSBV() { return SBV; }

void SVLT::SetSBV(int SBV)
{
    while (SBV > 0)
    {
        cout << "Nhap so buoi vang: ";
        cin >> SBV;
    }
    this->SBV = SBV;
}

void SVLT::Nhap()
{
    do
    {
        SV::Nhap();
        cout << "Nhap so buoi vang: ";
        cin >> SBV;
    } while (SBV < 0);
}

void SVLT::Xuat()
{
    SV::Xuat();
    cout << "";
    cout << "So buoi vang: " << SBV << "\nHoc bong cua sinh vien la: " << HocBong() << endl;
}

long SVLT::HocBong()
{
    long hb = 0;
    if (SBV <= 3 && SBV >= 0)
    {
        if (DiemTB >= 7 && DiemTB < 8)
        {
            hb += 1000000;
        }
        else if (DiemTB >= 8 && DiemTB < 9)
        {
            hb += 1200000;
        }
        else if (DiemTB >= 9)
        {
            hb += 1500000;
        }
    }
    return hb;
}

string SVLT::GetLoai()
{
    return "SVLT";
}
