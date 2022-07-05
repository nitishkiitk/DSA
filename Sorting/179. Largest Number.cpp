// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.
class Solution {
public:
    // comparator for sorting
    static bool cmp(int n1, int n2){
        string s1=to_string(n1);
        string s2= to_string(n2);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(), nums.end(),cmp);
        for(int i=0;i<nums.size();i++){
            res+=to_string(nums[i]);
        }
        if(nums[0]==0){return "0";}
        return res;
    }
};