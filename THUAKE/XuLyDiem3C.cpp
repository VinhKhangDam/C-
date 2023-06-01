#include "XuLyDiem.cpp"
#include <stdlib.h>
#define _DIEM3C
class DIEM3C : public Diem
{
protected:
    double z;
    static int dem;

public:
    ~DIEM3C();
    /*DIEM3C();
    DIEM3C(double);
    DIEM3C(double,double,double);
    DIEM3C(double,double,double);*/
    DIEM3C(double = 0, double = 0, double = 0);
    DIEM3C(const DIEM3C &);
    double GetZ() const;
    void SetZ(double);
    void SetXYZ(double, double, double);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEM3C &) const;
    void DiChuyen(double, double, double);
    double TinhKhoangCach(const DIEM3C &) const;
    DIEM3C TimDoiXung() const;
    double Chuvi(DIEM3C &, DIEM3C &) const;
    double Dientich(DIEM3C &, DIEM3C &) const;
    friend istream &operator>>(istream &, DIEM3C &);
    friend ostream &operator<<(ostream &, DIEM3C &);
};
int DIEM3C::dem = 0;

DIEM3C::~DIEM3C()
{
    cout << " Da huy 1 diem 3C => Con " << --dem << " diem 3C\n";
}

DIEM3C::DIEM3C(double x, double y, double z) : Diem(x, y), z(z)
{
    cout << "Da tao 1 diem 3C => Co " << ++dem << " diem 3C\n";
}

DIEM3C::DIEM3C(const DIEM3C &m)
{
    cout << "Da tao 1 diem 3C => Co " << ++dem << " diem 3C\n";
}

double DIEM3C::GetZ() const
{
    return z;
}

void DIEM3C::SetZ(double z)
{
    this->z = z;
}

void DIEM3C::SetXYZ(double x, double y, double z)
{
    SetXY(x, y);
    SetZ(z);
}

int DIEM3C::GetDem()
{
    return dem;
}

void DIEM3C::Nhap()
{
    Diem::Nhap();
    cout << "Nhap cao do: ";
    cin >> z;
}

void DIEM3C::Xuat() const
{
    Diem::Xuat();
    cout << " ," << z << ")";
}

bool DIEM3C::KiemTraTrung(const DIEM3C &m) const
{
    return Diem::KiemTraTrung(m) && z == m.z;
}

void DIEM3C::DiChuyen(double dx, double dy, double dz)
{
    Diem::DiChuyen(dx, dy);
    z += dz;
}

double DIEM3C::TinhKhoangCach(const DIEM3C &m) const
{
    return sqrt(pow(x - m.x, 2) + pow(y - m.y, 2) + pow(z - m.z, 2));
}

double DIEM3C::Chuvi(DIEM3C &a, DIEM3C &b) const
{
    return this->TinhKhoangCach(a) + a.TinhKhoangCach(b) + this->TinhKhoangCach(b);
}

DIEM3C DIEM3C::TimDoiXung() const
{
    return DIEM3C(-x == 0 ? x : -x, -y == 0 ? y : -y, -z == 0 ? z : -z);
}

double DIEM3C::Dientich(DIEM3C &a, DIEM3C &b) const
{
    double p = (this->TinhKhoangCach(a) + a.TinhKhoangCach(b) + this->TinhKhoangCach(b)) / 2;
    double d1 = this->TinhKhoangCach(a);
    double d2 = a.TinhKhoangCach(b);
    double d3 = this->TinhKhoangCach(b);
    return sqrt(p * (p - d1) * (p - d2) * (p - d3));
}

istream &operator>>(istream &in, DIEM3C &m)
{
    m.Diem::Nhap();
    cout << "Nhap cao do: ";
    in >> m.z;
    return in;
}

ostream &operator<<(ostream &out, DIEM3C &m)
{
    m.Diem::Xuat();
    out << ", " << m.z << ")";
    return out;
}
