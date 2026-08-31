class StackQueue {
    stack<int> s1, s2;
public:
    StackQueue() {}
    
    // Time Complexity: O(N) 
    void push(int x) {
        // Move everything to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop(); 
        }
        
        // Put the new element at the bottom
        s1.push(x);
        
        // Move everything back to s2 so the oldest elements stay on top
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    
    // Time Complexity: O(1)
    int pop() {
        if(s2.empty()) {
            cout << "queue underflow\n";
            return -1;
        }
        int ele = s2.top(); // Grab value first
        s2.pop();           // Then pop (returns void)
        return ele;
    }
    
    // Time Complexity: O(1)
    int peek() {
        if(s2.empty()) {
            cout << "queue underflow\n";
            return -1;
        }
        return s2.top();
    }
    
    // Time Complexity: O(1)
    bool isEmpty() {
        return s2.empty();
    }
};