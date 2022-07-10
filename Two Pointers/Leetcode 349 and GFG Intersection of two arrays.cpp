// print the count of elements in the intersection (or common elements) of the two arrays.

// For this question, the intersection of two arrays can be defined as the set containing distinct common elements between the two arrays. 
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        // making an unordered map
        unordered_map<int, int>temp;
        // res vector
        vector<int> res;
        // making count for all element =1
        for(int i=0;i<n;i++){
            temp[a[i]]=1;
        }
        // if it was previously exist then inc that element count=2
        for(int j=0;j<m;j++){
            if(temp[b[j]]){
                temp[b[j]]=2;
            }
        }
        // if the total count of that element is 2 then insert into res vector
        for(auto x:temp){
            if(x.second>=2){
                res.push_back(x.first);
            }
        }
        return res.size();
    }
};