// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
// I am applying the concept of summing two array of all the possibiulities ans then checking with another two arrays possibilities

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count=0;
        unordered_map<int,int>m;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=0;
                sum+=nums1[i]+nums2[j];
                m[sum]++;
            }
        }
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                int sum1=0;
                sum1+=nums3[i]+nums4[j];
                int s=-1*sum1;
                if(m.find(s)!=m.end()){
                    count+=m[s];
                }
            }
        }
        return count;
    }
};