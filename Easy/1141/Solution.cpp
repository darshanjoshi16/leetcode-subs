/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//using the floyd cycle detection algorithm
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        //we are using the concept of slow pointer and fast pointer by initializing at the head of node
        ListNode *slow = head, *fast = head;
        //cycle detection algo
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
    }
};
