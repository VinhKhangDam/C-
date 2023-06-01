#include "XuLyDiemMau3C.cpp"

int main()
{
    system("cls");
    cout << "So diem mau 3C hien tai la: " << DIEMMAU3C::GetDem() << endl;
    DIEMMAU3C d6(0), d7(4), d8(1, 2, 3, 123, 34, 6), *d9 = new DIEMMAU3C;
    cout << "So diem mau 3C hien tai la: " << DIEM3C::GetDem() << endl;
    cout << "d6: " << d6 << "\nd7: " << d7 << "\nd8: " << d8 << "\nd9: " << *d9 << endl;
    cout << "Nhap lai toa do diem 1: ";
    cin >> d6;
    cout << "d1 moi: " << d6 << endl;
    if (d6.DIEM3C::KiemTraTrung(d8))
    {
        cout << "d6 va d8 trung nhau ve hoanh do,tung do va cao do!" << endl;
    }
    else
    {
        cout << "d6 va d8 khong trung nhau ve hoanh do,tung do va cao do!" << endl;
    }
    if (d6.KiemTraTrung(d8))
        cout << "d6 va d8 trung nhau ve hoanh do,tung do,cao do va mau RGB!" << endl;
    else
        cout << "d6 va d8 khong trung nhau ve hoanh do,tung do,cao do va mau RGB!" << endl;
    delete d9;
    cout << "So diem mau 3C hien tai la: " << DIEMMAU3C::GetDem() << endl;
    system("pause");
    return 0;
}