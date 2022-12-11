#include <iostream>
using namespace std;
// 1- virtual method should be public in first parent in hirarchy
// 3- inheritance type should be public inheritance.
// 3- override parent method with a public mehtod with the same signature in the child
// 4- base pointer point to derived object
// then the implementation of the derived method will be executed.
class Geoshape
{

        float dim1, dim2;

public:
        Geoshape()
        {

                dim1 = dim2 = 0;
        }

        Geoshape(float dim)
        {

                dim1 = dim2 = dim;
        }

        Geoshape(float dim1, float dim2)
        {

                this->dim1 = dim1;
                this->dim2 = dim2;
        }

        ~Geoshape()
        {
                // something to destruct.
                dim1 = dim2 = -1;
        }

        void setDim1(float dim)
        {
                this->dim1 = dim;
        }

        void setDim2(float dim)
        {
                this->dim2 = dim;
        }

        float getDim1()
        {
                return this->dim1;
        }

        float getDim2()
        {
                return this->dim2;
        }

        float calcArea()
        {
                return this->dim1 * this->dim2;
        }
};

class Rectangle : public Geoshape
{

public:
        Rectangle() : Geoshape() {}

        Rectangle(float x, float y) : Geoshape(x, y) {}
};

class Triangle : public Geoshape
{

public:
        Triangle() : Geoshape() {}

        Triangle(float x, float y) : Geoshape(x, y) {}

        float calcArea()
        {
                return 0.5 * this->getDim1() * this->getDim2();
        }
};

// protected inheritance so that setters will not be accessible in main.
// so that we can change setting behaviour with another function.
class Square : protected Geoshape
{

public:
        Square() : Geoshape() {}
        Square(float x) : Geoshape(x) {}

        void setDimm(float x)
        {
                this->setDim1(x);
                this->setDim2(x);
        }

        float calcArea()
        {
                return this->getDim1() * this->getDim2();
        }
};

class Circle : protected Geoshape
{
public:
        Circle() : Geoshape() {}
        Circle(float x) : Geoshape(x) {}

        void setDimm(float x)
        {
                this->setDim1(x);
                this->setDim2(x);
        }

        float getDimm()
        {
                return this->getDim1();
        }

        float calcArea()
        {
                return this->getDimm() * this->getDimm() * 3.14;
        }
};

int main()
{

        Rectangle r(5.0, 4);
        cout << "Rectangle Area is:" << r.calcArea() << endl;

        Square s;
        s.setDimm(5.0);
        cout << "Square Area is: " << s.calcArea() << endl;

        Triangle t(4, 6);
        cout << "Triangle Area is: " << t.calcArea() << endl;

        Circle c;
        c.setDimm(4.0);
        cout << "Circle Area is : " << c.calcArea() << endl;

        return 0;
}
