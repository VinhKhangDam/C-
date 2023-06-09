#pragma once
#ifndef _SVLT
#define _SVLT
#include "SV.h"

class SVLT : public SV
{
private:
    int SBV;

public:
    SVLT(string = "", string = "", string = "", double = 0, int = 0);
    int GetSBV();
    void SetSBV(int);
    void Nhap();
    void Xuat();
    long HocBong();
    string GetLoai();
};


#endif // !_SVLT

