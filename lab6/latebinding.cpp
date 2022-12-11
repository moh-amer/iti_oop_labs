#include <iostream>
using namespace std;

class Base
{
public:
    virtual void myFunction()
    {
        cout << "Called from Base Class" << endl;
    }

    void newFucntion()
    {
        cout << "newFucntion from Base Class" << endl;
    }
};

class Derived : public Base
{

public:
    void myFunction()
    {
        cout << "Called from Derived Class" << endl;
    }
};

class Derived_1 : public Derived
{

public:
    void myFunction()
    {
        cout << "Called From Derived_1 Class" << endl;
    }

    void newFunction()
    {
        cout << "newFunction from derived_1 Class" << endl;
    }
};

int main()
{

    Base *baseptr;
    Derived derived;
    Derived_1 derived1;

    baseptr = &derived;
    baseptr->myFunction();

    baseptr = &derived1;
    baseptr->newFucntion();

    return 0;
}