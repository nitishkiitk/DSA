// Union of two arrays can be defined as the common and distinct elements in the two arrays.
// Given two sorted arrays of size n and m respectively, find their union.

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        // resultant vector
        vector<int>res;
        // tmp map that will sort the all the elemnet
        map<int,int>temp;
        // inserting all the elements of arr1 in map
        for(int i=0;i<n;i++){
            temp[arr1[i]]++;
        }
        // inserting all the elements of arr2 in map
        for(int j=0;j<m;j++){
            temp[arr2[j]]++;
        }
        // now inserting all the elements of tmp map to res vector
        for(auto x:temp){
            res.push_back(x.first);
        }
        return res;
    }
};