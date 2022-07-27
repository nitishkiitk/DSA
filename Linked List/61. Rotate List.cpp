// Given the head of a linked list, rotate the list to the right by k places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head;
        // length measurement
        int n=1;
        while(temp->next){
            temp=temp->next;
            n+=1;
        }
        // saving start and end for future use
        ListNode* end=temp;
        ListNode* start=head;
        // rptation euals to the k%n 
        k=k%n;
        temp=head;
        // will break at n-k
        for(int i=0;i<(n-k-1);i++){
            temp=temp->next;
        }
        end->next=start;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};