#include "XuLyDiem.cpp"
#include "XuLyMau.cpp"

class DIEMMAU : public Diem, MAU
{
private:
    static int dem;

public:
    ~DIEMMAU();
    DIEMMAU(double = 0, double = 0, int = 0, int = 0, int = 0);
    static int GetDem();
    void Nhap();
    void Xuat() const;
    bool KiemTraTrung(const DIEMMAU &) const;
    friend istream &operator>>(istream &, DIEMMAU &);
    friend ostream &operator<<(ostream &, const DIEMMAU &);
};

int DIEMMAU::dem = 0;

DIEMMAU::~DIEMMAU()
{
    cout << "Da huy 1 diem mau => Con " << --dem << " diem mau\n";
}

DIEMMAU::DIEMMAU(double x, double y, int r, int g, int b) : Diem(x, y), MAU(r, g, b)
{
    cout << "Da tao them 1 diem mau => Co " << ++dem << " diem mau\n";
}

int DIEMMAU::GetDem()
{
    return dem;
}

void DIEMMAU::Nhap()
{
    Diem::Nhap();
    MAU::Nhap();
}

void DIEMMAU::Xuat() const
{
    Diem::Xuat();
    MAU::Xuat();
}

bool DIEMMAU::KiemTraTrung(const DIEMMAU &m) const
{
    return Diem::KiemTraTrung(m) && MAU::KiemTraTrung(m);
}

istream &operator>>(istream &in, DIEMMAU &dm)
{
    dm.Nhap();
    return in;
}

ostream &operator<<(ostream &out, const DIEMMAU &dm)
{
    dm.Xuat();
    return out;
}
