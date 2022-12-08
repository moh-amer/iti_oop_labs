#include <iostream>

using namespace std;


void swapByValue(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swapByAddress(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swapByReference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;  
}


int main(){
    
    int x = 2, y= 3;
    
    swapByValue(x,y);
    cout<<"swap [By Value] " << x << "||" << y << endl;
    

    x = 2,y=3;
    swapByAddress(&x,&y);
    cout<<"swap [By Address] " << x << "||" << y << endl;
    

    x= 2, y =3;
    swapByReference(x,y);
    cout<<"swap [By Reference] " << x << "||" << y << endl;
    
    return 0;

}
