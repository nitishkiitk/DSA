// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        map<vector<int>, int>m;
        vector<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(), nums.begin()+n);
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int k=j+1, l=n-1;
                //take care of the data type max and min value and type cast accordingly
                long temp=long(target)-long(nums[i]+nums[j]);
                while(k<l && l<n){
                     //take care of the data type max and min value and type cast accordingly
                    long sum=nums[k]+nums[l];
                    if(sum>temp){
                        l--;
                    }
                    else if(sum<temp){
                        k++;
                    }
                    else{
                        m[{nums[i],nums[j],nums[k],nums[l]}]++;
                        k++;
                        l--;
                    }
                }
            }
        }
        for(auto p:m){
            res.push_back(p.first);
        }
        return res;
        
    }
};