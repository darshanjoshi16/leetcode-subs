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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL) slow=slow->next;
        while(slow!=NULL){
            if(s.top()!=slow->val) return false;
            s.pop();
            slow=slow->next;    
        }
        return s.empty();
    }
};
