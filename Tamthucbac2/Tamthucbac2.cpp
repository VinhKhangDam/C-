#include <iostream>
#include <cmath>
using namespace std;

class DathucB2 {
private:
    double a,b,c;
public:
    DathucB2();
    ~DathucB2();
    double getA() const;
    double getB() const;
    double getC() const;
    void setA(double);
    void setB(double);
    void setC(double);
    void setABC(double,double,double);
    friend istream& operator>> (istream& in,DathucB2 &DT);
    friend ostream& operator<< (ostream& out,const DathucB2 &DT);
    double giatri(int x0);
    DathucB2 operator+(const DathucB2 &DT);
};

DathucB2::DathucB2() {
    this->a = a;
    this->b = b;
    this->c = c;
}

DathucB2::~DathucB2() {

}

double DathucB2::getA() const {
    return a;
}

double DathucB2::getB() const {
    return b;
}

double DathucB2::getC() const {
    return c;
}

void DathucB2::setA(double a) {
    this->a=a;
}

void DathucB2::setB(double b) {
    this->b=b;
}

void DathucB2::setC(double c) {
    this->c=c;
}

void DathucB2::setABC(double a,double b,double c) {
    this->a=a;
    this->b=b;
    this->c=c;
}

istream& operator>>(istream& in,DathucB2& DT) {
    cout << "Nhap a!=0: " ;
    in >> DT.a;
    cout << "Nhap b: ";
    in >> DT.b;
    cout << "Nhap c: ";
    in >> DT.c;
    return in;
}

ostream& operator<< (ostream& out,const DathucB2& DT) {
    if (DT.a>0 && DT.b >0 && DT.c >0) {
        out << DT.a << "x^2 + " << DT.b << "x + " << DT.c;
    }
    else if (DT.a > 0 && DT.b > 0 && DT.c < 0) {
        out << DT.a << "x^2 + " << DT.b << "x - " << abs(DT.c);
    }
    else if (DT.a > 0 && DT.b <0 && DT.c > 0) {
        out << DT.a << "x^2 - " << abs(DT.b) << "x + " << DT.c;
    }
    else if (DT.a >0 && DT.b <0 && DT.c < 0) {
        out << DT.a << "x^2 - " << abs(DT.b) << "x - " << abs(DT.c);
    }
    else if (DT.a < 0 && DT.b >0 && DT.c >0) {
        out << "-" <<abs(DT.a) << "x^2 + " << DT.b << "x + " << DT.c;
    }
    else if (DT.a < 0 && DT.b > 0 && DT.c < 0) {
        out << "-" <<abs(DT.a) << "x^2 + " << DT.b << "x - " << abs(DT.c);
    }
    else if (DT.a < 0 && DT.b <0 && DT.c > 0) {
        out << "-" <<abs(DT.a) << "x^2 - " << abs(DT.b) << "x + " << DT.c;
    }
    else if (DT.a < 0 && DT.b <0 && DT.c < 0) {
        out << "-" <<abs(DT.a)<< "x^2 - " << abs(DT.b) << "x - " << abs(DT.c);
    }
    else if (DT.a > 0 && DT.b >0 && DT.c==0) {
        out  << DT.a << "x^2 + " << DT.b << "x";
    }
    else if (DT.a > 0 && DT.b <0 && DT.c==0) {
        out  << DT.a << "x^2 - " <<abs(DT.b) << "x";
    }
    else if (DT.a > 0 && DT.b ==0 && DT.c >0 ) {
        out  << DT.a << "x^2 +" << DT.c;
    }
    else if (DT.a > 0 && DT.b ==0 && DT.c <0 ) {
        out << DT.a << "x^2 -" << abs(DT.c);
    }
    else if (DT.a < 0 && DT.b >0 && DT.c==0) {
        out  << "-" <<abs(DT.a) << "x^2 + " << DT.b << "x";
    }
    else if (DT.a < 0 && DT.b <0 && DT.c==0) {
        out  << "-" <<abs(DT.a) << "x^2 - " <<DT.b << "x";
    }
    else if (DT.a < 0 && DT.b ==0 && DT.c >0 ) {
        out  << "-" <<abs(DT.a) << "x^2 +" << DT.c;
    }
    else if (DT.a < 0 && DT.b ==0 && DT.c <0 ) {
        out  << "-" <<abs(DT.a) << "x^2 -" << DT.c;
    }
    else if (DT.a > 0 && DT.b==0 && DT.c==0) {
         out  << DT.a << "x^2";
    }
    else if (DT.a < 0 && DT.b==0 && DT.c==0) {
         out << "-" << abs(DT.a) << "x^2";
    }
    return out;
}

DathucB2 DathucB2::operator+(const DathucB2& DT) {
    DathucB2 c;
    c.a=this->a + DT.a;
    c.b=this->b + DT.b;
    c.c=this->c + DT.c;
    return c;
}

double DathucB2::giatri(int x0) {
    return a*x0*x0+b*x0+c;
}

int main() {
    DathucB2 a1,a2;
    int x0;
    cout << "Nhap da thuc bac 2 thu nhat: ";
    cin >> a1;
    cout << "Nhap da thuc bac 2 thu hai: ";
    cin >> a2;
    cout << "Ta co : F1(x)=" << a1 << " ; F2(x)= " << a2 << endl;
    cout << "Cong da thuc F1 va F2, ta co: (" << a1 << ") + (" << a2 << ") = " << a1+a2 << endl; 
    cout << "Nhap gia tri x0 = " ;cin >> x0;
    cout << "Gia tri cua ham F1(" << x0 << ") la: " << a1.giatri(x0) << endl;
    cout << "Gia tri cua ham F2(" << x0 << ") la: " << a2.giatri(x0) << endl;
    system("pause");
    return 0;
}