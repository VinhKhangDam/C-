#include "HCNhat.h"
int main() {
	Diem A(3,4), B;
	HCNhat hcn(A, B);
	cout << "Hinh chu nhat duoc khoi tao ban dau la:\n";
	cout << hcn;
	while (1) {
		cout << "-----------------------------------------\n";
		int choice = 0;
		cout << "Ban muon lam gi?\n";
		cout << "0. Thoat\n";
		cout << "1. Nhap hinh chu nhat\n";
		cout << "2. Nhap gia tri cua diem A\n";
		cout << "3. Nhap gia tri cua diem B\n";
		cout << "4. Xuat hinh chu nhat\n";
		cout << "5. Di chuyen hinh chu nhat\n";
		cout << "6. Tinh chu vi\n";
		cout << "7. Tinh dien tich\n";
		cout << "8. Xuat chieu dai va chieu rong hinh chu nhat\n";
		cout << "Your choice: ";
		cin >> choice;
		if (choice == 0)
			return 0;
		else if (choice == 1) {
			cin >> hcn;
		}
		else if (choice == 2) {
			cin >> A;
			hcn.SetA(A);
		}	
		else if (choice == 3) {
			cin >> B;
			hcn.SetB(B);
		}
		else if (choice == 4) {
			cout << hcn;
		}
		else if (choice == 5) {
			int dx, dy;
			cout << "Nhap dx: ";
			cin >> dx;
			cout << "Nhap dy: ";
			cin >> dy;
			hcn.DiChuyenHCN(dx, dy);
		}
		else if (choice == 6) {
			cout << "Chu vi hinh chu nhat = " << hcn.TinhChuVi() << '\n';
		}
		else if (choice == 7) {
			cout << "Dien tich hinh chu nhat = " << hcn.TinhDienTich() << '\n';
		}
		else if (choice == 8) {
			cout << "Chieu dai = " << hcn.GetDai() << '\n';
			cout << "Chieu rong = " << hcn.GetRong() << '\n';
		}
		cout << "-----------------------------------------\n";
	}
}
