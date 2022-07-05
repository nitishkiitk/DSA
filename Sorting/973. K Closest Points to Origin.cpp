// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).
class Solution {
public:
    // comparator 
    static bool cmp(vector<int>p1, vector<int>p2){
        int d1=p1[0]*p1[0]+p1[1]*p1[1];
        int d2=p2[0]*p2[0]+p2[1]*p2[1];
        return d1<d2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(),cmp);
        vector<vector<int>>res;
        for(int i=0;i<k;i++){
            res.push_back(points[i]);
        }
        return res;
    }
};