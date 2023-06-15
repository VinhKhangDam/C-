#include "CongTy.h"

void main() {
	CongTy ct;
	int chon;
	do {
		cout << "=======================CHUONG TRINH QUAN LY THONG TIN NHAN VIEN=========================\n";
		cout << "1.Nhap danh sach nhan vien\n";
		cout << "2.Xuat danh sach nhan vien\n";
		cout << "3.Liet ke danh sach cac nhan vien co muc luong thap hon muc luong trung binh cua cong ty\n";
		cout << "4.Tim nhan vien co muc luong toi thieu\n";
		cout << "0.Thoat CT\n";
		cout << "========================================================================================\n";
		cout << "Ban chon: "; cin >> chon;
		switch (chon) {
		case 0:
			if (ct.GetSLuong() > 0)
				ct.~CongTy();
			cout << "Dang thoat chuong trinh...";
			break;
		case 1:
			if (ct.GetSLuong() > 0)
				ct.~CongTy();
			ct.Nhap();
			break;
		case 2:
			if (ct.GetSLuong() > 0) {
				ct.Xuat();
			}
			else {
				cout << "Chua nhap thong tin\n";
			}
			break;
		case 3:
			if (ct.GetSLuong() > 0) {
				ct.NhanVienCoLuongThapHon();
			}
			else
				cout << "Chua nhap thong tin\n";
			break;
		case 4:
			if (ct.GetSLuong() > 0) {
				long ltt;
				cout << "Nhap luong toi thieu: ";
				cin >> ltt;
				ct.TimNhanVienCoMucLuongToiThieu(ltt);
			}
			else
				cout << "Chua nhap thong tin\n";
		default:
			cout << "Ban chon sai.Moi chon lai!\n";
		}

	}while (chon != 0);
}