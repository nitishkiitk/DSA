// only unique pair is possible
vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0, h=n-1;
        int first=-1, last=-1;
        vector<int>result;
        while(l<=h){
            if(numbers[l]+numbers[h]==target){
                first=l+1;
                last=h+1;
                break;
            }
            else if(numbers[l]+numbers[h]>target){
                h--;
            }
            else{
                l++;
            }
        }
        result.push_back(first);
        result.push_back(last);
        return result;
    }