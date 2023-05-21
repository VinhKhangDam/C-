#include "Geometry.cpp"

class Circle : public Geometry
{
private:
    int r;

public:
    Circle() {}
    Circle(int r)
    {
        this->r = r;
    }
    double perimeter()
    {
        return r * 3.14 * 2;
    }
    double area()
    {
        return r * r * 3.14;
    }
};