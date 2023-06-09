#pragma once
#ifndef _TruongDH
#define _TruongDH
#include "SV.h"
#include "SVCQ.h"
#include "SVLT.h"
#include <fstream>
#include <string>

class TruongDH
{
private:
    SV** sv;
    int sl;

public:
    TruongDH();
    ~TruongDH();
    int GetSL();
    void Nhap();
    void Xuat();
    SV* Nhap1();
    void LietKeSinhVienDRL100();
    int SoLuongSVLTKhongnghi();
    long TongHocBong();
    double DiemTBSVCoHocBong();
    bool SVLTDTBtu9vaKhongNghi();
    void SVCQcoDiemTBCaoNhat();
    string DoiChuInHoa(string);
    string DoiChuInThuong(string);
    void SapXepTangTheoMaSo();
    void Them1SV(SV*, int);
    int Xoa1SV(string);
    void TimSVtheoMSSV(string);
    void TimSVtheoTen(string);
    void TimSVtheoKhoa(string);
    void TimSVtheoDTB(double);
};

#endif // !_TruongDH

