#include "XuLyDiem3C.cpp"

int main()
{
    system("cls");
    // main Diem 3c
    cout << "So diem 3C hien tai la: " << DIEM3C::GetDem() << endl;
    DIEM3C d1, d2(1), d3(1, 2), d4(1, 2, 3), *d5 = new DIEM3C;
    cout << "So diem 3C hien tai la: " << DIEM3C::GetDem() << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << *d5 << endl;
    cout << "Nhap lai toa do diem d1: ";
    cin >> d1;
    cout << "d1 moi: " << d1 << endl;
    if (d1.Diem::KiemTraTrung(d4))
        cout << "d1 va d4 trung nhau ve hoanh do va tung do!" << endl;
    else
        cout << "d1 va d4 khong trung nhau ve hoanh do va tung do!" << endl;
    if (d1.KiemTraTrung(d4))
        cout << "d1 va d4 trung nhau ve hoanh do, tung do va cao do!" << endl;
    else
        cout << "d1 va d4 khong trung nhau ve hoanh do, tung do va cao do!" << endl;
    d4.DiChuyen(3, 4, 5);
    cout << "d4 sau khi di chuyen la: " << d4 << endl;
    cout << "Khoang cach giua d1 va d4 la: " << d1.TinhKhoangCach(d4) << endl;
    cout << "Chu vi tam giac duoc tao boi d1,d3,d4 la: " << d1.Chuvi(d3, d4) << endl;
    cout << "DIen tich tam giac duoc tao boi d1,d3 va d4 la: " << d1.Dientich(d3, d4) << endl;
    delete d5;
    cout << "So diem 3C hien tai la: " << DIEM3C::GetDem() << endl;
    system("pause");
    return 0;
}