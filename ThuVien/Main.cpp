#include <iostream>
using namespace std;
#include <string>
#include <math.h>
#include <stdlib.h>
class Sach // Abtract class
{
protected:
    string ms, ts, nxb;
    long dg;
    int sl;

public:
    Sach(string = "", string = "", string = "", long = 0, int = 0);
    ~Sach();
    void SetMS(string);
    void SetTS(string);
    void SetNXB(string);
    void SetDG(long);
    void SetSL(int);
    string GetMS();
    string GetTS();
    string GetNXB();
    long GetDG();
    int GetSL();
    virtual void Nhap();
    virtual void Xuat();
    virtual void SetTinhTrang(int);
    virtual void SetTienThue(long);
    virtual int GetTinhTrang();
    virtual long GetTienThue();
    virtual long ThanhTien() = 0;
    virtual string GetLoai() = 0;
};

Sach::Sach(string ms, string ts, string nxb, long dg, int sl) : ms(ms), ts(ts), nxb(nxb), dg(dg), sl(sl) {}

Sach::~Sach() {}

void Sach::SetMS(string ms) { this->ms = ms; }

void Sach::SetTS(string ts) { this->ts = ts; }

void Sach::SetNXB(string nxb) { this->nxb = nxb; }

void Sach::SetDG(long dg) { this->dg = dg; }

void Sach::SetSL(int sl) { this->sl = sl; }

string Sach::GetMS() { return ms; }

string Sach::GetTS() { return ts; }

string Sach::GetNXB() { return nxb; }

long Sach::GetDG() { return dg; }

int Sach::GetSL() { return sl; }

void Sach::Nhap()
{
    cin.ignore();
    cout << "Nhap ma sach: ";
    getline(cin, ms);
    cout << "Nhap ten sach: ";
    getline(cin, ts);
    cout << "Nhap ten nha xuat ban sach: ";
    getline(cin, nxb);
    cout << "Nhap don gia: ";
    cin >> dg;
    cout << "Nhap so luong: ";
    cin >> sl;
}

void Sach::Xuat()
{
    cout << "\nThong tin cua cuon sach la: \n";
    cout << "Ma sach: " << ms << "\nTen sach: " << ts << "\nTen cua nha xuat ban: " << nxb << "\nDon gia: " << dg << "\nSo luong: " << sl << endl;
}

void Sach::SetTinhTrang(int ttrang) { return; }

void Sach::SetTienThue(long tthue) { return; }

int Sach::GetTinhTrang() { return -1; }

long Sach::GetTienThue() { return -1; }
////end Class Sach

/// start class SachGiaoKhoa
class SachGiaoKhoa : public Sach
{
private:
    int ttrang;

public:
    SachGiaoKhoa(string = "", string = "", string = "", long = 0, int = 0, int = -1);
    void SetTinhTrang(int);
    int GetTinhTrang();
    void Nhap();
    void Xuat();
    long ThanhTien();
    string GetLoai();
};

SachGiaoKhoa::SachGiaoKhoa(string ms, string ts, string nxb, long dg, int sl, int ttrang) : Sach(ms, ts, nxb, dg, sl), ttrang(ttrang) {}

void SachGiaoKhoa::SetTinhTrang(int ttrang)
{
    do
    {
        cout << "Nhap tinh trang sach (0: cu, 1: moi): ";
        cin >> ttrang;
    } while (ttrang < 0 || ttrang > 1);
}

int SachGiaoKhoa::GetTinhTrang()
{
    return ttrang;
}

void SachGiaoKhoa::Nhap()
{
    Sach::Nhap();
    do
    {
        cout << "Nhap tinh trang sach (0: cu, 1: moi): ";
        cin >> ttrang;
    } while (ttrang < 0 || ttrang > 1);
}

void SachGiaoKhoa::Xuat()
{
    Sach::Xuat();
    cout << "Tinh trang cua sach la: ";
    if (ttrang == 0)
    {
        cout << "Sach cu\n";
    }
    else
    {
        cout << "Sach moi\n";
    }
    cout << "Thanh tien : " << ThanhTien() << endl;
}

long SachGiaoKhoa::ThanhTien()
{
    if (ttrang == 1)
        return sl * dg;
    else
        return sl * dg * 0.5;
}

string SachGiaoKhoa::GetLoai()
{
    return "SachGiaoKhoa";
}
// end class SachGiaoKhoa

// start class SachThamKhao

class SachThamKhao : public Sach
{
private:
    long tthue;

public:
    SachThamKhao(string = "", string = "", string = "", long = 0, int = 0, long = 0);
    void SetTienThue(long);
    long GetTienThue();
    void Nhap();
    void Xuat();
    long ThanhTien();
    string GetLoai();
};

SachThamKhao::SachThamKhao(string ms, string ts, string nxb, long dg, int sl, long tthue) : Sach(ms, ts, nxb, dg, sl), tthue(tthue) {}

void SachThamKhao::SetTienThue(long tthue)
{
    do
    {
        cout << "Nhap tien thue: ";
        cin >> tthue;
    } while (tthue < 0);
}

long SachThamKhao::GetTienThue() { return tthue; }

void SachThamKhao::Nhap()
{
    Sach::Nhap();
    cout << "Nhap tien thue: ";
    cin >> tthue;
}

void SachThamKhao::Xuat()
{
    Sach::Xuat();
    cout << "Tien thue la: " << tthue << "\nThanh tien : " << ThanhTien() << endl;
}

long SachThamKhao::ThanhTien()
{
    return sl * dg + tthue;
}

string SachThamKhao::GetLoai()
{
    return "SachThamKhao";
}
// end class SachThamKhao

// start class ThuVien

class ThuVien
{
private:
    Sach **sach;
    int sluong;

public:
    ThuVien();
    ~ThuVien();
    void Nhap();
    void Xuat();
    long ThanhTienThuVien();
    void SachTraItNhat();
    string DoiChuInHoa(string);
    void TimThongTin(string);
};

ThuVien::ThuVien()
{
    sach = NULL;
    sluong = 0;
}

ThuVien::~ThuVien()
{
    for (int i = 0; i < sluong; i++)
        delete sach[i];
    delete[] sach;
    sach = NULL;
    sluong = 0;
}

void ThuVien::Nhap()
{
    int loai;
    do
    {
        cout << "Nhap so luong sach: ";
        cin >> sluong;
    } while (sluong < 1);
    sach = new Sach *[sluong];
    for (int i = 0; i < sluong; i++)
    {
        cout << "-----------------" << endl;
        cout << "Nhap thong tin sach " << i + 1 << ":\n";
        do
        {
            cout << "Nhap thong tin sach loai (1.Sach Giao Khoa, 2.Sach Tham Khao) : ";
            cin >> loai;
        } while (loai < 1 || loai > 2);
        if (loai == 1)
            sach[i] = new SachGiaoKhoa;
        else
            sach[i] = new SachThamKhao;
        sach[i]->Nhap();
    }
    cout << "-------------\n";
}

void ThuVien::Xuat()
{
    for (int i = 0; i < sluong; i++)
    {
        sach[i]->Xuat();
        cout << "-----------------------\n";
    }
}

long ThuVien::ThanhTienThuVien()
{
    long thanhtien = 0;
    for (int i = 0; i < sluong; i++)
    {
        if (sach[i]->ThanhTien() != 0)
        {
            thanhtien += sach[i]->ThanhTien();
        }
    }
    return thanhtien;
}

void ThuVien::SachTraItNhat()
{
    long min;
    for (int i = 0; i < sluong; i++)
    {
        min = sach[0]->ThanhTien();
        if (sach[i]->ThanhTien() < min)
        {
            min = sach[i]->ThanhTien();
        }
    }
    for (int i = 0; i < sluong; i++)
    {
        if (sach[i]->ThanhTien() == min)
        {
            sach[i]->Xuat();
        }
    }
}

string ThuVien::DoiChuInHoa(string str)
{
    for (int i = 0; i < sluong; i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

void ThuVien::TimThongTin(string nxb)
{
    for (int i = 0; i < sluong; i++)
    {
        if (sach[i]->GetLoai() == "SachGiaoKhoa" && DoiChuInHoa(sach[i]->GetNXB()) == DoiChuInHoa(nxb))
        {
            sach[i]->Xuat();
        }
        else
            cout << "Khong tim ra nha xuat ban ban muon tim\n";
    }
}

// end class ThuVien

int main()
{
    system("cls");
    long thanhtien;
    string hm;
    ThuVien tv;
    tv.Nhap();
    tv.Xuat();
    thanhtien = tv.ThanhTienThuVien();
    cout << "Thanh tien tra cho thu vien: " << thanhtien << endl;
    cout << "Sach co thanh tien it nhat: \n";
    tv.SachTraItNhat();
    cout << endl;
    cout << "Nhap ten nha xuat ban ban muon tim: ";
    cin >> hm;
    cout << "Sach giao khoa co ten nha xuat ban do nguoi dung nhap vao la: ";
    tv.TimThongTin(hm);
    system("pause");
    return 0;
}