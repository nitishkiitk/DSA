// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).
#include <algorithm>
class Solution {
public:
    int count(vector<vector<int>>& matrix, int m){
        int n=matrix.size();
        int count=0;
        for(int i=0;i<n;i++){
            auto it=matrix[i].begin();
            auto upper=upper_bound(it, it+n, m);
            count+=upper-it;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=INT_MAX, h=INT_MIN;
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]<l){l=matrix[i][0];}
            if(matrix[i][col-1]>h){h=matrix[i][col-1];}
        }
        int mid;
        while(l<=h){
            mid=l+(h-l)/2;
            int cnt=count(matrix,mid);
            if(cnt<k){l=mid+1;}
            else{
                int cnt_1=count(matrix,mid-1);
                if(cnt_1<k){return mid;}
                else{h=mid-1;}
            }
        }
        return -1;
    }
};