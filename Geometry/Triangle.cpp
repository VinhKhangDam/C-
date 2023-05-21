#include "Geometry.cpp"

class Triangle : public Geometry
{
private:
    int a;
    int b;
    int c;

public:
    Triangle() {}
    Triangle(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double perimeter()
    {
        return a + b + c;
    }
    double area()
    {
        double p = a + b + c / 2;
        return p * (p - a) * (p - b) * (p - c);
    }
};