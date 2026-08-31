        }
    }
    
            s2.push(s1.top());
            s1.pop();
        
        // Move everything back to s2 so the oldest elements stay on top
        while(!s1.empty()) {
        // Put the new element at the bottom
        s1.push(x);
            s2.pop(); 
        }
        
        // Move everything to s1
        while(!s2.empty()) {
            s1.push(s2.top());
    // Time Complexity: O(N) 
    void push(int x) {
public:
    StackQueue() {}
    
class StackQueue {
    stack<int> s1, s2;