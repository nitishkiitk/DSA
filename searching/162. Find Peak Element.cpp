
int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // first solve for length 1 and 2
        if(n == 1) return 0;
        if(n == 2)return nums[0] > nums[1] ? 0 : 1;
        //  then solve for 1 to n-2 and the first and last element will be taken care seperately
        int i = 1, j = n-2;
        while(i <= j){
            int mid = j + (i-j)/2;
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
                else if(nums[mid+1] > nums[mid]) i = mid+1;
                else if(nums[mid-1] >= nums[mid]) j = mid-1;
        }
        //  first and last element checking
        if(nums[0] > nums[1]) return 0;
        else if(nums[n-1] > nums[n-2]) return n-1;
        return -1;
    }