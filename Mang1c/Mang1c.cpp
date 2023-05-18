#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>
using namespace std;

class Mang1C {
private:
    int n;
    int *a;
public:
    void SinhMang();
    Mang1C();
    Mang1C(int);
    Mang1C(int n , int m);
    //Mang1C(int = 0 , int = 0);
    Mang1C(const Mang1C&);
    ~Mang1C();
    int GetN();
    int *GetA();
    friend istream& operator>>(istream& in,Mang1C &m);
    friend ostream& operator<<(ostream& out,const Mang1C &m);
    Mang1C& operator=(const Mang1C&);
    bool Kiemtrasonguyento(int k);
    void Lietkenguyento();
    bool Kiemtrachinhphuong(int k);
    int Demsoluongchinhphuong();
    bool Kiemtrasohoanthien(int k);
    int Tongsohoanthien();
    int Sodaonguoc(int k);
    bool Kiemtrasodoixung(int k);
    double TBCongsodoixung();
    bool Mangtoanphantule();
    int Phantuchanbenhat();
    void swap(int &a,int &b);
    void Sapxepmangtangdan();
    void Xoaphantu();
    void Themphantu();
    int Timkiem();
};

void Mang1C::SinhMang() {
    srand(time(NULL));
    for (int i=0;i<n;i++) {
        a[i]=rand()%20;
    }
}

Mang1C::~Mang1C() {
    n=0;
    delete[] a;
    a=NULL;
    cout << "Da huy mang 1 chieu\n";
} 

Mang1C::Mang1C() {
    n=0;
    a=NULL;
}

Mang1C::Mang1C(int n) {
    while (n<=0) {
        cout << "Nhap lai n > 0:";
        cin >> n;
    }
    this->n=n;
    a=new int[this->n];
    for (int i=0;i<this->n;i++) {
        a[i]=0;
    }
}

Mang1C::Mang1C(int n,int m) {
    if (n==0) {
        this->a=0;
        a=NULL;
    }
    else {
        while (n<=0) {
            cout << "Nhap lai n > 0: ";
            cin >> n;
        }
        this->n=n;
        a=new int[this->n];
        for (int i=0;i<this->n;i++) {
            a[i]=m;
        }
    }
}

Mang1C::Mang1C(const Mang1C& m) {
    n=m.n;
    a=new int[n];
    for (int i=0;i<n;i++) {
        a[i]=m.a[i];
    }
}

int Mang1C::GetN() {
    return n;
}

int* Mang1C::GetA (){
    return a;
}

istream& operator>> (istream& in,Mang1C& m) {
    if (m.a!=NULL) {
        m.~Mang1C();
    }
    do {
        cout << "Nhap n > 0:";
        in >> m.n;
    }while (m.n<=0);
    m.a=new int[m.n];
    for (int i=0;i<m.n;i++) {
        cout << "a[" << i << "] = ";
        in >> m.a[i];
    }
    return in;
}

ostream& operator << (ostream& out ,const Mang1C& m) {
    if (m.a==NULL) {
        out << "Mang rong\n";
    }
    else {
        for (int i=0;i<m.n;i++) {
            out << m.a[i] << " ";
        }
    }
    return out;
}

Mang1C& Mang1C::operator=(const Mang1C& m) {
    n=m.n;
    a=new int[n];
    for (int i=0;i<n;i++) {
        a[i]=m.a[i];
    }
    return *this;
}

bool Mang1C::Kiemtrasonguyento(int k) {
    if (k<2) return false;
    for (int i=2;i<=sqrt(k);i++) {
        if (k%i==0) {
            return false;
        }
    }
    return true;
}

void Mang1C::Lietkenguyento() {
    for (int i=0;i<n;i++) {
        if (this->Kiemtrasonguyento(a[i])==true) {
            cout << a[i] << " " ;
        }
    }
    cout << "\n";
}

bool Mang1C::Kiemtrachinhphuong(int k) {
    if (k<1) return false;
    int i=1;
    while (i<=sqrt(k)) {
        if (i==sqrt(k)) {
            return true;
        }i++;
    }
    return false;
}

int Mang1C::Demsoluongchinhphuong() {
    int dem=0;
    for (int i=0;i<n;i++) {
        if (this->Kiemtrachinhphuong(a[i])==true) {
            dem++;
        }
    }
    return dem;
}

bool Mang1C::Kiemtrasohoanthien(int k) {
    int sum=0;
    for (int i=1;i<=k/2;i++) {
        if (k%i==0) sum+=i;
    }
    if (sum==k) return true;
    return false;
}

int  Mang1C::Tongsohoanthien() {
    int sum=0;
    for (int i=0;i<n;i++) {
        if (this->Kiemtrasohoanthien(a[i])==true) {
            sum+=a[i];
        }
    }
    return sum;
}

int Mang1C::Sodaonguoc(int k) {
    int sodaonguoc=0;
    while (k>0) {
        sodaonguoc=sodaonguoc*10+k%10;
        k/=10;
    }
    return sodaonguoc;
}

bool Mang1C::Kiemtrasodoixung(int k) {
    if (Sodaonguoc(k)==k) return true;
    return false;
}

double Mang1C::TBCongsodoixung() {
    float TBC=0;
    int dem=0;
    for (int i=0;i<n;i++) {
        if (Kiemtrasodoixung(a[i])==true) {
            TBC += a[i];
            dem++;
        }
    }
    if (dem == 0) return 0;
    else TBC=TBC/dem;
    return TBC;
}

bool Mang1C::Mangtoanphantule() {
    for (int i=0;i<n;i++) {
        if (a[i]%2==0) return false;
    }
    return true;
}

int Mang1C::Phantuchanbenhat() {
    int dem=0,min;
    for (int i=0;i<n;i++) {
        if (a[i]%2==0) {
            dem++;
            min=a[i];
            break;
        }
    }
    if (dem==0) return 0;
    for (int i=0;i<n;i++) {
        if (a[i]%2==0 && min>a[i]) {
            min=a[i];
        }
    }
    return min;
}

void Mang1C::swap(int &a,int &b) {
    int temp=a;
    a=b;
    b=temp;
}

void Mang1C::Sapxepmangtangdan() {
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (a[i]>a[j]) {
                this->swap(a[i],a[j]);
            }
        }
    }
}

void Mang1C::Xoaphantu() {
    int x; 
    cout << "Nhap vi tri muon xoa: ";
    cin >> x;
    if (x<0) {
        return;
    }
    else if (x>=n) {
        return;
    }
    for (int i=x;i<n;i++) {
        a[i]=a[i+1];
    }
    n--;
}

void Mang1C::Themphantu() {
    int x;
    cout << "Nhap vi tri muon them: ";
    cin >> x;
    int y;
    cout << "Nhap gia tri muon them: ";
    cin >> y;
    if (x<0) {
        x=0;
    }
    else if (x>=n) {
        x=n;
    }
    for (int i=n-1;i>=x;i--) {
        a[i]=a[i-1];
    }
    a[x]=y;
    n++;
}

int Mang1C::Timkiem() {
    int x;
    cin >> x;
    cout << "Phan tu ban tim kiem o vi tri: ";
    for (int i=0;i<n;i++) {
        if (a[i]==x) return i;
    }
    return -1;
}

int main() {
    system("cls");
    Mang1C *m1=new Mang1C,m2(5),m3(3,7);
    cout << "Mang 1: "<< *m1 << "\nMang 2: " << m2 << "\nMang 3: " << m3 << endl;
    cout << "Nhap lai mang 1: \n";
    cin >> *m1;
    cout << "Mang 1 moi: " << *m1 << endl;
    Mang1C m4(*m1),m5,m6;
    m5=m6=*m1;
    cout << "Mang 4: " << m4 << endl;
    cout << "Mang 5: " << m5 << endl;
    cout << "Mang 6: " << m6 << endl;
    delete m1;
    cout << "Da xoa 1 mang\n";
    cout << "Mang 4: " << m4 << endl;
    cout << "Mang 5: " << m5 << endl;
    cout << "Mang 6: " << m6 << endl;
    cout << "So phan tu la so nguyen to trong mang m4 la: " ;
    m4.Lietkenguyento();
    cout << "so phan tu chinh phuong trong mang m4 la: ";
    cout << m4.Demsoluongchinhphuong() << endl;
    cout << "Tong cac so hoan thien trong mang m4 la: ";
    cout << m4.Tongsohoanthien() << endl;
    cout << "TBC cac so doi xung trong mang m4 la: " ;
    cout << m4.TBCongsodoixung() << endl;
    if (m4.Mangtoanphantule()==true) {
        cout << "Mang m4 toan phan tu le!" << endl;
    } 
    else {
        cout << "Mang m4 khong phai mang toan phan tu le!" << endl;
    }
    cout << "Phan tu chan be nhat cua mang m4 la: " << m4.Phantuchanbenhat() << endl;
    m4.Sapxepmangtangdan();
    cout << "Mang m4 theo thu tu tang dan la: " << m4 << endl;
    m4.Xoaphantu();
    cout << "Xoa phan tu bat ky cua m4 la: " << m4 << endl;
    m4.Themphantu();
    cout << "Them phan tu bat ky cua m4 la: " << m4 << endl;
    cout << "Nhap phan tu ban muon tim trong mang m4: " << m4.Timkiem()  << endl;
    system("pause");
    return 0;
}