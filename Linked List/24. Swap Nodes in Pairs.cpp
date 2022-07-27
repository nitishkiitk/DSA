// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

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
    ListNode* swapPairs(ListNode* head) {
        // if LL is of size 1 or empty then return same
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        ListNode* temp=head->next;
        // solving using recursion 
        ListNode* h=swapPairs(temp->next);
        // atatching the remaining recursion result to the starting 
        temp->next=head;
        curr->next=h;
        return temp;
    }
};
