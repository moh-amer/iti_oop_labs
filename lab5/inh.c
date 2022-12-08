#include<iostream>

using namespace std;

class Base
{

        private: int x;
        protected: int y;
        public:
        Base()
        {
                x = y = 1;
        }

        Base(int xy)
        {
                x = y = xy;
        }

        Base(int x, int y)
        {
                this->x = x;
                this->y = y;
        }

        ~Base()
        {
                cout<< "Base Class Destructor called"<<endl;
        }

        void setX(int x)
        {
                this->x = x;
        }
        void setY(int y)
        {
                this->y = y;
        }

        int getX()
        {
                return this->x;
        }

        int getY()
        {

                return this->y;
        }

        int sum()
        {

                return this->x + this->y;
        }

};

class Derived: public Base
{
        private: int z;

        public:
        Derived():Base()
        {

                this->z = 1;

        }

        Derived(int z):Base()
        {

                this->z = z;

        }

        Derived(int x, int y , int z)
        {

                setX(x);
                setY(y);
                this->z = z;

        }

        ~Derived()
        {
                cout<<"Derived Class Constructor called"<<endl;
        }


        void setZ(int z)
        {

                this->z = z;
        }

        int getZ()
        {

                return this->z;
        }

        int sum()
        {
                return Base::sum() + z;
        }

};

int main()
{

        Base b;
        cout << b.sum()<< endl;

        Derived d(10, 20, 30);
        cout << d.sum() << endl;

return 0;
}
