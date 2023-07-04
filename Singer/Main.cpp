#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Singer
{
protected:
    string name;
    int year;
    int sodia;
    int sobuoi;

public:
    Singer(string = "", int = 0, int = 0, int = 0);
    ~Singer();
    void SetName(string);
    void SetYear(int);
    void SetSoDia(int);
    void SetSoBuoi(int);
    string GetName();
    int GetYear();
    int GetSoDia();
    int GetSoBuoi();
    virtual void Nhap();
    virtual void Xuat();
    virtual void SetGameShow(int);
    virtual int GetGameShow();
    virtual long Luong() = 0;
    virtual string GetLoai() = 0;
};

Singer::Singer(string n, int y, int s, int b) : name(n), year(y), sodia(s), sobuoi(b) {}

Singer::~Singer() {}

void Singer::SetName(string name)
{
    this->name = name;
}

void Singer::SetYear(int year)
{
    do
    {
        cout << "Nhap so nam di dien: ";
        cin >> year;
    } while (year < 1);
}

void Singer::SetSoDia(int sodia)
{
    this->sodia = sodia;
}

void Singer::SetSoBuoi(int sobuoi)
{
    this->sobuoi = sobuoi;
}

string Singer::GetName()
{
    return name;
}

int Singer::GetYear()
{
    return year;
}

int Singer::GetSoDia()
{
    return sodia;
}

int Singer::GetSoBuoi()
{
    return sobuoi;
}

void Singer::Nhap()
{
    cout << "Nhap ten ca si: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap so nam di dien: ";
    cin >> year;
    cout << "Nhap so dia ban duoc: ";
    cin >> sodia;
    cout << "Nhap so buoi dien: ";
    cin >> sobuoi;
}

void Singer::Xuat()
{
    cout << "Ten ca si: " << name << "\nSo nam di dien: " << year << "\nSo dia ban duoc: "
         << "\nSo buoi dien: " << sobuoi << "\n";
}

void Singer::SetGameShow(int gs)
{
    return;
}

int Singer::GetGameShow()
{
    return -1;
}

class NoiTieng : public Singer
{
private:
    int gs;

public:
    NoiTieng(string = "", int = 0, int = 0, int = 0, int = 0);
    void SetGameShow(int);
    int GetGameShow();
    void Nhap();
    void Xuat();
    long Luong();
    string GetLoai();
};

NoiTieng::NoiTieng(string n, int y, int s, int b, int gs) : Singer(n, y, s, b), gs(gs) {}

void NoiTieng::SetGameShow(int gs)
{
    this->gs = gs;
}

int NoiTieng::GetGameShow()
{
    return gs;
}

void NoiTieng::Nhap()
{
    Singer::Nhap();
    cout << "Nhap so game show duoc tham gia: ";
    cin >> gs;
}

void NoiTieng::Xuat()
{
    Singer::Xuat();
    cout << "So gameshow tham gia duoc la: " << gs << "\nLuong cua ca si la: " << Luong() << endl;
}

long NoiTieng::Luong()
{
    return 5000000 + 500000 * year + 1200 * sodia + 500000 * sobuoi + 500000 * gs;
}

string NoiTieng::GetLoai()
{
    return "NT";
}

class CNT : public Singer
{
public:
    CNT(string = "", int = 0, int = 0, int = 0);
    void Nhap();
    void Xuat();
    long Luong();
    string GetLoai();
};

CNT::CNT(string n, int y, int s, int b) : Singer(n, y, s, b) {}

void CNT::Nhap()
{
    Singer::Nhap();
}

void CNT::Xuat()
{
    Singer::Xuat();
    cout << "Luong cua ca si: " << Luong() << endl;
}

long CNT::Luong()
{
    return 3000000 + 500000 * year + 1000 * sodia + 200000 * sobuoi;
}

string CNT::GetLoai()
{
    return "CNT";
}

class CongTy
{
private:
    Singer **sg;
    int sl;

public:
    CongTy();
    ~CongTy();
    void Nhap();
    void Xuat();
    void CaSiCoLuongCaoNhat();
};

CongTy::CongTy() {}

CongTy::~CongTy() {}

void CongTy::Nhap()
{
    int chon;
    do
    {
        cout << "Nhap so luong ca si: ";
        cin >> sl;
    } while (sl < 1);
    sg = new Singer *[sl];
    for (int i = 0; i < sl; i++)
    {
        cout << "------------" << endl;
        cout << "Nhap thong tin ca si thu " << i + 1 << ":\n";
        do
        {
            cout << "Nhap ca si(1.Ca si noi tieng, 2.Ca si chua noi tieng): ";
            cin >> chon;
        } while (chon < 1 || chon > 2);
        if (chon == 1)
            sg[i] = new NoiTieng;
        else
            sg[i] = new CNT;
        sg[i]->Nhap();
    }
}

void CongTy::Xuat()
{
    for (int i = 0; i < sl; i++)
    {
        sg[i]->Xuat();
    }
}

void CongTy::CaSiCoLuongCaoNhat()
{
    long luong;
    for (int i = 0; i < sl; i++)
    {
        luong = sg[0]->Luong();
        if (sg[i]->Luong() > luong)
        {
            luong = sg[i]->Luong();
        }
    }
    for (int i = 0; i < sl; i++)
    {
        if (sg[i]->Luong() == luong)
        {
            sg[i]->Xuat();
        }
    }
}

int main()
{
    system("cls");
    CongTy a;
    a.Nhap();
    a.Xuat();
    a.CaSiCoLuongCaoNhat();
    system("pause");
    return 0;
}