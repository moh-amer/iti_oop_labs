#include <iostream>

using namespace std;

class Stack{

    int size,tos;
    int *arr;

    int isfull()
    {
        return this->tos == this->size;
    }
    int isempty()
    {
        return this->tos == 0;
    }
    public:

    Stack()
    {
        this->size = 5;
        this->tos = 0;
        arr = new int[this->size];
        cout<< "No parameter constructor " << endl;
    }

    Stack(Stack &s)
    {

            this-> size = s.size;
            this-> tos = s.tos;
            this->arr = new int[this->size];

            for(int i = 0 ; i < this->tos ; i++)
            {
                    arr[i] = s.arr[i]; 

            }

            cout << "Copy Constructor" << endl;
    }

    Stack(int size)
    {
        this->size = size;
        this->tos = 0;
        this->arr = new int[this->size];
        cout << "one parameter Constructor called" << endl;
    }

    ~Stack()
    {

            for(int i = 0; i < this->size; i ++ )
            {

                    this->arr[i] = -1;
            }

            delete[] arr;

    }


    void push(int val)
    {
        if(!isfull())
            this->arr[tos++] = val;
        else
            cout<< "The Stack is full" << endl;
    }

    int pop()
    {
        if( !isempty() )
            return this->arr[--tos];
        else
        {

            cout<< "The stack is empty" << endl;
            return -1;
        }
            
    }

    int peek()
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

friend void viewContent(Stack s);

};
// End of Class.



void viewContent(Stack s)
{

        cout << "Stack content : " << endl;
        for (int i = 0; i < s.tos; i++)
        {

                cout << s.arr[i] << "   ";
        }

        cout << endl;

}


int main(){

//Case 1

    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    viewContent(S1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;





//////Case 2
/*
Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

//    Stack SS ;
 //    SS = S1.reverse();
  //  cout<< SS.pop();

    cout << S1.reverse().pop() << endl; 
*/
/////Case 3
/*
    Stack S1;

    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);

    Stack S3 ( S1 );

    for(int i=0; i<10; i++)
    S3.pop();


    for(int i=0; i<10; i++)
        S3.push(-1);

    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;
    cout<<"Num = "<<S1.pop()<<endl;

*/
        return 0;
}
