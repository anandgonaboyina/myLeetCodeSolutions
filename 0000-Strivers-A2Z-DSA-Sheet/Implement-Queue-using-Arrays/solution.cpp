class ArrayQueue {
private:
int* queueArray;
int start, end;
int capacity;
public:
    ArrayQueue(int size=100) {
        capacity = size;
        queueArray = new int[capacity];
        start =-1;
        end =-1;
    }

    ~ArrayQueue()
    {
        delete[] queueArray;
    }

    void push(int x) {
        if(isEmpty())
            start =0;
        if(end >= capacity -1)
        {
            cout<<"queue overflow\n";
            return;
        }
        queueArray[++end] = x;
    }
    
    int pop() {
        if(isEmpty())
        {
            cout<<"queue underflow\n"<<endl;
            return-1;
        }
        int ele = queueArray[start];
        if(start == end)
        {
            start = -1;
            end = -1;
        }
        else
            start++;
        return ele;
    }
    
    int peek() {
        if(isEmpty())
        {
            cout<<"queue is empty";
            return -1;
        }
    return queueArray[start];
    }
    
    bool isEmpty() {
        return start == -1;
    }
};