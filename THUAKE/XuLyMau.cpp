#include <iostream>
using namespace std;

class MAU
{
protected:
    int r, g, b;
    static int dem;

public:
    ~MAU();
    MAU(int = 0, int = 0, int = 0);
    MAU(const MAU &);
    int GetR() const;
    int GetG() const;
    int GetB() const;
    static int GetDem();
    void SetR(int);
    void SetG(int);
    void SetB(int);
    void SetRGB(int, int, int);
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const MAU &) const;
    friend istream &operator>>(istream &, MAU &);
    friend ostream &operator<<(ostream &, const MAU &);
};

int MAU::dem = 0;

MAU::~MAU()
{
    cout << "Da huy 1 mau => Con " << --dem << " mau\n";
}

MAU::MAU(int r, int g, int b)
{
    SetRGB(r, g, b);
    cout << "Da tao mot mau => Co " << ++dem << " mau\n";
}

MAU::MAU(const MAU &m)
{
    SetRGB(m.r, m.g, m.b);
    cout << "Da tao mot mau => Co " << ++dem << " mau\n";
}

int MAU::GetR() const
{
    return r;
}

int MAU::GetG() const
{
    return g;
}

int MAU::GetB() const
{
    return b;
}

int MAU::GetDem()
{
    return dem;
}

void MAU::SetR(int r)
{
    while (r < 0 || r > 255)
    {
        cout << "Nhap lai thong so r tu 0 den 255: ";
        cin >> r;
    }
    this->r = r;
}

void MAU::SetG(int g)
{
    while (g < 0 || g > 255)
    {
        cout << "Nhap lai thong so g tu 0 den 255: ";
        cin >> g;
    }
    this->g = g;
}

void MAU::SetB(int b)
{
    while (b < 0 || b > 255)
    {
        cout << "Nhap lai thong so b tu 0 den 255: ";
        cin >> b;
    }
    this->b = b;
}

void MAU::SetRGB(int r, int g, int b)
{
    SetR(r);
    SetG(g);
    SetB(b);
}

void MAU::Nhap()
{
    do
    {
        cout << "Nhap lai thong so mau RGB tu 0 den 255: ";
        cin >> r >> g >> b;
    } while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}

void MAU::Xuat() const
{
    cout << " )- Mau RGB(" << r << ", " << g << ", " << b << ")";
}

bool MAU::KiemTraTrung(const MAU &m) const
{
    return r == m.r && g == m.g && b == m.b;
}

istream &operator>>(istream &in, MAU &m)
{
    do
    {
        cout << "Nhap lai thong so mau RGB tu 0 den 255: ";
        in >> m.r >> m.g >> m.b;
    } while (m.r < 0 || m.r > 255 || m.g < 0 || m.g > 255 || m.b < 0 || m.b > 255);
    return in;
}

ostream &operator<<(ostream &out, const MAU &m)
{
    out << " - Mau RGB(" << m.r << ", " << m.g << ", " << m.b << ")";
    return out;
}
