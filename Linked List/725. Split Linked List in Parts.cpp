// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // initialising resulting vector also initialising so that reamning will automatically will null
        vector<ListNode*>res(k,NULL);
        // calculating length
        int length=0;
        ListNode* temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        // calculating length and adding length for each part if there is any
        int minlength=length/k;
        int addlength=length%k;
        // calculating parts by using prev and curr
        ListNode* curr=head;
        ListNode* prev=NULL;
        int i=0;
        while(i<k && curr!=NULL){
            res[i]=curr;
            int add=0;
            if(addlength>0){add=1;}
            for(int j=0;j<(minlength+add);j++){
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            addlength--;
            i++;
        }
        return res;
    }
};