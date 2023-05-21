#include "Transport.cpp"
#include <vector>

class Car : public Transport
{
private:
    int numberSeat;
    string engineType;

public:
    Car() {}
    Car(string manufacturer, string name, int year, int speed, int numberSeat, string engineType) : Transport(manufacturer, name, year, speed)
    {
        this->numberSeat = numberSeat;
        this->engineType = engineType;
    }
    int getNumberSeat()
    {
        return numberSeat;
    }
    string getEngineType()
    {
        return engineType;
    }
    double getSpeedBasic()
    {
        return getSpeed() / numberSeat;
    }
    void display()
    {
        Transport::display();
        cout << "Engine Type: " << engineType << endl;
        cout << "Speed Basic: " << getSpeedBasic() << endl;
    }
    static vector<Car> getCarHaveMaxSpeedBasic(vector<Car> vt)
    {
        double max = vt[0].getSpeedBasic();
        for (int i = 1; i < vt.size(); i++)
        {
            if (max < vt[i].getSpeedBasic())
            {
                max = vt[i].getSpeedBasic();
            }
        }
        vector<Car> s;
        for (int i = 0; i < vt.size(); i++)
        {
            if (max == vt[i].getSpeedBasic())
            {
                s.push_back(vt[i]);
            }
        }
        return s;
    }
    static vector<Car> getCarHaveMaxSeat(vector<Car> vt)
    {
        int max = vt[0].getNumberSeat();
        for (int i = 1; i < vt.size(); i++)
        {
            if (max < vt[i].getNumberSeat())
            {
                max = vt[i].getNumberSeat();
            }
        }
        vector<Car> s;
        for (int i = 0; i < vt.size(); i++)
        {
            if (max == vt[i].getNumberSeat())
            {
                s.push_back(vt[i]);
            }
        }
        return s;
    }
};