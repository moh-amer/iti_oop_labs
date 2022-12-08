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
            this->real = img =5;
    }
    Complex(int ri){
            this->real = img = ri;
    }

    Complex(int r, int i)
    {
            this->real = r;
            this->img = i;
    }

    //Copy Constructor.
    Complex(Complex &c){
            this->real = c.real;
            this->img = c.img;
    }

    ~Complex()
    {


    }


    void setReal(int);
    void setImg(int);

    int getReal();
    int getImg();
    Complex addComplex(Complex );
    Complex subComplex(Complex);

    //C3 = C1- C2;
    Complex operator- (Complex c)
    {
            Complex comp;
            
            comp.setImg(this->img - c.getImg());
            comp.setReal(this->real - c.getReal());

            return comp;
    }

    //C3 = C2 - 7;
    Complex operator- (int num)
    {

            Complex comp;

            comp.setReal(this->real - num);
            comp.setImg(this->img - num); 

            return comp;

    }

    //C1-=C2;
    Complex operator-= (const Complex& c)
    {

            this->setReal(this->real - c.real);
            this->setImg(this->img - c.img);

            return *this;
    }
    
    //C2=--C1;
    Complex operator--()
    {

            this->setReal( --this->real);
            this->setImg( --this->img );

            return *this;

    }


    //C2 = C1--; 
    Complex operator--(int)
    {

            //temp complex to get the value before change 
            //inside the setter we change the passed object it self 
            Complex temp;
            temp.setReal(this->real--);
            temp.setImg(this->img--);

            return temp;


    }

    //C1 == C2
    int operator==(Complex c)
    {
            return ( this->real == c.real && this->img == c.img );
    }


    //C1 != C2
    int operator!=(Complex c)
    {
            return ( !(this->real == c.real && this->img == c.img ) );

    }

    //C1 > C2,  C1 >= C2,
    int operator>(Complex c)
    {
            return (this->img > c.img);
    }

    int operator>=(Complex c)
    {
            return (this->img >= c.img);
    }

    //C1 < C2, C1 <= C2,
    int operator<(Complex c)
    {
        return (this->img < c.img);
    }

    int operator<=(Complex c)
    {
        return (this->img <= c.img);
    }

    //(int) C1
    operator int ()
    {
        return this->real + this->img;
    }

    //cout<< C1['R']
    int operator[](char c)
    {
            int res;
            switch(c)
            {

                    case 'R':
                    case 'r':
                            res = this->real;
                            break;
                    case 'I':
                    case 'i':
                            res = this->img;
                            break;
                        default:
                            res = -1;
            }
            return res;
        
    }
};
//End of Class

void Complex::setReal(int x)
    {
        this->real = x;
    }
void Complex::setImg(int x)
    {
        this->img = x;
    }
int Complex::getReal()
    {
        return this->real;
    }
int Complex::getImg()
    {
        return this->img;
    }
Complex Complex::addComplex(Complex comp)
    {
        Complex newComp;
        newComp.setReal( this->getReal() + comp.getReal());
        newComp.setImg( this->getImg() + comp.getImg());
        return newComp;
    }

Complex Complex::subComplex(Complex comp)
    {

            Complex newComp;
            newComp.setReal( this->getReal() - comp.getReal() );
            newComp.setImg(  this->getImg() - comp.getImg());

            return newComp;

    }

// Stand alone function for C3 = 7 - C2;
Complex operator-(int num, Complex c)
{
        Complex comp;
        comp.setReal(num - c.getReal() );
        comp.setImg( num - c.getImg());

        return comp;
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

        Complex c1(9,15), c2(1), c3;

        
        print(c1);
        print(c2);
        
        c3 = c1 - c2;
        cout << " --------- c3 = c1 - c2 --------" << endl;
        print(c3);


        c3 = 7 - c1;
        cout << " --------- c3 = 7 - c1 --------" << endl;
        print(c3);

        c3 = c1 - 7;
        cout << " --------- c3 = c1 - 7 --------" << endl;
        print(c3);

        
        c1 -= c2;
        cout << " --------- c1 -= c2 --------" << endl;
        print(c1);

        c3 = --c1;
        cout << " --------- c3 = --c1 --------" << endl;
        print(c3);

        c3 = c1--;
        cout << " --------- c3 = --c1 --------" << endl;
        print(c3);
        print(c1);

        
        c3 = c1;
        cout << " --------- c1 == c2 --------" << endl;
        cout << " Equality Comparison result of the two Complexes: "<< (c1 == c2) << endl;



//        c3 = c1;
        cout << " --------- c1 != c2 --------" << endl;
        cout << " Not Equal Comparison result of the two Complexes: "<< (c1 != c2) << endl;



        cout << " --------- c3 = (int)c1 --------" << endl;
        cout << "Result : "<< (int)c1 << endl;
        

        cout << " --------- Imaginary OR Real --------" << endl;
        cout << "Result : "<< c1['i'] << endl;






        return 0;
}
