/*
REVISION NOTES: MIN STACK

1. The History Trap:
   - A single variable cannot track previous minimums when elements are popped.
    
2. The Pair Solution:
   - Use stack<pair<int, int>> to store {value, current_minimum} for EVERY element.
   - When pushing, the new minimum is just min(new_value, previous_minimum).
   - When popping, the element below it naturally retains the correct historical minimum.

3. C++ STL Memory:
   - Do not write destructors for standard STL containers (like stack, vector, queue) unless you explicitly allocated them with 'new'.

Time Complexity: O(1) for all operations.
Space Complexity: O(N) to store the pairs.
*/
class MinStack {
stack<pair<int, int>> st;
public:
    MinStack() {}

  void push(int value) {
            int currMin = st.empty()? value : min(value, st.top().second);
            st.push({value, currMin});
    }

  void pop() {
    if(!st.empty())
        st.pop();
  }

  int top() {
  return st.top().first;
  }

  int getMin() {
    return st.top().second; 
  }
};