#include "Geometry.cpp"

class Rectangle : public Geometry
{
private:
    int h;
    int w;

public:
    Rectangle() {}
    Rectangle(int h, int w)
    {
        this->h = h;
        this->w = w;
    }
    double perimeter()
    {
        return (h + w) * 2;
    }
    double area()
    {
        return h * w;
    }
};