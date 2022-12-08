#include <iostream>
using namespace std;

class Queue{
    private:
        int* q;
        int head;
        int tail;
        int size;
        int num;
    public:
    Queue(){
        head = 0;
        tail = -1;
        size = 5;
        num = 0;
        q = new int[size];
    }
    Queue(int s){
        head = 0;
        tail = -1;
        size = s;
        num = 0;
        q = new int[size];
    }
    ~Queue(){
        delete[] q;
    }
    void Enqueue(int e)
    {
        tail = (tail+1) % size;
        q[tail] = e;
        num++;
    }
    int Dequeue()
    {
        int i = q[head];
        head = (head+1) % size;
        num--;
        return i;
    }
    int isEmpty()
    {
        return num == 0;
    }
    int isFull()
    {
        return num ==size;
    }
};



int main(){
    Queue q(3);
    q.Enqueue(45);
    q.Enqueue(42);
    q.Enqueue(3);
    cout << q.Dequeue() << endl;
    cout << q.Dequeue() << endl;
}
