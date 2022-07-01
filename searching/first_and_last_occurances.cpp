vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,h=n-1,m=(l+h)/2;
        vector<int>result;
        int first=-1, last=-1;
//      checking first occurance
        while(l<=h){
            m=(h+l)/2;
            if(target>nums[m]){
                l=m+1;
            }
            else if(target<nums[m]){
                h=m-1;
            }
            else if(nums[m]==target){
                if(m==0){
                    first=m;
                    break;
                }
                else{
                    if(nums[m]>nums[m-1]){
                        first=m;
                        break;
                    }
                    h=m-1;
                }
                
            }
        }
        // checking last occurance
        l=0,h=n-1;
        while(l<=h){
            m=(h+l)/2;
            if(target>nums[m]){
                l=m+1;
            }
            else if(target<nums[m]){
                h=m-1;
            }
            else if(nums[m]==target){
                if(m==n-1){
                    last=m;
                    break;
                }
                else{
                    if(nums[m]<nums[m+1]){last=m; break;}
                    l=m+1;
                }
                
            }
        }
        result.push_back(first);
        result.push_back(last);
        return result;
    }