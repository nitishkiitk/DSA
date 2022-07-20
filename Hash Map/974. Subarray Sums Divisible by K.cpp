// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.
//here I am using the concept of if a subarray sum is divisible then the previous sum reminder and right now sum reminder will be equal
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
        int sum=0;
        unordered_map<int, int>m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(rem==0){count++;}
            if(m.find(rem)!=m.end()){
                count+=m[rem];
                m[rem]++;
            }
            else{
                m[rem]++;
            }
        }
        return count;
    }
};