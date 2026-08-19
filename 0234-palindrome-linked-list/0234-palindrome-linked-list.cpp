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

 //my brute force solution TC is N and Sc is N because N chars memory limit exceed after 75/93 tests passed
 //the String Trap (O(N^2) Time): In C++, writing s = s + char does not just add a character to the end. It creates a brand new string in memory, copies the entire existing string over, adds the new character, and then destroys the old string
 // this solution is not preferred though logic is fine 

//  Casting (char)ptr->val for numbers is very dangerous in C++. If ptr->val is 10, casting it to a char turns it into a newline character (\n). 
//  If it is 0, it becomes the null terminator (\0)
/*
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* ptr = head;
        string s ="";
        while(ptr)
        {
            s = s + (char)(48 + ptr->val);  // danger ahead if we do directly that (char)ptr->val
            ptr = ptr->next;
        }

        // for(int i=0; i<s.size()/2; i++)
        //    { 
        //     if(s[i] != s[s.size()-1-i])
        //         return false;
        //     }
        // return true;
        // or below
        string revL = s;
        reverse(revL.begin(), revL.end());
        return revL == s;
    }
};

*/
//my brute force solution implementing using the vector got 58% beats
//Tc is N and SC is N
/*
class Solution{
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* ptr = head;
        vector<int> nums;
        while(ptr)
        {
            nums.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i=0; i<nums.size()/2; i++)
           { 
            if(nums[i] != nums[nums.size()-1-i])
                return false;
            }
        return true;
    }
};
*/

//optimal solution for Sc to 1  // need to complete this follow up Qn
// using the Tortoise and Hare i find middle and then reverse the last half of LL and compare from last and first
// got 100% beats as TC is N and SC is 1
/*
class Solution{
public:
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = head;
        while(fast &&  fast->next)
       {
            slow = slow->next;
            fast = fast->next->next;
       }
     //here slow sit at middle of the linkedlist whatever the size if even or odd it sit at n/2
       ListNode* tail = reverseLL(slow);
       while(ptr != slow)
       {
        if(ptr->val != tail->val)
            return false;
        ptr = ptr->next;
        tail = tail->next;
       }
    return true;
    }
};

*/

//revision : 1
//my brute force solution 1
// TC is N and SC is N
/*
class Solution{
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        stack<int> st;
        ListNode* ptr = head;
        while(ptr)
        {
            st.push(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while(ptr)
        {
            if(ptr->val != st.top())
                return false;
            st.pop();
            ptr= ptr->top
        }
        return true;
    }
};
*/
//optimal solution
// TC is N and SC is N
class Solution{
public:
    ListNode* reverseLL(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* ptr =head;
        ListNode* prev = nullptr;
        while(ptr)
        {
            ListNode* temp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* tail = reverseLL(slow);
        while(ptr != slow)
        {
            if(ptr->val != tail->val)
                return false;
            tail= tail->next;
            ptr= ptr->next;
        }
        return true;
    }
};

