#pragma once
#ifndef _SVCQ
#define _SVCQ
#include "SV.h"

class SVCQ : public SV
{
private:
    int DRL;

public:
    SVCQ(string = "", string = "", string = "", double = 0, int = 0);
    int GetDRL();
    void SetDRL(int);
    void Nhap();
    void Xuat();
    long HocBong();
    string GetLoai();
};

#endif // !_SVCQ

