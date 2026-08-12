/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 //my brute force TC is N and Sc is 1 got 100% beats though its done in two passes 
 /*
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(head && !head->next && n==1) return nullptr;
        int len =0, fn = 0;
        ListNode* ptr = head;
        while(ptr)
        {
            ptr = ptr->next;
            len++;
        }
        fn = len-n;  // node before that we delete
        if(fn == 0)
            {
                ListNode* temp = head;
                head=head->next;
                delete temp;
                return head;
            }
        ptr = head;
        for(int i=1; i<fn; i++)
        {
            ptr = ptr->next;
        }
        ListNode* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        return head;
    }
};
*/
//optimal solution of above logic in single pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(head && !head->next && n==1) return nullptr;
        ListNode* dummy  = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        int cnt=1;
        while(fast && cnt <=n)
        {
            fast = fast->next;
            cnt++;
        }
        while(fast->next)
        {
            slow =slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;          // if head is need to delete then slow = dummy so dummy->next = head->next fine it saves us
        delete temp;
        return dummy->next;
    }
};
//## Notes logic behind
/*
 Creating a dummy node that points to head, and start both fast and slow at this dummy. This completely protects you from the edge case where we have to delete the very first node of the list.
ny Using two pointers, fast and slow. Move fast forward exactly N steps. Now there is a gap of $N$ nodes between slow and fast.Move both pointers forward one step at a time until fast reaches the very last node.Because of the exact N-nodes gap, slow will now be pointing exactly at the node right before the one you need to delete.Re-wire the pointer: slow->next = slow->next->next;

*/