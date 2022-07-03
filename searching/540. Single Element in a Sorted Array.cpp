int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1, m=l+(h-l)/2;
        if(n==1){return nums[0];}
        while(l<=h){
            m=l+(h-l)/2;
            if(m==0 && nums[m]!=nums[m+1]){return nums[m];}
            if(m==n-1 && nums[m]!=nums[m-1]){return nums[m];}
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1]){return nums[m];}
            else if(nums[m]==nums[m-1]){
                if((m-1)%2==0){l=m+1;}
                else{h=m-1;}
            }
            else if(nums[m]==nums[m+1]){
                if((m)%2==0){l=m+2;}
                else{h=m-1;}
            }
        }
        return -1;
    }