// first find the pivot point in the array
int pivot_finding(vector<int>& nums){
    int n=nums.size();
    int l=0,h=n-1;
    int m=(l+h)/2;
    while(l<=h){
        m=(l+h)/2;
        if(nums[m]<=nums[n-1]){h=m-1;}
        else{
            if(nums[m]>nums[m+1]){return m;}
            else{l=m+1;}
        }
    }
    return -1;
}
// then apply the key_finding functuion seperately for each part 
int key_finding(vector<int>& nums, int l, int h, int target){
    int m =(l+h)/2;
    while(l<=h){
        m=(l+h)/2;
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]>target){h=m-1;}
        else{l=m+1;}
    }
    return -1;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=pivot_finding(nums);
        int ans=key_finding(nums,0,pivot,target);
        if(ans==-1){
            ans=key_finding(nums,pivot+1,n-1,target);
            if(ans!=-1){return ans;}
        }
        return ans;
    }
    
};