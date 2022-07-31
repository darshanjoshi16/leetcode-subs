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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(0);
        ListNode* podd = odd;
        ListNode* even = head;
        ListNode* peven = even;
        
        while(even && even->next){
                odd->next = even->next;
                even->next = even->next->next;
                odd->next->next=NULL;
                odd = odd->next;
                if(even->next==NULL){
                    even->next = podd->next;
                    break;
                }
                even = even->next;
                
        }
        
        if(even){
             even->next = podd->next;
        }
        
        return peven;
        
    }
};
