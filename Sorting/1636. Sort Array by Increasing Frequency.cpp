class Solution {
public:
    //  comparator function
     static bool compare(pair<int,int>p1, pair<int,int>p2){
        if(p1.second==p2.second){
            return p1.first>p2.first;
        }
        else{ return p1.second<p2.second;}
    }
    // frequency count 
    int fre_cnt(vector<int>&nums, int k){
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==k){cnt++;}
        }
        return cnt;
    }
    // main function
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>>main;
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int cnt=fre_cnt(nums,nums[i]);
            main.push_back({nums[i], cnt});
        }
        sort(main.begin(), main.end(),compare);
        for(int j=0;j<n;j++){
            int ele=main[j].first;
            res.push_back(ele);
        }
        return res;
    }
};