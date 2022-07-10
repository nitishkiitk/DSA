// Given an integer array and a non-negative integer k, count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k

class Solution{
	public:
	int TotalPairs(vector<int>arr, int k){
	    // Code here
	    unordered_map<int,int>mp;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        // run the second loop on map rather than for whole loop as in the map we will have the disticnt element only with their frequency
        for(auto x:mp)
        {
            if(mp.find(x.first-k)!=mp.end())
            {
                if((x.first-k)==x.first)
                {
                    if(x.second>1)
                    count++;
                }
                else
                count++;
            }
        }
        return count;
	}

};