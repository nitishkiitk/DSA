// Given the head of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        // first will check if LL is empty or 1 inlength then will return same
        if(!head || head->next==NULL){
            return head;
        }
        // will save the head->next in temp that will use later as we have to remove the connection and add again after returning of function
        ListNode* temp=head->next;
        // breaking tyhe blink
        head->next=NULL;
        // calling the fn and saving that node
        ListNode* h=reverseList(temp);
        // after returning temp next to head
        temp->next=head;
        // return the head of the LL
        return h;
    }
};