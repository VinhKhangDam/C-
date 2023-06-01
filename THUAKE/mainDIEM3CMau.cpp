#include "XuLyDiem3CMau.cpp"
#include "XuLyMau.cpp"
int main()
{
    system("cls");
    cout << "So diem mau 3C hien tai la: " << DIEM3CMAU::GetDem << endl;
    DIEM3CMAU d1, d2(1), d3(1, 2), d4(1, 2, 4), d5(1, 2, 4, 62), d6(1, 2, 3, 64, 213, 23), *d7 = new DIEM3CMAU;
    cout << "So diem mau 3C hien tai la: " << DIEM3CMAU::GetDem << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << d5 << "\nd6: " << d6 << "\nd7: " << *d7 << endl;
    cout << "Nhap lai d1 moi: ";
    cin >> d1;
    cout << "d1 moi la: " << d1 << endl;
    if (d1.DIEM3C::KiemTraTrung(*d7))
        cout << "d1 va d7 trung nhau ve hoanh do,tung do va cao do\n";
    else
        cout << "d1 va d7 khong trung nhau ve hoanh do,tung do va cao do\n";
    // if (d1.MAU::KiemTraTrung(*d7))
    //     cout << "d1 va d7 trung mau\n";
    // else
    //     cout << "d1 va d7 khong trung mau\n";
    if (d1.KiemTraTrung(*d7))
        cout << "d1 va d7 trung nhau ve hoanh do,tung do,cao do va mau\n";
    else
        cout << "d1 va d7 khong trung nhau ve hoanh do,tung do,cao do va mau\n";
    system("pause");
    return 0;
}