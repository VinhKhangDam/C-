#include "XuLyDiem3C.cpp"
#include "XuLyMau.cpp"

class DIEM3CMAU : public DIEM3C, MAU
{
private:
    static int dem;

public:
    ~DIEM3CMAU();
    DIEM3CMAU(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEM3CMAU &) const;
    friend istream &operator>>(istream &, DIEM3CMAU &);
    friend ostream &operator<<(ostream &, const DIEM3CMAU &);
};

int DIEM3CMAU::dem = 0;

DIEM3CMAU::~DIEM3CMAU()
{
    cout << "Da huy 1 diem 3 chieu mau => Con " << --dem << " diem 3C mau\n";
}

DIEM3CMAU::DIEM3CMAU(double x, double y, double z, int r, int g, int b) : DIEM3C(x, y, z), MAU(r, g, b)
{
    cout << "Da them 1 diem 3 chieu mau => Co " << ++dem << " diem 3C mau\n";
}

int DIEM3CMAU::GetDem()
{
    return dem;
}

void DIEM3CMAU::Nhap()
{
    DIEM3C::Nhap();
    MAU::Nhap();
}

void DIEM3CMAU::Xuat() const
{
    DIEM3C::Xuat();
    MAU::Xuat();
}

bool DIEM3CMAU::KiemTraTrung(const DIEM3CMAU &m) const
{
    return DIEM3C::KiemTraTrung(m) && MAU::KiemTraTrung(m);
}

istream &operator>>(istream &in, DIEM3CMAU &m)
{
    m.Nhap();
    return in;
}

ostream &operator<<(ostream &out, const DIEM3CMAU &m)
{
    m.Xuat();
    return out;
}
