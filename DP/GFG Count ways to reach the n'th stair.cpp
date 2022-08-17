// There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does matter).
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // function for calculating no of ways and saving the value
    long long int ways(int i,int n, vector<long long int>& vec){
        // termibnation condition
        if(i>n)return 0;
        if(i==n)return 1;
        // memoization check
        if(vec[i]!=-1){
            return vec[i];
        }
        // solve and save
        vec[i]=(ways(i+1,n,vec)%(1000000007)+ways(i+2,n,vec)%(1000000007))%(1000000007);
        // return
        return vec[i];
    }
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        // initlising the storing data structure here vector
        vector<long long int> vect(10001,-1);
        // calling the start from 0
        int i=0;
        //function call
        ways(i, n,vect);
        // returning
        return vect[0]%(1000000007);
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends