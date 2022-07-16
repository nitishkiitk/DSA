// Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int n, int k) 
    { 
        // Complete the function
        int count=0;
        unordered_map<int, int>m;
        int sum=0;
        m[sum]=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(m.find(sum-k)!=m.end()){
                int range=i-m[sum-k];
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

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends