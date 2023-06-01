#include "XuLyDiemMau.cpp"
#include "XuLyMau.cpp"
#include <stdlib.h>
int main()
{
    system("cls");
    cout << "So diem mau 2C hien tai la: " << DIEMMAU::GetDem << endl;
    DIEMMAU d1, d2(1), d3(1, 2), d4(1, 2, 100), d5(1, 2, 50, 100), d6(1, 2, 50, 100, 256), *d7 = new DIEMMAU;
    cout << "So diem mau 2C hien tai la: " << DIEMMAU::GetDem << endl;
    cout << "d1: " << d1 << "\nd2: " << d2 << "\nd3: " << d3 << "\nd4: " << d4 << "\nd5: " << d5 << "\nd6: " << d6 << "\nd7: " << *d7 << endl;

    cout << "Nhap lai toa do diem 2C d1: ";
    cin >> d1;
    cout << "d1 moi: " << d1 << endl;
    if (d1.Diem::KiemTraTrung(*d7))
        cout << "d1 va d7 trung hoanh do va tung do!\n";
    else
        cout << "d1 va d7 khong trung hoanh do va tung do\n";

    // if (d1.MAU::KiemTraTrung(*d7))
    //     cout << "d1 va d7 trung mau\n";
    // else
    //     cout << "d1 va d7 khong trung mau\n";

    if (d1.KiemTraTrung(*d7))
        cout << "d1 va d7 trung nhau hoanh do,tung do va mau\n";
    else
        cout << "d1 va d7 khong trung nhau hoanh do,tung do va mau\n";
    system("pause");
    return 0;
}