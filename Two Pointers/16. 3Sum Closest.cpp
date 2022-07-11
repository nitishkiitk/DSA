// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        //first sort the aaray
        sort(nums.begin(),nums.end());
        // declare resas 0 and min_diff=INT_MAX
        int res = 0;
        int min_diff = INT_MAX;
        
        for(int i=0; i<n-2; i++)
        {
            int lo = i+1;
            int hi = n-1;
            
            while(lo < hi)
            {
                int sum = nums[i] + nums[lo] + nums[hi];
                if(abs(target - sum) < min_diff)
                {
                    min_diff = abs(target - sum);
                    res = sum; 
                }
                // sum>target then high-- and if sum<target lo++
                else if(sum > target)
                {
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }
        return res;
    }
};