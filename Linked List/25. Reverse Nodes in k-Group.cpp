// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr=head;
        int count=0;
        // check the pair 
        while(curr && count<k){
            curr=curr->next;
            count++;
        }
        //' if the size of LL is leaa than k then return the sa,me'
        if(count<k){
            return head;
        }
        // reversing the size k LL
        ListNode* prev=NULL;
        ListNode* temp=head;
        for(int i=0;i<k;i++){
            ListNode* temp2=temp->next;
            temp->next=prev;
            prev=temp;
            temp=temp2;
        }
        // recu8rsion call 
        head->next=reverseKGroup(temp,k);
        // retrurning
        return prev;
    }
};