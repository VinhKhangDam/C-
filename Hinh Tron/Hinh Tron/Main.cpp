#include "HTron.h"

void main() {
	Diem C(4, 5);
	double r = 8;
	Htron ht(C, r);
	cout << "Hinh tron duoc khoi tao ban dau la: " << ht << endl;
	int chon;
	while (1) {
			cout << "---------HINH TRON------------\n";
			cout << "0.Thoat CT\n";
			cout << "1.Nhap hinh tron\n";
			cout << "2.Nhap gia tri cua tam hinh tron\n";
			cout << "3.Nhap gia tri cua ban kinh hinh tron\n";
			cout << "4.Xuat hinh tron\n";
			cout << "5.Di chuyen hinh tron\n";
			cout << "6.Tinh chu vi\n";
			cout << "7.Tinh dien tich\n";
			cout << "Ban chon :";
			cin >> chon;
			if (chon == 0) {
				return ;
			}
			else if (chon == 1) {
				cin >> ht;
			}
			else if (chon == 2) {
				cin >> C;
				ht.SetTam(C);
			}
			else if (chon == 3) {
				cout << "Nhap ban kinh: r = ";
				cin >> r;
				ht.SetR(r);
			}
			else if (chon == 4) {
				cout << ht << "\n";
			}
			else if (chon == 5) {
				double dx, dy;
				cout << "Nhap dx: "; cin >> dx;
				cout << "Nhap dy: "; cin >> dy;
				ht.DiChuyen(dx, dy);
			}
			else if (chon == 6) {
				cout << "Chu vi cua hinh tron la: " << ht.TinhChuVi() << endl;
			}
			else if (chon == 7) {
				cout << "Dien tich cua hinh tron la: " << ht.TinhDienTich() << endl;
			}
			cout << "------------------------------------\n";
	}
	system("pause");
}