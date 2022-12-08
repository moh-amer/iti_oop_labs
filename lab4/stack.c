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
    }

    Stack(const Stack &s)
    {

            this-> size = s.size;
            this-> tos = s.tos;
            this->arr = new int[this->size];

            for(int i = 0 ; i < this->tos ; i++)
            {
                    arr[i] = s.arr[i]; 

            }

    }

    Stack(int size)
    {
        this->size = size;
        this->tos = 0;
        this->arr = new int[this->size];
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
        {
                int temp = this->arr[tos-1];
                this->arr[--tos] = -1;
                return temp; 
        }
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


//operator= //S1 = S2;
Stack operator=(Stack c)
{

        this->size = c.size;
        this->tos = c.tos;
        delete[] this->arr;

        this->arr = new int[size];

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
        
        newStack.arr = new int[newStack.size];
        
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

        Stack s1(5), s2(7), s3;
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
        s1.push(5);

        s2.push(6);
        s2.push(7);
        s2.push(8);
        s2.push(9);
        s2.push(10);

        s3 = s1+s2;


        //viewContent(s1);
        //viewContent(s2);
        viewContent(s3);

        return 0;
}
