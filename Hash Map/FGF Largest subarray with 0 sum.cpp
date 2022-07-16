// Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int count=0;
        unordered_map<int, int>m;
        int sum=0;
        m[sum]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum)!=m.end()){
                int range=i-m[sum];
                count=max(count,range);
            }
            if(m.find(sum)!=m.end()){
                continue;
            }
            m[sum]=i;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends