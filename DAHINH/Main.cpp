#include "TruongDH.h"
#include <string>
#include <stdlib.h>
int main()
{
    system("cls");
    TruongDH tr;
    int chon;
    do
    {
        cout << "=====CHUONG TRINH QUAN LI SINH VIEN CUA TRUONG======\n";
        cout << "1. Nhap d/s du lieu sinh vien\n";
        cout << "2. Xuat d/s du lieu sinh vien\n";
        cout << "3. Liet ke d/s cac sinh vien chinh quy co diem ren luyen ban 100\n";
        cout << "4. So luong sinh vien lien thong khong nghi buoi nao\n";
        cout << "5. Tong hoc bong cap cho cac sinh vien\n";
        cout << "6. Diem trung binh cua cac sinh vien duoc cap hoc bong\n";
        cout << "7. Cac sinh vien chinh quy co diem trung binh cao nhat\n";
        cout << "8. D/s cac sinh vien tang dan theo ma so\n";
        cout << "9. Them 1 sinh vien moi\n";
        cout << "10. Xoa 1 sinh vien co ma so do nguoi dung nhap\n";
        cout << "11. Kiem tra sinh vien lien thong co DTB tu 9 tro len va khong nghi buoi nao\n";
        cout << "12. Tim kiem sinh vien theo ma so\n";
        cout << "13. Tim kiem sinh vien theo ten\n";
        cout << "14. Tim kiem sinh vien theo khoa\n";
        cout << "15.Tim kiem sinh vien theo diem trung binh\n";
        cout << "0. Thoat CT\n";
        cout << "===============================================================\n";
        cout << "Ban chon: ";
        cin >> chon;
        switch (chon)
        {
        case 0:
            if (tr.GetSL() > 0)
                tr.~TruongDH();
            cout << "Dang thoat chuong trinh\n";
            break;
        case 1:
            if (tr.GetSL() > 0)
                tr.~TruongDH();
            tr.Nhap();
            break;
        case 2:
            if (tr.GetSL() > 0)
                tr.Xuat();
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 3:
            if (tr.GetSL() > 0)
                tr.LietKeSinhVienDRL100();
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 4:
            if (tr.GetSL() > 0)
            {
                int dem = tr.SoLuongSVLTKhongnghi();
                if (dem > 0)
                    cout << "Co " << dem << " sinh vien khong nghi buoi nao\n";
                else
                    cout << "Khong co sinh vien nao khong nghi buoi nao\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 5:
            if (tr.GetSL() > 0)
            {
                long tong = tr.TongHocBong();
                if (tong > 0)
                    cout << "Tong hoc bong cho sinh vien la: " << tong << "\n";
                else
                    cout << "Khong co hoc bong nao sinh vien duoc nhan\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 6:
            if (tr.GetSL() > 0)
            {
                double dtb = tr.DiemTBSVCoHocBong();
                if (dtb > 0)
                    cout << "Diem trung binh sinh vien co hoc bong la: " << dtb << "\n";
                else
                    cout << "Khong co sinh vien nao nhan hoc bong\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 7:
            if (tr.GetSL() > 0)
            {
                cout << "Sinh vien chinh quy co diem trung binh cao nhat la: \n";
                tr.SVCQcoDiemTBCaoNhat();
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 8:
            if (tr.GetSL() > 0)
            {
                tr.SapXepTangTheoMaSo();
                tr.Xuat();
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 9:
        {
            SV* pdt;
            int vt = 1;
            pdt = tr.Nhap1();
            if (tr.GetSL() > 0)
            {
                do
                {
                    cout << "Nhap vi tri muon them SV tu 1 den " << tr.GetSL() + 1 << ": ";
                    cin >> vt;
                } while (vt < 1 || vt > tr.GetSL() + 1);
            }
            tr.Them1SV(pdt, vt);
            cout << "D/s sinh vien sau khi them la: " << vt << "\n";
            tr.Xuat();
            break;
        }
        case 10:
            if (tr.GetSL() > 0)
            {
                string ms;
                cout << "Nhap ma so muon xoa: \n";
                cin >> ms;
                int kq = tr.Xoa1SV(ms);
                if (kq != -1)
                {
                    if (tr.GetSL() > 0)
                    {
                        cout << "D/s sinh vien sau khi xoa sinh vien co ma so: " << ms << " la: \n";
                        tr.Xuat();
                    }
                    else
                    {
                        cout << "D/s sinh vien rong\n";
                    }
                }
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 11:
            if (tr.GetSL() > 0)
            {
                if (tr.SVLTDTBtu9vaKhongNghi())
                    cout << "Co sinh vien lien thong co dtb tu 9 va khong nghi buoi nao\n";
                else
                    cout << "Khong co sinh vien lien thong co dtb tu 9 va khong nghi buoi nao\n";
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 12:
            if (tr.GetSL() > 0)
            {
                string ms;
                cin.ignore();
                cout << "Nhap ma so can tim: ";
                getline(cin, ms);
                tr.TimSVtheoMSSV(ms);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 13:
            if (tr.GetSL() > 0)
            {
                string ht;
                cin.ignore();
                cout << "Nhap ho ten can tim: ";
                getline(cin, ht);
                tr.TimSVtheoTen(ht);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 14:
            if (tr.GetSL() > 0)
            {
                string kh;
                cin.ignore();
                cout << "Nhap khoa can tim: ";
                getline(cin, kh);
                tr.TimSVtheoKhoa(kh);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        case 15:
            if (tr.GetSL() > 0)
            {
                double dtb;
                cout << "Nhap diem trung binh can tim: ";
                cin >> dtb;
                tr.TimSVtheoDTB(dtb);
            }
            else
                cout << "Chua nhap thong tin\n";
            break;
        default:
            cout << "Ban chon sai roi.Moi ban chon lai\n";
            break;
        }
    } while (chon != 0);
    system("pause");
    return 0;
}
