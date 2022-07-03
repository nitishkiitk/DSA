 bool isPossible(vector<int>& nums, int k){
        int n=nums.size();
        if(k!=0 and nums[n-k]>=k and nums[n-k-1]<=k){
            return true;
        }
        return false;
    }
    
    int hIndex(vector<int>& nums) {
        int n=nums.size();

        if(nums[0]>=n){
            return n;
        }
        
        
        int l=1,r=n;
        int res=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,mid)){
                res=mid;
                l=mid+1;
            }else{
                if(nums[n-mid]>=mid and nums[n-mid-1]>mid){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }

        return res;
    }