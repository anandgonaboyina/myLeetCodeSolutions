struct Node { // Fixed parenthesis
    int val;
    Node* next;
    Node(int d) {
        val = d;
        next = nullptr;
    }
};

class LinkedListQueue {
    Node* start;
    Node* end;
    int size;
public:
    LinkedListQueue() {
        start = end = nullptr; // Modern C++ prefers nullptr over NULL
        size = 0;
    }
    
    // Fixed: Free remaining memory when the queue is destroyed
    ~LinkedListQueue() {
        while(start != nullptr) {
            Node* temp = start;
            start = start->next;
            delete temp;
        }
    }

    // Time Complexity: O(1)
    void push(int x) {
        Node* newNode = new Node(x);
        if(start == nullptr) {
            start = end = newNode;
        } else { 
            // Fixed: Added 'else' so we don't accidentally link a node to itself
            end->next = newNode;
            end = newNode;
        }
        size++;
    }
    
    // Time Complexity: O(1)
    int pop() {
        if(start == nullptr)
            return -1;
            
        int value = start->val;
        Node* temp = start;
        start = start->next;
        
        // Fixed: Reset 'end' if the queue is now completely empty
        if(start == nullptr) {
            end = nullptr;
        }
        
        delete temp;
        size--;
        return value;
    }
    
    // Time Complexity: O(1)
    int peek() {
        if(start == nullptr)
            return -1;
        return start->val;
    }
    
    // Time Complexity: O(1)
    bool isEmpty() {
        return size == 0; 
    }
};
// Space Complexity: O(N) where N is the number of nodes in the queue.