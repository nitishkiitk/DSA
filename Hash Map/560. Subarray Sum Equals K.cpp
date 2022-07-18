// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count =0;
        unordered_map<int,int>m;
        int n=nums.size();
        int sum=0;
        m[sum]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-k)!=m.end()){
                //inc the count by m[sum-k] because we have to count
                count+=m[sum-k];
            }
            // simply inc that element because we have to count the total subarray
            m[sum]++;
        }
        return count;
        
    }
};