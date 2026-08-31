class QueueStack {
    queue<int> q;
public:
    QueueStack() {}
    
    void push(int x) {
        int n = q.size(); // Record size before pushing the new element
        
        q.push(x); // Push x to the back
        
        // Rotate all previous elements to sit behind x
        for(int i = 0; i < n; i++) {
            q.push(q.front()); // Grab the front element
            q.pop();           // Delete it from the old front
        }
    }
    
    int pop() {
        if(isEmpty()) {
            cout << "stack underflow\n";
            return -1;
        }
        int ele = q.front(); // Store value before popping
        q.pop();             // C++ pop() returns void
        return ele;
    }
    
    int top() {
        if(isEmpty()) {
            cout << "stack empty\n";
            return -1;
        }
        return q.front(); // Queues use front(), not top()
    }
    
    bool isEmpty() {
        return q.empty(); // q.empty() is slightly faster than q.size() == 0
    }
};

// Time Complexity: 
// - push(): O(N) because we rotate N elements every time.
// - pop(), top(), isEmpty(): O(1) instant lookup.
// Space Complexity: O(N) for using a single queue.