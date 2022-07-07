// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
// class Solution {
// public:
//     //Recursion Approach:
//     //Two options at each step - once take it and once don't take the nums[i]
//     vector<vector<int>> ans;
//     void solve(vector<int>& nums, int i, vector<int> temp){
//         if(i == nums.size()){
//             ans.push_back(temp);
//         }else{
//             solve(nums, i + 1, temp); //skip the nums[i]
//             temp.push_back(nums[i]);
//             solve(nums, i + 1, temp); //take the nums[i]
//         }
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> temp;
//         solve(nums, 0, temp);
//         return ans;
//     }
// };

class Solution {
public:
    //intializing a return array
    vector<vector<int>>res;
    //function to compute the subsets
    void subset(vector<int>& nums,int i,vector<int>temp){
        if(i==nums.size()){
            res.push_back(temp);
            return;
        }
        subset(nums,i+1,temp);
        temp.push_back(nums[i]);
        subset(nums, i+1, temp);
        
    }
    //mmain function
    vector<vector<int>> subsets(vector<int>& nums) {
        int i=0;
        vector<int>temp;
        subset(nums,i,temp);
        return res;
        
    }
};