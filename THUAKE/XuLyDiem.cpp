#include <iostream>
#include <math.h>
#define epsilon 0.000000001
using namespace std;
class Diem
{
protected:
    double x, y;

public:
    ~Diem();
    Diem(double = 0, double = 0);
    Diem(const Diem &);
    void SetX(double);
    void SetY(double);
    void SetXY(double, double);
    double GetX() const;
    double GetY() const;
    void Nhap();
    void Xuat() const;
    void DiChuyen(double, double);
    bool KiemTraTrung(const Diem &) const;
    double TinhKhoangCach(const Diem &) const;
    Diem DiemDoiXung() const;
    bool KiemTraTamGiacHopLe(const Diem &, const Diem &) const;
    bool KiemTraTamGiacHopLe(double, double, double) const;
    double TinhChuVi(const Diem &, const Diem &) const;
    double TinhDienTich(const Diem &, const Diem &) const;
    string PhanLoai(const Diem &, const Diem &) const;
    friend istream &operator>>(istream &, Diem &);
    friend ostream &operator<<(ostream &, const Diem &);
};

Diem::~Diem()
{
    cout << "Da huy 1 diem\n";
}
Diem::Diem(double x, double y)
{
    this->x = x;
    this->y = y;
}
Diem::Diem(const Diem &d)
{
    x = d.x;
    y = d.y;
}
void Diem::SetX(double x)
{
    this->x = x;
}
void Diem::SetY(double y)
{
    this->y = y;
}
void Diem::SetXY(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Diem::GetX() const
{
    return x;
}
double Diem::GetY() const
{
    return y;
}
void Diem::Nhap()
{
    cout << "Nhap x: ";
    cin >> x;
    cout << "Nhap y: ";
    cin >> y;
}
void Diem::Xuat() const
{
    cout << "(" << x << ", " << y;
}
void Diem::DiChuyen(double a, double b)
{
    x = x + a;
    y = y + b;
}
bool Diem::KiemTraTrung(const Diem &d) const
{
    return (x == d.x && y == d.y);
}
double Diem::TinhKhoangCach(const Diem &d) const
{
    return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}
Diem Diem::DiemDoiXung() const
{
    return Diem(-x, -y);
}
bool Diem::KiemTraTamGiacHopLe(const Diem &d1, const Diem &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = this->TinhKhoangCach(d2);
    return (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a);
}
bool Diem::KiemTraTamGiacHopLe(double a, double b, double c) const
{
    return (a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a);
}
double Diem::TinhChuVi(const Diem &d1, const Diem &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = this->TinhKhoangCach(d2);
    return a + b + c;
}
double Diem::TinhDienTich(const Diem &d1, const Diem &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = this->TinhKhoangCach(d2);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
string Diem::PhanLoai(const Diem &d1, const Diem &d2) const
{
    double a = this->TinhKhoangCach(d1);
    double b = d1.TinhKhoangCach(d2);
    double c = this->TinhKhoangCach(d2);
    string result = "";
    if (!this->KiemTraTamGiacHopLe(d1, d2))
        result = "Tam giac khong hop le!";
    else
    {
        if (a == b && b == c)
            result = "Tam giac deu!\n";
        else if (a == b || b == c || a == c)
        {
            if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2))
                result = "Tam giac vuong can!";
            else
                result = "Tam giac can!";
        }
        else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2))
            result = "Tam giac vuong!";
        else
            result = "Tam giac thuong!";
    }
    return result;
}
istream &operator>>(istream &in, Diem &d)
{
    d.Nhap();
    return in;
}
ostream &operator<<(ostream &out, const Diem &d)
{
    d.Xuat();
    return out;
}
