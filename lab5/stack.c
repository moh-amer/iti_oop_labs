#include <iostream>
#include "complex.h"


using namespace std;

template <class T>
class Stack{

    int size,tos;
    T *arr;
    

    int isfull()
    {
        return this->tos == this->size;
    }
    int isempty()
    {
        return this->tos == 0;
    }
    public:

    static int counter;

    static int getCounter()
    {
            return counter;
    }
    Stack()
    {
        this->size = 5;
        this->tos = 0;
        arr = new T[this->size];

        counter++;
    }

    Stack(const Stack &s)
    {

            this-> size = s.size;
            this-> tos = s.tos;
            this->arr = new T[this->size];

            for(int i = 0 ; i < this->tos ; i++)
            {
                    arr[i] = s.arr[i]; 

            }

        counter++;

    }

    Stack(int size)
    {
        this->size = size;
        this->tos = 0;
        this->arr = new T[this->size];

        counter++;
    }

    ~Stack()
    {

            for(int i = 0; i < this->size; i ++ )
            {

                    this->arr[i] = -1;
            }

            delete[] arr;

            counter--;

    }


    void push(T val)
    {
        if(!isfull())
            this->arr[tos++] = val;
        else
            cout<< "The Stack is full" << endl;
    }

    T pop()
    {
        if( !isempty() )
        {
                T temp = this->arr[tos-1];
                this->arr[--tos] = -1;
                return temp; 
        }

            
    }

    T peek()
    {
        if(!isempty())
            return arr[this->tos-1];
        else
        {
            cout << "The stack is empty" << endl;
            return -1;
        }
    }

Stack reverse()
{
    Stack nstack(this->size);
    int i = this->tos;
    while(i > 0)
    {
        nstack.push(arr[--i]);
    }

    return nstack;
}

void printstack()
{
    int i= this->tos;
    while(i > 0)
    {
        cout<< arr[--i] << "  ";
    }
    cout << endl;
}

friend void viewContent(Stack<T> s);


//operator= //S1 = S2;
Stack operator=(Stack c)
{

        this->size = c.size;
        this->tos = c.tos;
        delete[] this->arr;

        this->arr = new T[size];

        for(int i =0 ; i < this->size; i++)
        {

                this->arr[i] = c.arr[i];
        }

        return *this;

}

//operator+ //S3 = S1 + S2; //Append 
Stack operator+( Stack s)
{
        Stack newStack;
        newStack.size = this->size + s.size;
        newStack.tos = 0;
        
        newStack.arr = new T[newStack.size];
        
        int i;

        //propagate the data of the first Stack.
        for(i = 0; i < this->tos; i++){
                newStack.push(this->arr[i]);
        }

        //propagate the data of the second stack.
        for( i= 0; i < s.tos ; i++)
        {
                newStack.push(s.arr[i]);
        }

        return newStack;
}

};
// End of Class.

template<typename T>
int Stack<T>::counter = 0;


template<typename T>
void viewContent(Stack<T> s)
{

        cout << "Stack content : " << endl;
        for (int i = 0; i < s.tos; i++)
        {

                cout << s.arr[i] << "   ";
        }

        cout << endl;
}

template <typename T>
void Swap( T &x, T &y)
{
        T temp = x;
        x = y;
        y = temp;

}


int main(){

        int a=3, b = 5;
    Swap<int>(a,b);
    cout<<"\nAfter Swap: "<<a<<", "<<b<<endl;

    char Ch1='Z', Ch2='O';
    Swap<char>(Ch1, Ch2);
    cout<<"\nAfter Swap: "<<Ch1<<", "<<Ch2<<endl;

    Complex C1(5), C2(2,7);
    Swap<Complex>(C1, C2);
	
    cout<<"\nComplex1 After Swap: "<<endl;
    print(C1);
    cout<<"\nComplex2 After Swap: "<<endl;
    print(C2);
        
    Stack<int> S;
    S.push(10);
    S.push(20);
    cout<< S.pop() << endl;    

    Stack<char> S2(3);
    S2.push('A');
    S2.push('B');
    S2.push('C');
    cout<< S2.pop()<< endl;    
    
    Stack<Complex> S3(4);
    S3.push(C1);
    S3.push(C2);
    Complex C = S3.pop();
    print(C);


    cout << "Counter : " << Stack<int>::getCounter() << endl;
        
}
