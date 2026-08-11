/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/
// my brute force solution Tc is N and Sc is N
/*
class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        if(!head || !head->next) return 0;
        unordered_set<ListNode*> nodes;
        ListNode* cycleEnd = nullptr;
        ListNode* ptr = head;
        int ans =0;
        while(ptr)
        {
            if(nodes.contains(ptr->next))
            {
                cycleEnd = ptr;
                ptr = ptr->next;  //cycle starting node
                break;
            }
            nodes.insert(ptr);
            ptr = ptr->next;
        }
        if(cycleEnd)
        {        
            while(ptr != cycleEnd)
                {
                    ans++;
                    ptr = ptr->next;
                }
            return ans+1;
        }
        return ans;
    }
};
*/
//optimal solution using the Tortoise and Hare
// Tc is N and SC is 1
class Solution{
    public:
    int findLengthOfLoop(ListNode *head)
    {
        if(!head || !head->next) return 0;
        ListNode* slow = head;
        ListNode* fast = head;
        int ans=0;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)   
                break;
            // or if(fast && fast->next) break; this will also work if loop there
        }
        if(slow == fast)
        {
            slow = slow->next;  // points to starting of the loop
            while(slow != fast)
            {
                ans++;
                slow = slow->next;
            }
            return ans+1;
        }
        return ans;
    }
};