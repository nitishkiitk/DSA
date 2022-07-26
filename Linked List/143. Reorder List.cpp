// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
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
    //finding the reverse of the list after the mid 
    ListNode* reversell(ListNode* head){
        if(!head || head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        head->next=NULL;
        ListNode* h=reversell(temp);
        temp->next=head;
        return h;
    }
    // finding the mid of the list
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    void reorderList(ListNode* head) {
        ListNode* mid=middleNode(head);
        ListNode* h2=reversell(mid);
        ListNode* h1=head;
        // merging the both list
        while(h2->next){
            ListNode* curr=h1->next;
            ListNode* future=h2->next;
            // playing with first list
            h1->next=h2;
            h1=curr;
            // playing with reversed list
            h2->next=curr;
            h2=future;
        }
    }
};