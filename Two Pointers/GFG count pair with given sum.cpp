// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
class Solution{   
public:
    int getPairsCount(int arr[], int n, int x) {
        int count=0;
        //create unordered_map so that the inserting will take O(1)
        unordered_map<int, int>m;
        for(int i=0; i<n;i++){
            int b=x-arr[i];
            // if x-arr[i] exist then unc count and then inc the occurence of arr[i]
            if(m[b]){
                count+=m[b];
            }
            m[arr[i]]++;
        }
        return count;
    }
};
