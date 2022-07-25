// Given the head of a singly linked list, return true if it is a palindrome.
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
    // reverse the linked list function
    ListNode* reverselist(ListNode* head){
        if(!head || head->next==NULL){
            return head;
        }
        ListNode* temp=head->next;
        head->next=NULL;
        ListNode* h= reverselist(temp);
        temp->next=head;
        return h;
    }
    
    bool isPalindrome(ListNode* head) {
        int size=1;
        ListNode* temp=head;
        // if empty or size 1 list then return true
        if(!head || head->next==NULL){
            return true;
        }
        while(temp->next){
            size++;
            temp=temp->next;
        }
        int n=size;
        // checking for even size linked list
        if(n%2==0){
            ListNode* mid;
            ListNode* temp2=head;
            for(int i=0;i<n/2;i++){
                temp2=temp2->next;
            }
            mid=temp2;
            ListNode* endhead=reverselist(mid);
            ListNode* starthead=head;
            for(int i=0;i<n/2;i++){
                // cout<<"yes"<<endl;
                if(endhead->val !=starthead->val){return false;}
                endhead=endhead->next;
                starthead=starthead->next;
            }
            return true;
        }
        // checking for even size linked list
        else if(n%2!=0){
            ListNode* mid;
            ListNode* temp2=head;
            for(int i=0;i<n/2;i++){
                temp2=temp2->next;
            }
            mid=temp2;
            ListNode* endhead=reverselist(mid);
            ListNode* starthead=head;
            for(int i=0;i<=n/2;i++){
                if(endhead->val !=starthead->val){return false;}
                endhead=endhead->next;
                starthead=starthead->next;
            }
            return true;
        }
        return false;
        
    }
};