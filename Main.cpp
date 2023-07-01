#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
using namespace std;

class Ve
{
protected:
    string mave;
    string hoten;
    int ns;
    int sotrochoi;

public:
    Ve(string = "", string = "", int = 0, int = 0);
    ~Ve();
    void SetMaVe(string);
    void SetHoTen(string);
    void SetNamSinh(int);
    void SetSoTroChoi(int);
    string GetMaVe();
    string GetHoTen();
    int GetNamSinh();
    int GetSoTroChoi();
    virtual void Nhap();
    virtual void Xuat();
    virtual string GetLoai() = 0;
    virtual long GiaVe() = 0;
};

Ve::Ve(string mave, string ht, int ns, int stc) : mave(mave), hoten(ht), ns(ns), sotrochoi(stc) {}

Ve::~Ve() {}

void Ve::SetMaVe(string mv) { mv = mave; }

void Ve::SetHoTen(string ht) { this->hoten = ht; }

void Ve::SetNamSinh(int ns) { this->ns = ns; }

void Ve::SetSoTroChoi(int stc)
{
    do
    {
        cout << "Nhap lai so tro choi: ";
        cin >> sotrochoi;
    } while (stc < 0 || stc > 30);
}

string Ve::GetMaVe() { return mave; }

string Ve::GetHoTen() { return hoten; }

int Ve::GetNamSinh() { return ns; }

int Ve::GetSoTroChoi() { return sotrochoi; }

void Ve::Nhap()
{
    cin.ignore();
    cout << "Nhap ma ve: ";
    getline(cin, mave);
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap nam sinh: ";
    cin >> ns;
    do
    {
        cout << "Nhap so tro choi: ";
        cin >> sotrochoi;
    } while (sotrochoi < 0 || sotrochoi > 30);
}

void Ve::Xuat()
{
    cout << "\nThong tin ve cua nguoi da mua ve la:\n";
    cout << "Ma ve : " << mave << "\nHo ten cua nguoi mua: " << hoten << "\nNam sinh cua nguoi mua: " << ns
         << "\nSo tro choi : " << sotrochoi << endl;
}

class VeTronGoi : public Ve
{
public:
    VeTronGoi(string = "", string = "", int = 0, int = 0);
    void Nhap();
    void Xuat();
    string GetLoai();
    long GiaVe();
};

VeTronGoi::VeTronGoi(string mv, string ht, int ns, int stc) : Ve(mv, ht, ns, stc) {}

void VeTronGoi::Nhap()
{
    Ve::Nhap();
}

void VeTronGoi::Xuat()
{
    Ve::Xuat();
}

string VeTronGoi::GetLoai()
{
    return "VeTronGoi";
}

long VeTronGoi::GiaVe()
{
    return 200000;
}

class VeTungPhan : public Ve
{
public:
    VeTungPhan(string = "", string = "", int = 0, int = 0);
    void Nhap();
    void Xuat();
    string GetLoai();
    long GiaVe();
};

VeTungPhan::VeTungPhan(string mv, string ht, int ns, int stc) : Ve(mv, ht, ns, stc) {}

void VeTungPhan::Nhap()
{
    Ve::Nhap();
}

void VeTungPhan::Xuat()
{
    Ve::Xuat();
}

string VeTungPhan::GetLoai()
{
    return "VeTungPhan";
}

long VeTungPhan::GiaVe()
{
    return 70000 + 20000 * sotrochoi;
}

class CongVien
{
private:
    int sl;
    Ve **ve;

public:
    CongVien();
    ~CongVien();
    int GetSL();
    void Nhap();
    void Xuat();
    Ve *Nhap1();
    long TongTienVe();
    void Sovelavetungphan();
};

CongVien::CongVien()
{
    ve = NULL;
    sl = 0;
}

CongVien::~CongVien()
{
    for (int i = 0; i < sl; i++)
        delete ve[i];
    delete[] ve;
    ve = NULL;
    sl = 0;
}

int CongVien::GetSL()
{
    return sl;
}

void CongVien::Nhap()
{
    int loai;
    do
    {
        cout << "Nhap so luong ve: ";
        cin >> sl;
    } while (sl < 1);
    ve = new Ve *[sl];
    for (int i = 0; i < sl; i++)
    {
        cout << "-------------------------" << endl;
        cout << "Nhap thong tin ve " << i + 1 << ":\n";
        do
        {
            cout << " Nhap(1 : Ve Tron Goi, 2 : Ve Tung Phan): ";
            cin >> loai;
        } while (loai < 1 || loai > 2);
        if (loai == 1)
            ve[i] = new VeTronGoi;
        else
            ve[i] = new VeTungPhan;
        ve[i]->Nhap();
        cout << "------------------------";
    }
}

void CongVien::Xuat()
{
    for (int i = 0; i < sl; i++)
    {
        ve[i]->Xuat();
        cout << "------------------------";
    }
}

Ve *CongVien::Nhap1()
{
    int loai;
    Ve *v;
    do
    {
        cout << " Nhap(1 : Ve Tron Goi, 2 : Ve Tung Phan): ";
        cin >> loai;
    } while (loai < 1 || loai > 2);
    if (loai == 1)
        v = new VeTronGoi;
    else
        v = new VeTungPhan;
    v->Nhap();
    return v;
}

long CongVien::TongTienVe()
{
    long tonggiave = 0;
    for (int i = 0; i < sl; i++)
    {
        if (ve[i]->GiaVe() != 0)
        {
            tonggiave += ve[i]->GiaVe();
        }
    }
    return tonggiave;
}

void CongVien::Sovelavetungphan()
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (ve[i]->GetLoai() == "VeTungPhan")
        {
            dem++;
        }
    }
    cout << "So ve da ban la ve tung phan la: " << dem << endl;
}

int main()
{
    system("cls");
    CongVien cv;
    cv.Nhap();
    cv.Xuat();
    long tonggiave = 0;
    tonggiave = cv.TongTienVe();
    cout << "\nTong tien ve thu duoc la: " << tonggiave << endl;
    cv.Sovelavetungphan();
    system("pause");
    return 0;
}