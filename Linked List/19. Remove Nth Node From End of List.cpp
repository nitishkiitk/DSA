// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow=head;
        ListNode* fast=head;
        int i=1;
        while(i<=n){
            fast=fast->next;
            i++;
        }
        // if yout fast is null then ypu have delete the first elemet so change the head simply
        if(!fast){
            ListNode* tmp=head->next;
            delete(head);
            return tmp;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* tmp=slow->next;
        slow->next=slow->next->next;
        delete(tmp);
        return head;
        
    }
};