// Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

// Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
class Solution {
public:
// Comparator
    static bool cmp(pair<int, int>p1, pair<int , int>p2){
        // if the arr1 element will ended then we will move to the remaining elemmnt and compare them only
        if(p1.second == INT_MAX && p2.second==INT_MAX){
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int arr[1001];
        for(int i=0;i<1001;i++){
            arr[i]=INT_MAX;
        }
        for(int i=0;i<arr2.size();i++){
            arr[arr2[i]]=i;
        }
        vector<pair<int,int>>vec;
        for(int i=0;i<arr1.size();i++){
            vec.push_back({arr1[i], arr[arr1[i]]});
        }
        sort(vec.begin(), vec.end(),cmp);
        vector<int>res;
        for(int i=0;i<vec.size();i++){
            res.push_back(vec[i].first);
        }
        return res;
    }
};