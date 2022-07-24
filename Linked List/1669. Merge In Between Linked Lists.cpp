// You are given two linked lists: list1 and list2 of sizes n and m respectively.

// Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

// The blue edges and nodes in the following figure indicate the result:
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head=list1;
        if(a==0){
            head=list2;
        }
        // finding the previous node of a
        // finding the node b
        ListNode* node_a;
        ListNode* node_b;
        ListNode* temp=list1;
        int i=0;
        for(;i<a-1;i++){
            temp=temp->next;
        }
        node_a=temp;
        for(;i<b;i++){
            temp=temp->next;
        }
        node_b=temp;
        // finding the last node of list2
        ListNode* temp2=list2;
        while(temp2->next){
            temp2=temp2->next;
        }
        // merging the previous node of 'a' with list2 starting and list2 ending with next of node 'b'
        node_a->next=list2;
        temp2->next=node_b->next;
        return head;
    }
};