#include <iostream>
#include <stdlib.h>
using namespace std;

class MTVuong {
private:
    int n;
    int **p;
public:
    MTVuong();
    ~MTVuong();
    MTVuong(int n);
    MTVuong(const MTVuong&);
    friend istream& operator >> (istream& in,MTVuong& m);
    friend ostream& operator << (ostream& out,MTVuong& m);
    MTVuong& operator=(const MTVuong&);
    void Lietke();
    bool Tontaiphantuam();
    int Phantuchan();
    void swap(int &a,int &b);
    void Sapxepmanggiamdan();
};

MTVuong::~MTVuong() {
    for (int i=0;i<n;i++) {
        delete p[i];
    }
    delete p;
    p=NULL;
    cout << "Da huy mot ma tran vuong! \n";
}

MTVuong::MTVuong() {
    n=0;
    p=NULL;
}

MTVuong::MTVuong(int n) {
    while (n<=0) {
        cout << "Nhap n > 0: ";
        cin >> n;
    }
    this->n=n;
    p=new int*[n];
    for(int i=0;i<n;i++) {
        p[i]=new int [n];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            p[i][j]=0;
        }
    } 
}

MTVuong::MTVuong(const MTVuong& m) {
    n=m.n;
    p=new int*[n];
    for (int i=0;i<n;i++) {
        p[i]=new int[n];
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            p[i][j]=m.p[i][j];
        }
    }
} 

istream& operator>>(istream& in,MTVuong& m) {
    if (m.p!=NULL) {
        m.~MTVuong();
    }
    do {
        cout << "Nhap n>0:";
        in >> m.n;
    }while (m.n<=0);
    m.p=new int*[m.n];
    for (int i=0;i<m.n;i++) {
        m.p[i]=new int[m.n];
    }
    for (int i=0;i<m.n;i++) {
        for (int j=0;j<m.n;j++) {
            cout << "p[" << i << "][" << j << "] = ";
            in >> m.p[i][j];
        }
    }
    return in;
}

ostream& operator << (ostream& out,MTVuong& m) {
    if (m.p==NULL) {
        out << "Ma tran rong\n";
    }
    else {
        for (int i=0;i<m.n;i++) {
            for (int j=0;j<m.n;j++) {
                out << m.p[i][j] << " ";
            }
            cout << endl;
        }
    }
    return out;
}

MTVuong& MTVuong::operator=(const MTVuong& m) {
    n=m.n;
    p=new int*[n];
    for (int i=0;i<n;i++) {
        p[i]=new int[n];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            p[i][j]=m.p[i][j];
        }
    }
}

void MTVuong::Lietke() {
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) {
                if (p[i][j]%2!=0) {
                    cout << p[i][j] << " ";
                }
            }
        }
    }
    cout << "\n";
}

bool MTVuong::Tontaiphantuam() {
    for (int i=0;i<n;i++) {
        for (int j=i;j<n;j++) {
            if (i==j) {
                if (p[i][j]<0) return true;
            }
        }
    }
    return false;
}

int MTVuong::Phantuchan() {
    for (int i=0;i<n;i++) {
        for (int j=n-1-i;j<n;j++) {
            if (p[i][j]%2==0) {
                return p[i][j];
            }
        }
    }
}

void MTVuong::swap(int &a,int &b) {
    int temp=a;
    a=b;
    b=temp;
}

void MTVuong::Sapxepmanggiamdan() {
    for (int i=0;i<n;i++) {
        for (int j=n-i-1;j<n;j++) {
            if (p[i][j]>p[j][i]) {
                this->swap(p[i][j],p[j][i]);
            }
        }
    }
}

int main() {
    system("cls");
    MTVuong *m1=new MTVuong,m2(3);
    cout << "Ma tran vuong 1 la: " << *m1 << "\nMa tran vuong 2 la: \n" << m2 << endl;
    cout << "Nhap lai ma tran vuong 1: \n";
    cin >> *m1;
    cout << "Ma tran vuong 1 moi la: \n" << *m1 <<endl;
    MTVuong m4,m5;
    m4=*m1, m5=*m1;
    cout << "Ma tran vuong m4 la: \n" << m4 << endl;
    cout << "Ma tran vuong m5 la: \n" << m5 << endl;
    delete m1;
    cout << "Da xoa 1 ma tran vuong!" << endl;
    cout << "Ma tran vuong m4 la: \n" << m4 << endl;
    cout << "Ma tran vuong m5 la: \n" << m5 << endl;
    cout << "Cac gia tri le nam tren duong cheo chinh la: "; m4.Lietke();
    if (m4.Tontaiphantuam()==true) {
        cout << "Ton tai phan tu am nam duoi duong cheo chinh" << endl;
    }
    else {
         cout << "Khong ton tai phan tu am nam duoi duong cheo chinh" << endl;
    }
    cout << "Phan tu chan dau tien o phia duoi duong cheo phu la: " << m4.Phantuchan() << endl;
    m4.Sapxepmanggiamdan();
    cout << "Sap xep cac phan tu tren duong cheo phu theo huong giam dan la: \n"<<m4 << endl;
    system("pause");
    return 0;
}