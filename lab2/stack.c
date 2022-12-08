#include <iostream>

using namespace std;

class Stack{

    int size,tos;
    int *arr;

    int isfull()
    {
        return tos == size;
    }

    int isempty()
    {
        return tos == 0;
    }
    public:

    Stack()
    {
        size = 5;
        tos = 0;
        arr = new int[size];
    }

    Stack(int size)
    {
        Stack::size = size;
        tos = 0;
        arr = new int[size];
    }


    void push(int val)
    {
        if(!isfull())
            arr[tos++] = val;
        else
            cout<< "The Stack is full" << endl;
    }

    int pop()
    {
        if(!isempty())
            return arr[--tos];
        else
        {

            cout<< "The stack is empty" << endl;
            return -1;
        }
            
    }

    int peak()
    {
        if(!isempty())
            return arr[tos-1];
        else
        {
            cout << "The stack is empty" << endl;
            return -1;
        }
    }

Stack reverse()
{
    Stack nstack(tos);
    int i = tos;
    while(i > 0)
    {
        nstack.push(arr[--i]);
    }

    return nstack;
}

void printstack()
{
    int i= tos;
    while(i > 0)
    {
        cout<< arr[--i] << "  ";
    }
    cout << endl;
    
}

};


int main(){

Stack S1(5);
	
	S1.push(10);
	S1.push(20);
	S1.push(30);

	cout<< S1.peak()<< endl; //30
	cout<< S1.peak()<< endl; //30

	cout<< S1.pop()<< endl; //30
	cout<< S1.pop()<< endl; //20

	Stack S2(5);
	
	S2.push(3);
	S2.push(4);
	S2.push(5);
	S2.push(6);

	cout<< S2.reverse().pop()<<endl ; 

return 0;
}