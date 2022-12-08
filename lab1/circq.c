#include <iostream>

using namespace std;

class CircQ{


int *q, front, rear, size;


int isfull()
{
    //check if circularily full or not.
    return (front == 0 && rear == size) || front == rear+1;
}

int isempty()
{
    return (!isfull()) && (rear == -1);
}

public:
    CircQ(){
        front = rear = -1;
        q = new int[size];
    }

    CircQ(int size)
    {
        front = rear = -1;
        CircQ::size = size;
        q = new int[CircQ::size];
    }

    int enque(int val)
    {

        if(isfull())
            return 0;

        //the stack is empty.
        if(rear == -1)
        {
            q[++rear] = val;
            front++;
            return 1;
        }   
        else
        {
            rear = (rear+1) % size;
            q[rear] = val;
            return 1;
        }

    }

    int deque(int *dequed)
    {
        if(front == -1)
            return 0;

        if(front == rear + 1)
        {
            rear = front = -1;
            return 0;
        }

        if(front == size)
        {
            front = 0;
            *dequed = q[front];
            return 1;
        }

        *dequed = q[front++];
        return 1;
    }

    ~CircQ()
    {
        delete[] q;
    }

};




int main()
{


    int dequed;

    CircQ q(5);
    
    q.enque(5);
    q.enque(6);
    q.enque(7);
    q.enque(8);
    q.enque(9);
    
    q.deque(&dequed);
    cout<< dequed << endl;
    q.enque(10);

    q.deque(&dequed);
    cout<< dequed << endl;

    q.deque(&dequed);
    cout<< dequed << endl;

    q.deque(&dequed);
    cout<< dequed << endl;

    q.deque(&dequed);
    cout<< dequed << endl;

    q.deque(&dequed);
    cout<< dequed << endl;

    return 0;
}