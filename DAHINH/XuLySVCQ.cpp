#include "SVCQ.h"

SVCQ::SVCQ(string ms, string ht, string khoa, double dtb, int drl) : SV(ms, ht, khoa, dtb), DRL(drl) {}

int SVCQ::GetDRL() { return DRL; }

void SVCQ::SetDRL(int DRL)
{
    while (DRL < 0 || DRL > 100)
    {
        cout << "Nhap diem ren luyen: ";
        cin >> DRL;
    }
    this->DRL = DRL;
}

void SVCQ::Nhap()
{
    do
    {
        SV::Nhap();
        cout << "Nhap diem ren luyen: ";
        cin >> DRL;
    } while (DRL < 0 || DRL > 100);
}

void SVCQ::Xuat()
{
    SV::Xuat();
    cout << "";
    cout << "Diem ren luyen: " << DRL << "\nTien hoc bong: " << HocBong() << endl;
}

long SVCQ::HocBong()
{
    long hb = 0;
    if (DRL > 75)
    {
        if (DiemTB >= 7.5 && DiemTB < 8.5)
        {
            hb += 1000000;
        }
        else if (DiemTB >= 8.5 && DiemTB < 9.5)
        {
            hb += 1200000;
        }
        else if (DiemTB >= 9.5)
        {
            hb += 1500000;
        }
    }
    else
        return hb;
}

string SVCQ::GetLoai()
{
    return "SVCQ";
}

