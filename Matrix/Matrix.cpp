#include <iostream>
#include<cmath>
#include <stdlib.h>
using namespace std;

class MaTran {
private:
    int sd,sc;
    int **p;
public:
    MaTran();
    MaTran(int d ,int c,int a);
    MaTran(const MaTran&);
    ~MaTran();
    int getSd();
    int getSc();
    int **getP();
    friend istream& operator>> (istream& in,MaTran &);
    friend ostream& operator<< (ostream& out,MaTran&);
    MaTran& operator=(const MaTran&);
    bool Kiemtranguyento(int k);
    void Lietke();
    bool KiemtrasoCP(int k);
    int SoluongphantuCP();
    bool Kiemtrasohoanthien(int k);
    int Tongsohoanthien();
    int Sodaonguoc(int k);
    bool Kiemtrasodoixung(int k);
    double TBCongsodoixung();
    void swap(int &a,int &b);
    void Sapxepmangtangdan();
};

MaTran::~MaTran() {
    sd=0;
    for (int i=0;i<sc;i++) {
        delete[] p[i];
    }
    delete[] p;
    p=NULL;
    cout << "Da huy 1 ma tran\n";
}

MaTran::MaTran() {
    sd=0;sc=0;
    p=NULL;
}

MaTran::MaTran(int d,int c,int a) {
    while (d<=0) {
        cout << "Nhap lai so dong > 0: ";
        cin >> d;
    }
    while (c<=0) {
        cout << "Nhap lai so cot > 0: ";
        cin >>  c;
    }
    p=new int *[d];
    for (int i=0;i<d;i++) {
        p[i]=new int [c];
    }
    for (int i=0;i<d;i++) {
        for (int j=0;j<c;j++) {
            p[i][j]=a;
        }
    }
}

MaTran::MaTran(const MaTran& m) {
    sd=m.sd;
    sc=m.sc;
    p=new int *[sd];
    for (int i=0;i<sd ;i++) {
        p[i]=new int[sc];
    }
    for (int i=0;i<sd;i++) {
        for (int j=0;j<sc;j++) {
            p[i][j]=m.p[i][j];
        }
    }
}

int MaTran::getSd() {
    return sd;
}

int MaTran::getSc() {
    return sc;
}

int** MaTran::getP() {
    return p;
}

istream& operator>> (istream& in,MaTran& m) {
    if (m.p!=NULL) {
        m.~MaTran();
    }
    do {
        cout << "Nhap lai so dong > 0 :";
        in >> m.sd;
        cout << "Nhap lai so cot > 0: ";
        in >> m.sc;
    }while (m.sd<=0 || m.sc<=0);
    m.p=new int *[m.sd];
    for (int i=0;i<m.sd;i++) {
        m.p[i] =new int[m.sc];
    }
    for (int i=0;i<m.sd;i++) {
        for (int j=0;j<m.sc;j++) {
            cout << "p["<<i<<"][" << j <<"] = ";
            in >> m.p[i][j];
        }
    }
    return in;
}

ostream& operator << (ostream& out, MaTran& m) {
    if (m.p==NULL) {
        out << "Ma tran rong\n";
    }
    else {
        for (int i=0;i<m.sd;i++) {
            for (int j=0;j<m.sc;j++) {
                out << m.p[i][j] << " ";
            }
            cout << endl;
        }
    }
    return out;
}

MaTran& MaTran::operator=(const MaTran& m) {
    sd=m.sd;sc=m.sc;
    p=new int *[sd];
    for (int i=0;i<sd;i++) {
        p[i]=new int[sc];
    }
    for (int i=0;i<sd;i++) {
        for (int j=0;j<sc;j++) {
            p[i][j]=m.p[i][j];
        }
    }
    return *this;
}

bool MaTran::Kiemtranguyento(int k) {
    if (k<2) return false;
    for (int i=2;i<=sqrt(k);i++) {
        if (k%i==0) {
            return false;
        }
    }
    return true;
}

void MaTran::Lietke() {
    for (int i=0;i<sd;i++) {
        for (int j=0;j<sc;j++) {
            if (this->Kiemtranguyento(p[i][j])==true) {
                cout << p[i][j] << " ";
            }
        }
    }
    cout << "\n";
}

bool MaTran::KiemtrasoCP( int k) {
    if (k<1) return false;
    int i=1;
    while (i<=sqrt(k)) {
        if (i==sqrt(k)) {
            return true;
        }i++;
    }
    return false;
}

int MaTran::SoluongphantuCP() {
    int dem=0;
    for (int i=0;i<sd;i++) {
        for (int j=0;j<sc;j++) {
            if (KiemtrasoCP(p[i][j])==true) {
                dem++;
            }
        }
    }
    return dem;
}

bool MaTran::Kiemtrasohoanthien(int k) {
    int sum=0;
    for (int i=1;i<=k/2;i++) {
        if (k%i==0) sum+=i;
    }
    if (sum==k) return true;
    return false;
}

int MaTran::Tongsohoanthien() {
    int sum=0;
    int k;
    cout << "Nhap dong ban muon tinh: ";
    cin >> k;
        for (int j=0;j<sc;j++) {
            if (this->Kiemtrasohoanthien(p[k][j])==true) {
                sum+=p[k][j];
            }
    }
    return sum;
}

int MaTran::Sodaonguoc(int k) {
    int sodaonguoc=0;
    while (k>0) {
        sodaonguoc=sodaonguoc*10+k%10;
        k/=10;
    }
    return sodaonguoc;
}

bool MaTran::Kiemtrasodoixung(int k) {
    if (Sodaonguoc(k)==k) return true;
    return false;
}

double MaTran::TBCongsodoixung() {
    float tbc=0;
    int dem=0;
    int k;
    cout << "Nhap cot ban muon tinh: ";
    cin >> k;
    for (int i=0;i<sd;i++) {
            if (Kiemtrasodoixung(p[i][k])==true) {
                tbc+=p[i][k];
                dem++;
        }
    }
    if (dem==0) return 0;
    else tbc=tbc/dem;
    return tbc;
}

void MaTran::swap(int &a,int &b) {
    int temp=a;
    a=b;
    b=temp;
}


void MaTran::Sapxepmangtangdan() {
    for (int k=0;k<sd;k++) {
        for (int i=0;i<sc-1;i++) {
            for (int j=sc-1;j>i;j--) {
                if (p[k][j]<p[k][j-1]) {
                    this->swap(p[k][j],p[k][j-1]);
                }
            }
        }
    }
}

int main() {
    system("cls");
    MaTran *mt1=new MaTran;
    cout << "Ma tran 1 la: \n";
    cout << "Nhap lai ma tran 1: \n";
    cin >> *mt1;
    cout << "Mang m1 moi la: \n" << *mt1 << endl;
    MaTran mt4,mt5;
    mt4=mt5=*mt1;
    cout << "Mang 4 la: \n" << mt4 << endl;
    cout << "Mang 5 la: \n" << mt5 << endl;
    delete mt1;
    cout << "Da xoa 1 ma tran\n";
    cout << "Mang 4 la: \n" << mt4 << endl;
    cout << "Mang 5 la: \n" << mt5 << endl;
    cout << "Cac gia tri cua ma tran mt4 la so nguyen to la: " ;
    mt4.Lietke();
    cout << "So phan tu chinh phuong trong ma tran mt4 la: ";
    cout << mt4.SoluongphantuCP() << endl;
    cout << "Tong cac so hoan thien trong ma tran mt4 la: " ;
    cout << mt4.Tongsohoanthien() << endl;
    cout << "Trung binh cong cac so doi xung la: ";
    cout << mt4.TBCongsodoixung() << endl;
    mt4.Sapxepmangtangdan();
    cout << "Sap xep ma tran tang dan la: \n" << mt4 << endl;
    system("pause");
    return 0;
}