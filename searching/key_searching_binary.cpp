// here we are searching the target key in a sorted(ascending) array nums
int search(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0, h=n-1,m=(l+h)/2;
    while(l<=h){
        m=(l+h)/2;
        if(nums[m]==target){return m;} 
        else if(target>nums[m]){
            l=m+1;
        }
        else{h=m-1;}
    }
    return -1;
}