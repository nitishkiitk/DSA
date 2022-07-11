// 
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        vector<int>res;
        // the two pointers i and j and start the pointer j with i only as it may possible that at that point only tyhe sum will be equal
        int i=0, j=i, flag=0;
        // flag checking is their any thing haapen or not 
        long long sum=arr[i];
        while(j<n){
            // if sum less then include mo5re element
            if(sum<s){
                j++;
                if(j<n){sum+=arr[j];}
                else{
                    res.push_back(-1);
                    flag=1;
                    break;
                }
            }
            // if sum greater then remove some element
            else if(sum>s){
                sum-=arr[i];
                i++;
            }
            // if equal then check whetrher i<=j or not
            else if(sum==s){
                flag=1;
                if(i<=j){
                    res.push_back(i+1);
                    res.push_back(j+1);
                    break;
                }
                else{
                    res.push_back(-1);
                    break;
                }
                
            }
        }
        if(!flag){
            res.push_back(-1);
        }
        return res;
    }
};