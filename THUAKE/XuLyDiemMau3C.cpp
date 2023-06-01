#include "XuLyDiem3C.cpp"
using namespace std;
class DIEMMAU3C : public DIEM3C
{
protected:
	int r, g, b;
	static int dem;

public:
	~DIEMMAU3C();
	DIEMMAU3C(double = 0, double = 0, double = 0, int = 0, int = 0, int = 0);
	int GetR() const;
	int GetG() const;
	int GetB() const;
	void SetR(int);
	void SetG(int);
	void SetB(int);
	void SetRGB(int, int, int);
	static int GetDem();
	void Nhap();
	void Xuat() const;
	bool KiemTraTrung(const DIEMMAU3C &) const;
	friend istream &operator>>(istream &in, DIEMMAU3C &);
	friend ostream &operator<<(ostream &out, const DIEMMAU3C &);
};

int DIEMMAU3C::dem = 0;
DIEMMAU3C::~DIEMMAU3C()
{
	cout << "Da huy 1 diem mau 3c => Con " << --dem << " diem mau 3C\n";
}
DIEMMAU3C::DIEMMAU3C(double x, double y, double z, int r, int g, int b) : DIEM3C(x, y, z)
{
	SetRGB(r, g, b);
	cout << "Da tao diem mau 3C => Co " << ++dem << " diem mau 3c\n";
}
int DIEMMAU3C::GetR() const
{
	return r;
}
int DIEMMAU3C::GetG() const
{
	return g;
}
int DIEMMAU3C::GetB() const
{
	return b;
}
void DIEMMAU3C::SetR(int r)
{
	while (r < 0 || r > 255)
	{
		cout << "Nhap lai thong so r tu 0 den 255: ";
		cin >> r;
	}
	this->r = r;
}
void DIEMMAU3C::SetG(int g)
{
	while (g < 0 || g > 255)
	{
		cout << "Nhap lai thong so g tu 0 den 255: ";
		cin >> g;
	}
	this->g = g;
}
void DIEMMAU3C::SetB(int b)
{
	while (b < 0 || b > 255)
	{
		cout << "Nhap lai thong so b tu 0 den 255: ";
		cin >> b;
	}
	this->b = b;
}
void DIEMMAU3C::SetRGB(int r, int g, int b)
{
	SetR(r);
	SetG(g);
	SetB(b);
}
int DIEMMAU3C::GetDem()
{
	return dem;
}
void DIEMMAU3C::Nhap()
{
	DIEM3C::Nhap();
	do
	{
		cout << "Nhap lai thong so RGB tu 0 den 255: ";
		cin >> r >> g >> b;
	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);
}
void DIEMMAU3C::Xuat() const
{
	DIEM3C::Xuat();
	cout << " - Mau RGB(" << r << ", " << g << ", " << b << ")";
}
bool DIEMMAU3C::KiemTraTrung(const DIEMMAU3C &dm3c) const
{
	return DIEM3C::KiemTraTrung(dm3c) && r == dm3c.r && g == dm3c.g && b == dm3c.b;
}
istream &operator>>(istream &in, DIEMMAU3C &dm3c)
{
	dm3c.DIEM3C::Nhap();
	do
	{
		cout << "Nhap 3 thong so RGB tu 0 den 255: ";
		in >> dm3c.r >> dm3c.g >> dm3c.b;
	} while (dm3c.r < 0 || dm3c.r > 255 || dm3c.g < 0 || dm3c.g > 255 || dm3c.b < 0 || dm3c.b > 255);
	return in;
}
ostream &operator<<(ostream &out, const DIEMMAU3C &dm3c)
{
	dm3c.DIEM3C::Xuat();
	out << " - Mau RGB(" << dm3c.r << ", " << dm3c.g << ", " << dm3c.b << ")";
	return out;
}
