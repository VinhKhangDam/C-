#include "NVSX.h"
#include "NVVP.h"

void main() {
	//test NVSX
	cout << "-----NHAN VIEN SAN XUAT--------\n";
	NVSX n1, n2("Nguyen Van A","22/10/2004",3500000,24), n3("Nguyen Van B", "22/10/1999",3500000,12), n4("Nguyen Van A", "11/01/2000", 5000000, 12);
	cout << "Nhan vien 1 la: " << n1 << "\nNhan vien 2 la: " << n2 << "\nNhan vien 3 la: " << n3 << "\nNhan vien 4 la: " << n4 << endl;
	cout << "Nhap thong tin nhan vien so 1: ";
	cin >> n1;
	cout << "\n";
	cout << "Thong tin n1 sau khi nhap la: \n" << n1 << endl;
	cout << "----------------------------\n";

	//test NVVP
	cout << "-----NHAN VIEN VAN PHONG-------\n";
	NVVP e1, e2("Nguyen Van Chien","11/10/2004",300), e3("Nguyen Van Bao", "23/11/2000",265), e4("Le Gia Bao", "21/10/1998", 200);
	cout << "Nhan vien 1 la: " << e1 << "\nNhan vien 2 la: " << e2 << "\nNhan vien 3 la: " << e3 << "\nNhan vien 4 la: " << e4 << endl;
	cout << "Nhap thong tin nhan vien so 1 : ";
	cin >> e1;
	cout << "\n";
	cout << "Thong tin nhan vien so 1 sau khi nhap la: \n" << e1 << endl;
	cout << "----------------------------\n";
	system("pause");
}