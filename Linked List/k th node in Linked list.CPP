// Given a singly linked list and a number k. Write a function to find the (N/k)th element, where N is the number of elements in the list. We need to consider ceil value in case of decimals.

// Input:
// The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer N. The second line consists of N spaced integers.The last line consists of an integer k.

// Output:
// Print the data value of (N/k)th node in the Linked List.

// User Task:
// The task is to complete the function fractional_node() which should find the n/kth node in the linked list and return its data value.

// Constraints: 
// 1 <= T <= 100
// 1 <= N <= 100
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int fractional_node(struct Node* head,int k);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Node* ptr,*start = NULL,*ptr1;
        int n,i;
        cin>>n;
        
        for(i=0;i<n;i++)
        {
            int value;
            cin>>value;
            
            ptr=new Node(value);
            
            if(start==NULL)
            {
                start=ptr;
                ptr1=ptr;
            }
            else
            {
                ptr1->next=ptr;
                ptr1=ptr1->next;
            }
        }
        ptr1->next=NULL;
        int k;
        cin>>k;
        int p = fractional_node(start,k);
        cout<<p<<endl;
    }
}

// } Driver Code Ends


/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
int fractional_node(struct Node *head, int k)
{
    // your code here
    // Corner cases
    // if (k <= 0 || head == NULL)
    //     return NULL;
 
    Node* fractionalNode = NULL;
     
    // Traverse the given list
    int i = 0;
    for (Node* temp = head; temp != NULL; temp = temp->next) {
 
        // For every k nodes, we move fractionalNode one
        // step ahead.
        if (i % k == 0) {
 
            // First time we see a multiple of k
            if (fractionalNode == NULL)
                fractionalNode = head;
 
            else
                fractionalNode = fractionalNode->next;
        }
        i++;
    }
    return fractionalNode->data;
}
