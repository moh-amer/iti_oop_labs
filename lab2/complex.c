#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;

public:

    Complex()
    {
            cout<< "No parameter constructor called" << endl;
            real = img =5;
    }
    Complex(int ri){

            cout<< "One value Parameterized constructor called" <<endl;
            real = img = ri;

    }

    Complex(int r, int i)
    {
            cout<< "2 Values Parameterized constructor called" <<endl;

            real = r;
            img = i;

    }

    ~Complex()
    {

            cout<< "Destructor called" << endl;

    }


    void setReal(int);
    void setImg(int);

    int getReal();
    int getImg();
    Complex addComplex(Complex );
    Complex subComplex(Complex);

};

void Complex::setReal(int x)
    {
        real = x;
    }
void Complex::setImg(int x)
    {
        img = x;
    }
int Complex::getReal()
    {
        return real;
    }
int Complex::getImg()
    {
        return img;
    }
Complex Complex::addComplex(Complex comp)
    {
        Complex newComp;
        newComp.setReal(getReal() + comp.getReal());
        newComp.setImg(getImg() + comp.getImg());
        return newComp;
    }

Complex Complex::subComplex(Complex comp)
    {

            Complex newComp;
            newComp.setReal( getReal() - comp.getReal() );
            newComp.setImg(getImg() - comp.getImg());

            return newComp;

    }

void print(Complex C)
{
    int real = C.getReal();
    int img = C.getImg();

    if (real == 0 && img == 0)
    {
        cout << 0 << endl;
    }
    else if (real == 0)
    {
        cout << img << "i" << endl;
    }
    else if (img == 0)
    {
        cout << real << endl;
    }
    else if (img < 0)
    {
        cout << real << img << "i" << endl;
    }
    else
    {
        cout << real << "+" << img << "i" << endl;
    }
}

int main()
{
/*    Complex first, second;

    first.setImg(3);
    first.setReal(7);

    second.setImg(3);
    second.setReal(8);


    cout<< "------First Complex----------" << endl;
    print(first);

    cout<< "------Second Complex----------" << endl;
    print(second);

    cout<< "------Add Complex----------" << endl;
    Complex add = first.addComplex(second);
    print(add);

    cout<< "------Subtract Complex ----------" << endl;
    Complex sub = first.subComplex(second);
    print(sub);
*/

    Complex C1(3,4), C2(5), C3;
	C3 = C1.addComplex(C2);
    print(C3);
    return 0;
}
