//int SUM ( int x, int y, int z);  //try it with all possible default values
#include<iostream>

using namespace std;

int Sum(int x = 1 , int y = 2 , int z = 3)
{

        return x + y + z;

}

int main()
{

        cout<< "Sum Value without parameters : " << Sum() << endl; // print 6
        cout<< "Sum Value Sum(x) parameters : " << Sum(10) << endl; // print 15
        cout<< "Sum Value Sum(x,y) parameters : " << Sum(10,20) << endl; // print 33
        cout<< "Sum Value Sum(x,y,z) parameters : " << Sum(10,20,30) << endl; // print 60



}

