// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res;
        int pivot;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                pivot=i;
                break;
            }
        }
        int i=pivot;
        int j=pivot-1;
        for(;i<nums.size() && j>=0;){
            int f1=nums[i]*nums[i];
            int f2=nums[j]*nums[j];
            if(f1<f2){
                res.push_back(f1);
                i++;
            }
            else{
                res.push_back(f2);
                j--;
            }
        }
        for(;i<nums.size();){
            res.push_back(nums[i]*nums[i]);
            i++;
        }
        for(;j>=0;){
            res.push_back(nums[j]*nums[j]);
            j--;
        }
        return res;
        
    }
};