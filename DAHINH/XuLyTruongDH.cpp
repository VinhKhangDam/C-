#include "TruongDH.h"

TruongDH::TruongDH()
{
    sv = NULL;
    sl = 0;
}

TruongDH::~TruongDH()
{
    for (int i = 0; i < sl; i++)
        delete sv[i];
    delete[] sv;
    sv = NULL;
    sl = 0;
}

int TruongDH::GetSL()
{
    return sl;
}

void TruongDH::Nhap()
{
    int loai;
    do
    {
        cout << "Nhap so luong SV: ";
        cin >> sl;
    } while (sl < 1);
    sv = new SV * [sl];
    for (int i = 0; i < sl; i++)
    {
        cout << "-------------------------" << endl;
        cout << "Nhap thong tin sinh vien " << i + 1 << ":\n";
        do
        {
            cout << " Nhap(1 : SVCQ, 2 : SVLT): ";
            cin >> loai;
        } while (loai < 1 || loai > 2);
        if (loai == 1)
            sv[i] = new SVCQ;
        else
            sv[i] = new SVLT;
        sv[i]->Nhap();
    }
}

SV* TruongDH::Nhap1()
{
    int loai;
    SV* s;
    do
    {
        cout << "Nhap loai (1 : SVCQ , 2 : SVLT): ";
        cin >> loai;
    } while (loai < 1 || loai > 2);
    if (loai == 1)
        s = new SVCQ;
    else
        s = new SVLT;
    s->Nhap();
    return s;
}

void TruongDH::Xuat()
{
    for (int i = 0; i < sl; i++)
    {
        sv[i]->Xuat();
    }
}

void TruongDH::LietKeSinhVienDRL100()
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->GetLoai() == "SVCQ" && sv[i]->GetDRL() == 100)
        {
            sv[i]->Xuat();
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co sinh vien chinh quy nao co diem ren luyen bang 100\n";
}

int TruongDH::SoLuongSVLTKhongnghi()
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->GetLoai() == "SVLT" && sv[i]->GetSBV() == 0)
            dem++;
    }
    if (dem == 0)
        cout << "Khong co sinh vien lien thong nao khong nghi buoi nao\n";
    return dem;
}

long TruongDH::TongHocBong()
{
    long tong = 0;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->HocBong() != 0)
        {
            tong += sv[i]->HocBong();
        }
    }
    return tong;
}

double TruongDH::DiemTBSVCoHocBong()
{
    double dtb = 0, dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->GetLoai() == "SVCQ" && sv[i]->HocBong() != 0)
        {
            dtb += sv[i]->GetDiemTB();
            dem++;
        }
    }
    if (dem == 0)
        ;
    else
        return dtb / dem;
}

bool TruongDH::SVLTDTBtu9vaKhongNghi()
{
    bool kt = false;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->GetLoai() == "SVLT" && sv[i]->GetSBV() == 0 && sv[i]->GetDiemTB() >= 9)
        {
            kt = true;
            break;
        }
    }
    return kt;
}

void TruongDH::SVCQcoDiemTBCaoNhat()
{
    double max;
    for (int i = 0; i < sl; i++) {
        max = sv[0]->GetDiemTB();
        if (sv[i]->GetLoai() == "SVCQ" && sv[i]->GetDiemTB() > max) {
            max = sv[i]->GetDiemTB();
        }
    }
    for (int i = 0; i < sl; i++) {
        if (sv[i]->GetDiemTB() == max) {
            sv[i]->Xuat();
        }
    }
}

string TruongDH::DoiChuInHoa(string str)
{
    for (int i = 0; i < sl; i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

string TruongDH::DoiChuInThuong(string str)
{
    for (int i = 0; i < sl; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

void TruongDH::SapXepTangTheoMaSo()
{
    for (int i = 0; i < sl; i++)
    {
        for (int j = 0; j < sl; j++)
        {
            if (DoiChuInHoa(sv[i]->GetMSSV()) > DoiChuInHoa(sv[i]->GetMSSV()))
            {
                SV* tam = sv[i];
                sv[i] = sv[j];
                sv[j] = tam;
            }
        }
    }
}

void TruongDH::Them1SV(SV* pdt, int vt)
{
    SV** pnew = new SV * [sl + 1];
    for (int i = 0; i < vt - 1; i++)
    {
        pnew[i] = sv[i];
    }
    pnew[vt - 1] = pdt;
    for (int i = vt; i < sl + 1; i++)
        pnew[i] = sv[i - 1];
    delete[] sv;
    sv = pnew;
    sl++;
}

int TruongDH::Xoa1SV(string ms)
{
    int vt = -1;
    for (int i = 0; i < sl; i++)
    {
        if (DoiChuInHoa(sv[i]->GetMSSV()) == DoiChuInHoa(ms))
        {
            vt = i;
            break;
        }
    }
    if (vt != -1)
    {
        SV** pnew = new SV * [sl - 1];
        for (int i = 0; i < vt; i++)
            pnew[i] = sv[i];
        for (int i = vt; i < sl - 1; i++)
            pnew[i] = sv[i + 1];
        delete[] sv;
        sv = pnew;
        sl--;
    }
    else
        cout << "Khong tim thay sinh vien nao co ma so nay\n";
    return vt;
}

void TruongDH::TimSVtheoMSSV(string ms)
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (DoiChuInHoa(sv[i]->GetMSSV()) == DoiChuInHoa(ms))
        {
            sv[i]->Xuat();
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co sinh vien nao thuoc ma so " << ms << endl;
}

void TruongDH::TimSVtheoTen(string ht)
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (DoiChuInHoa(sv[i]->GetName()) == DoiChuInHoa(ht))
        {
            sv[i]->Xuat();
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co sinh vien nao co ten " << ht << endl;
}

void TruongDH::TimSVtheoKhoa(string kh)
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (DoiChuInHoa(sv[i]->GetKhoa()) == DoiChuInHoa(kh))
        {
            sv[i]->Xuat();
            dem++;
        }
    }
    if (dem == 0)
        cout << "Khong co sinh vien nao thuoc khoa " << kh << endl;
}

void TruongDH::TimSVtheoDTB(double dtb)
{
    int dem = 0;
    for (int i = 0; i < sl; i++)
    {
        if (sv[i]->GetDiemTB() == dtb)
        {
            sv[i]->Xuat();
            dem++;
        }
    }
    cout << "Khong co sinh vien nao co diem trung binh la " << dtb << endl;
}
