// First Method
int one_count(vector<int>nums, int n){
    int l=0, h=n-1, m=(l+h)/2;
    while(l<=h){
        m=(l+h)/2;
        if(nums[m]<1){h=m-1;}
        else if(nums[m]==1){
            if(m==n-1){return m+1;}
            else if(nums[m+1]==0){return m+1;}
            l=m+1;
        }
    }
    return 0;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> >res;
        int n=sizeof(mat)/sizeof(mat[0]);
        int m=sizeof(mat[0]);
        for(int i=0;i<n;i++){
            int count=one_count(mat[i],m);
            res.push_back(make_pair(count,i));
        }
        sort(res.begin(), res.end());
        vector<int> sol;
        for(int i=0;i<n;i++){
            sol.push_back(res[i].second);
        }
        return sol;
    }
};

// second method that accepted
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        for(int i=mat[0].size()-1;i>=0;i--){
            for(int j=mat.size()-1;j>=0;j--){
                if(mat[j][i]&&(i==mat[0].size()-1||(mat[j][i+1]==0)))
                    result.push_back(j);
            }
        }
        for(int i=mat.size()-1;i>=0;i--){
            if(mat[i][0]==0) result.push_back(i);
        }
        return vector<int>(result.rbegin(),result.rbegin()+k);
    }
};
