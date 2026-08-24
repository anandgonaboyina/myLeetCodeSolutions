//notLeetCode problem.
// It is a classic GeeksforGeeks / Coding Ninjas problem.
class Solution {
public:
    void insertSorted(stack<int> &st, int ele)
    {
        if(st.empty() || ele > st.top())
        {
            st.push(ele);
            return;
        }
        int t = st.top();
        st.pop();
        insertSorted(st, ele);
        st.push(t);

    }
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int t = st.top();
        st.pop();
        sortStack(st);
        insertSorted(st, t);
    }
};

/*
Think of this as unpacking a messy box, and then putting the items back in perfectly organized.

1. sortStack is the "Unpacker"
It blindly takes everything out of the box (st.pop()), one by one, holding each item in its hands (int t). Once the box is completely empty, it starts handing the items to the Organizer.
 
2. insertSorted is the "Organizer"
When handed an item (ele), it looks at the top of the box.

If the box is empty, or the item is bigger than what's on top, it simply drops it in (st.push(ele)).

If the item is smaller, the Organizer takes the top item out (st.pop()), sets it aside (int t), drops the new item in, and then puts the set-aside item back on top (st.push(t)).

A Quick 2-Element Trace:
Imagine sorting a stack [5, 2] (Top is 5).

sortStack pops 5. (Stack = [2])

sortStack pops 2. (Stack = [])

The box is empty, so the Unpacker starts putting things back!

Calls insertSorted(st, 2). Box is empty. Pushes 2. (Stack = [2])

Calls insertSorted(st, 5). 5 is greater than 2. Pushes 5. (Stack = [2, 5]). Sorted!

*/