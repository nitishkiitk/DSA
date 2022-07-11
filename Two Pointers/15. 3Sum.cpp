// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // making map so that it will not push the same value multiple times
        map<vector<int>,int>m;
        // resultant vector
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(), nums.begin()+n);
        for(int i=0;i<n-2;i++){
            int j=i+1, k=n-1;
            int temp=-1*nums[i];
            while(j<k && k<n){
                int sum=nums[j]+nums[k];
                if(sum>temp){
                    k--;
                }
                else if(sum<temp){
                    j++;
                }
                else if(sum==temp){
                    m[{nums[i],nums[j], nums[k]}]++;
                    j++;
                    k--;
                }
            }
        }
        for(auto k:m){
            res.push_back(k.first);
        }
        return res;
    }
};