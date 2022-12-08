#include <iostream>
using namespace std;

///shifting

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

    void EnQueue(int e){
        if(!isFull()){
            q[++tail] = e;
            num++; 
        }else
        {
            cout << "full" << endl;
        }
        
    }
    int DeQueue(){
        int i,e = q[head];
        if(!isEmpty()){
            for(i=0; i< tail; i++){
                q[i] = q[i+1];
            }
            num--;
        }
        return e;
    }

    int isEmpty(){
        return num == 0;
    }
    int isFull(){
        return num == size;
    }
};


int main(){
    Queue q;
    q.EnQueue(5);
    q.EnQueue(3);
    q.EnQueue(24);
    q.EnQueue(1);
    q.EnQueue(8);
    cout << q.DeQueue() << endl;
    q.EnQueue(8);

}
