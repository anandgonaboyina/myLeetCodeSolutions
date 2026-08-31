class ArrayStack {
privte:
int * stackArray;
int capacity;
int topIndex;
public:
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }
    
    void push(int x) {
        if(top >= capacity - 1;)
        {
            cout<<"stack overflow"<<endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    
    int pop() {
        if(topIndex == -1 || isEmpty())
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    
    int top() {
    if(topIndex == -1 || isEmpty())
    {
        cout<<"stack underflow"<<endl;
        return -1;
    }
    return stackArray[topIndex];
    }
    
    bool isEmpty() {
       return (top == -1)
    }
    int size()
    {
        return topIndex+1;
    }
};