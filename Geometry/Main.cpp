#include "Geometry.cpp"
#include "Triangle.cpp"
#include "Circle.cpp"
#include "Rectangle.cpp"

int main()
{
    Geometry **geometry = new Geometry *[4];
    geometry[0] = new Triangle(3, 4, 5);
    geometry[1] = new Rectangle(3, 5);
    geometry[2] = new Circle(2);
    geometry[3] = new Circle(3);
    for (int i = 0; i < 4; i++)
    {
        geometry[i]->display();
    }
}