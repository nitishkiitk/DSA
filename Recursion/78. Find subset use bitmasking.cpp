// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
#include<cmath>
class Solution {
public:
    // returning vector declaration
    vector<vector<int>>res;
    // subset calculation  from bitwise vector
    void subset(vector<int>nums, vector<int>&vec){
        vector<int>temp;
        for(int i=0;i<vec.size();i++){
            if(vec[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        res.push_back(temp);
        return;
    }
    // bit vector calculation for a number
    void bitcal(vector<int>& nums,long int n){
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back(0);
        }
        int i=nums.size()-1;
        while(n>0){
            vec[i]=n%2;
            n=n/2;
            i--;
        }
        subset(nums, vec);
        return;
    }
    // main function
    vector<vector<int>> subsets(vector<int>& nums) { 
        long int power = pow(2, nums.size());
        for(long int i=0;i<power;i++){
            bitcal(nums,i);
        }
        return res;
    }
};