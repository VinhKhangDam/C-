#include "Transport.cpp"
#include "Car.cpp"

int main()
{
    vector<Car> vt;
    Car c1("VietNam", "VinFast", 2021, 300, 4, "diesel");
    Car c2("Japan", "Toyota", 2022, 280, 4, "petrol");
    Car c3("Korea", "Huyndai", 2023, 350, 4, "diesel");
    vt.push_back(c1);
    vt.push_back(c2);
    vt.push_back(c3);
    for (int i = 0; i < vt.size(); i++)
    {
        vt[i].display();
        cout << "---------------------" << endl;
    }
    vector<Car> v = Car::getCarHaveMaxSpeedBasic(vt);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "---------MAX-SPEED----------" << endl;
        v[0].display();
    }
}