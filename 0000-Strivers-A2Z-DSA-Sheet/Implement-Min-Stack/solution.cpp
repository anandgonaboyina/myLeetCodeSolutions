
// LeetCode 155: Min Stack. 
/// getting around 86% beats because Sc is N as we storing the double the digits of N those N min values
// Space Complexity: O(N) to store the pairs.
// Time Complexity: O(1) for all operations.
//Approach 1 : 
/*
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
*/

/*
=========================================================================
REVISION NOTES: MIN STACK
=========================================================================
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


// =========================================================================
//Approach 2 :
//=========================================================================
// now minEle also SC 1;
// got 100%
class MinStack {
stack<long long> st;
long long currMin;
public:
    MinStack() {}

  void push(int value) {

        if(st.empty())
        {
            currMin = value;
            st.push(value);
        }
        else if(value < currMin)
        {
            st.push(2LL*value - currMin);
            currMin = value;
        }
        else
            st.push(value);
    }

  void pop() {
    if(st.empty()) return;
    long long topNum = st.top();
    if(topNum < currMin)
        currMin = 2*currMin - topNum;
    st.pop();
  }

  int top() {
    if(st.top() < currMin)
        return currMin;
    return st.top();
  }

  int getMin() {
    return currMin; 
  }
};


/*
=========================================================================
REVISION NOTES: APPROACH 2 - O(1) AUXILIARY SPACE (THE MATH TRICK)
=========================================================================
1. The Flips and Flops (Mistakes to Remember):
   **- Missing the Normal Push: I initially forgot to push the element entirely if it wasn't a new minimum. 
   - The Negative Number Trap: I tried pushing 'currMin - prevMin'. This fails with negative numbers! If prevMin = -5 and new value = -10, then -10 - (-5) = -5. But -5 is NOT less than -10, so the flag fails. The mathematically proven formula is '2 * value - currMin'.
   - The OR Condition Bug: I used an '||' inside pop() to check conditions, which caused it to skip the math logic entirely if the stack just wasn't empty.
   ******- Integer Overflow: 32-bit integers will overflow when doing '2 * value'. MUST use 'long long' for the stack and currMin.

2. The Flag Logic (How it works):
   - PUSH: When a new minimum 'x' arrives, push a fake value/flag: (2LL * x - currMin). Because x < currMin, this fake value is GUARANTEED to be strictly less than x. Update currMin = x.
   - TOP: If stack.top() < currMin, we hit a flag! The actual value pushed was currMin.
   - POP: If stack.top() < currMin, we must restore the previous minimum before removing the flag. The reverse formula is: prevMin = (2LL * currMin - stack.top()).

Time Complexity: O(1) for all operations.
Space Complexity: O(1) auxiliary space (we only store the N elements, no extra pairs).
*/
/*
===============================================================
(Why O(1) Math Approach gets ~96% not 100% and Pair Approach gets ~86%)
==============================================================
1. Physical Memory is Identical: 
   - Approach 1 pushes pair<int, int> -> 4 bytes + 4 bytes = 8 bytes.
   - Approach 2 pushes a 'long long' -> 8 bytes.
   - LeetCode allocates the exact same memory for both! No actual RAM is saved.

2. CPU Math Overhead:  
   - Approach 1 just stores and reads basic variables.
   - Approach 2 forces the CPU to perform 64-bit multiplication (2LL *) and subtraction on every push/pop. This adds tiny microsecond delays.

3. Time Clumping:
   - For O(1) algorithms, the difference between the 90th percentile and 20th percentile is often just 2 or 3 milliseconds. That tiny math overhead causes the drop.
   
Interview Tip: Code the Pair approach (Approach 1) first. If the interviewer asks for O(1) extra space, explain the Math Trick (Approach 2), but you can point out the 64-bit memory reality to show deep system understanding!
*/
