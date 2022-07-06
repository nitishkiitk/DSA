class Solution {
    // vector<vector<int>>res;
public:
    vector<vector<int>>res;
    void subset(vector<int>& nums, vector<int>&temp, int i,int cnt, int n){
        if(i==n){
            res.push_back(temp);
        }
        temp[cnt]=nums[i];
        subset(nums, temp, i+1, cnt+1, n);
        subset(nums, temp, i+1, cnt, n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>res;
        vector<int>temp;
        int i=0, cnt=0;
        subset(nums,temp, i, cnt, n );
        return res;
        // void subset(vector<int>temp, int i, int cnt){
        //     if(i==n){
        //         res.push_back(temp);
        //         return;
        //     }
        //     temp[cnt]=nums[i];
        //     subset(temp,i+1, cnt+1);
        //     subset(temp,i+1, cnt);
        // }
        // subset(temp,i, cnt);
    }
};