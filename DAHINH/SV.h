#pragma once
#ifndef _SV
#define _SV
#include <iostream>
#include <string>
using namespace std;

class SV
{
protected:
    string MSSV, Name, Khoa;
    double DiemTB;

public:
    ~SV();
    SV(string = "", string = "", string = "", double = 0);
    string GetMSSV();
    string GetName();
    string GetKhoa();
    double GetDiemTB();
    void SetName(string);
    void SetKhoa(string);
    void SetDiemTB(double);
    virtual void SetDRL(int);
    virtual void SetSBV(int);
    virtual int GetDRL();
    virtual int GetSBV();
    virtual void Nhap();
    virtual void Xuat();
    virtual string GetLoai() = 0;
    virtual long HocBong() = 0;
};

#endif // !_SV

