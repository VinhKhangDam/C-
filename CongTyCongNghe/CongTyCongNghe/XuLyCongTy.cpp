#include "CongTy.h"

CongTy::CongTy() {
	nv = NULL;
	sluong = 0;
}

CongTy::~CongTy() {
	for (int i = 0; i < sluong; i++) {
		delete nv[i];
	}
	delete[] nv;
	nv = NULL;
	sluong = 0;
}

int CongTy::GetSLuong() { return sluong; }

void CongTy::Nhap() {
	int loai;
	do {
		cout << "Nhap so luong nhan vien: ";
		cin >> sluong;
	} while (sluong < 1);
	nv = new NhanVien * [sluong];
	for (int i = 0; i < sluong; i++) {
		cout << "-----------\n";
		cout << "Nhap thong tin nhan vien thu " << i + 1 << ":\n";
		do {
			cout << "Nhap loai (1.Lap Trinh Vien, 2.Kiem chung vien): ";
			cin >> loai;
		} while (loai < 1 || loai>2);
		if (loai == 1)
			nv[i] = new LTV;
		else
			nv[i] = new KCV;
		nv[i]->Nhap();
	}
}

NhanVien* CongTy::Nhap1() {
	int loai;
	NhanVien* pdt;
	do {
		cout << "Nhap loai (1.Lap Trinh Vien, 2.Kiem chung vien): ";
		cin >> loai;
	} while (loai < 1 || loai>2);
	if (loai == 1)
		pdt = new LTV;
	else
		pdt = new KCV;
	pdt->Nhap();
	return pdt;
}

void CongTy::Xuat() {
	for (int i = 0; i < sluong; i++) {
		nv[i]->Xuat();
	}
}

long CongTy::LuongTrungBinh() {
	long ltb = 0;
	int dem = 0;
	for (int i = 0; i < sluong; i++) {
		if (nv[i]->Luong() > 0) {
			ltb += nv[i]->Luong();
			dem++;
		}
	}
	return ltb / dem;
}

void CongTy::NhanVienCoLuongThapHon() {
	for (int i = 0; i < sluong; i++) {
		if (nv[i]->Luong() < CongTy::LuongTrungBinh()) {
			nv[i]->Xuat();
		}
	}
}

void CongTy::TimNhanVienCoMucLuongToiThieu(long ltt) {
	int dem = 0;
	for (int i = 0; i < sluong; i++) {
		if (nv[i]->Luong() == ltt) {
			nv[i]->Xuat();
			dem++;
		}
	}
	if (dem == 0)
		cout << "Khong co nhan vien nao co muc luong toi thieu la " << ltt << endl;
}