#include <iostream>
using namespace std;

class Dathuc {
private:
    double *x;
    int sophantu;
public:
    Dathuc();
    Dathuc(int n);
    Dathuc(const Dathuc&);
    ~Dathuc();
    Dathuc & operator=(const Dathuc&);
    friend Dathuc operator+(const Dathuc&,const Dathuc&);
    friend Dathuc operator-(const Dathuc&,const Dathuc&);
    friend Dathuc operator*(const Dathuc&,const Dathuc&);
    friend istream& operator>>(istream& in,Dathuc&);
    friend ostream& operator<<(ostream& out,Dathuc&);
    bool PreAllZero(int k) {
        for (int i=sophantu;i>=0;i--) {
            if (i>k && x[i]!=0) {
                return false;
            }
        }
        return true;
    }
};

Dathuc::Dathuc() {
    this->sophantu=0;
    this->x=new double[0+1];
    for (int i=0;i<=this->sophantu;i++) {
        this->x[i]=0;
    }
}

Dathuc::Dathuc(int n) {
    this->sophantu=n;
    this->x=new double[sophantu+1];
    for (int i=0;i<=this->sophantu;i++) {
        this->x[i]=0;
    }
}

Dathuc::Dathuc(const Dathuc& DT) {
    this->sophantu=DT.sophantu;
    delete[] this->x;
    this->x=new double[sophantu+1];
    for (int i=0;i<=this->sophantu;i++) {
        this->x[i]=DT.x[i];
    }
}

Dathuc::~Dathuc() {
    delete[] this->x;
}

Dathuc & Dathuc::operator=(const Dathuc& DT) {
    if (&DT==this) {
        return *this;
    }
    this->sophantu=DT.sophantu;
    delete[] this->x;
    this->x=new double[sophantu+1];
    for (int i=0;i<=this->sophantu;i++) {
        this->x[i]=DT.x[i];
    }
    return *this;
}

Dathuc operator+(const Dathuc& DT1,const Dathuc& DT2) {
    Dathuc DT((DT1.sophantu>DT2.sophantu)?DT1.sophantu:DT2.sophantu);
    for (int i=0;i<=DT.sophantu;i++) {
        if (i<=DT1.sophantu && i<=DT2.sophantu) {
            DT.x[i]=DT1.x[i]+DT2.x[i];
        }
        else {
            if (i>DT1.sophantu) {
                DT.x[i]=DT2.x[i];
            }
            else if (i>DT2.sophantu) {
                DT.x[i]=DT1.x[i];
            }
            else {

            }
        }
    }
    return DT;
}

Dathuc operator-(const Dathuc& DT1,const Dathuc& DT2) {
    Dathuc DT((DT1.sophantu>DT2.sophantu)?DT1.sophantu:DT2.sophantu);
    for (int i=0;i<=DT.sophantu;i++) {
        if (i<=DT1.sophantu && i<=DT2.sophantu) {
            DT.x[i]=DT1.x[i]-DT2.x[i];
        }
        else {
            if (i>DT1.sophantu) {
                DT.x[i]=DT2.x[i];
            }
            else if (i>DT2.sophantu) {
                DT.x[i]=DT1.x[i];
            }
            else {

            }
        }
    }
    return DT;
}

Dathuc operator*(const Dathuc& DT1,const Dathuc& DT2) {
    Dathuc DT(DT1.sophantu+DT2.sophantu);
    for (int i=0;i<=DT1.sophantu;i++) {
        for (int j=0;j<=DT2.sophantu;j++) {
            DT.x[i+j]=DT1.x[i]*DT2.x[j];
        }
    }
    return DT;
}

ostream& operator<<(ostream& out,Dathuc& DT) {
    for (int i=DT.sophantu;i>=0;i--) {
        if (DT.x[i]!=0) {
            if (DT.x[i]>0) {
                if (i!=DT.sophantu && DT.PreAllZero(i)==0) {
                    out << " + ";
                }
            }
            else {
                 out << " - ";
            }
            if (abs(DT.x[i]!=1)) {
                out << abs(DT.x[i]);
            }
            if (i==1) {
                out << "x";
            }
            else if(i==0) {}
            else {
                out << "x^" <<i;
            }
        }
    }
    return out;
}

istream& operator>>(istream& in,Dathuc& DT) {
    delete[] DT.x;
    cout << "Nhap vao so mu toi da: ";
    in >> DT.sophantu;
    cout <<"Nhap gia tri dau vao cua luy thua tu cao den thap: ";
    DT.x=new double[DT.sophantu+1];
    for (int i=DT.sophantu;i>=0;i++) {
        in >> DT.x[i];
    }
    return in;
}

int main() {
    Dathuc DT1;
    Dathuc DT2;
    cout << "Nhap da thuc 1: ";
    cin >> DT1;
    cout << "Nhap da thuc 2: ";
    cin >> DT2;
    Dathuc Tong=DT1+DT2;
    cout << "Tong 2 da thuc 1 va 2 la: "<<Tong << endl;
    Dathuc Hieu=DT1-DT2;
    cout << "Hieu da thuc 1 tru cho da thuc 2 la: " << Hieu<< endl;
    Dathuc Tich=DT1*DT2;
    cout << "Tich giua da thuc 1 va da thuc 2 la: " << Tich << endl;
    system("pause");
    return 0;
}