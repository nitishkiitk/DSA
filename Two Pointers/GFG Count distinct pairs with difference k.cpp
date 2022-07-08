// Given an integer array and a non-negative integer k, count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k

class Solution{
	public:
	int TotalPairs(vector<int>arr, int k){
	    // Code here
	    int n=arr.size();
	    unordered_map<int,int>m;
        int count=0;
        int i=0;
        for(int j=0;j<n;J++){
            m[arr[j]]++;
        }
        for(;i<n;){
            int b,c;
            if(arr[i]<k){
                b=k+arr[i];
                int a=arr[i];
                while(arr[i]==a){
                    i++;
                }
            }
            else if(arr[i]>k){
                // we have to consider both the case where the both the elements are greater than target 
                // one is larger and other is smaller
                // both are smaller tyhan target
                b=arr[i]-k;
                if(k>0){c=k+arr[i];}
                int a=arr[i];
                while(arr[i]==a){
                    i++;
                }
            }
            if(m[b]){
                count++;
            }
            else if(m[c]){
                count++;
            }
            
        }
        return count;
        // unordered_map<int,int>mp;
        // int count=0;
        // for(int i=0;i<arr.size();i++)
        // {
        //     mp[arr[i]]++;
        // }
        // for(auto x:mp)
        // {
        //     if(mp.find(x.first-k)!=mp.end())
        //     {
        //         if((x.first-k)==x.first)
        //         {
        //             if(x.second>1)
        //             count++;
        //         }
        //         else
        //         count++;
        //     }
        // }
        // return count;
    	}

};