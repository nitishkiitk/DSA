/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int peak_found(MountainArray &mountainArr, int n){
        int l=0,h=n-1,mid;
        while(l<=h){
            mid=(l+h)/2;
            if(mountainArr.get(mid)>mountainArr.get(mid+1) && mountainArr.get(mid)>mountainArr.get(mid-1)){
                return mid;
            }
            else if(mountainArr.get(mid)>mountainArr.get(mid-1) && mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{h=mid-1;}
        }
        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int res=-1;
        int n=mountainArr.length();
        int peak=peak_found(mountainArr,n);
        int l1=0, h1=peak,mid1;
        int l2=peak+1, h2=n-1,mid2;
        while(l1<=h1){
            mid1=(l1+h1)/2;
            if(mountainArr.get(mid1)==target){
                res=mid1;
            }
            else if(mountainArr.get(mid1)>target){
                h1=mid1-1;
            }
            else{l1=mid1+1;}
        }
        if(res==-1){
            while(l2<=h2){
            mid2=(l2+h2)/2;
            if(mountainArr.get(mid2)==target){
                res=mid2;
            }
            else if(mountainArr.get(mid2)>target){
                l2=mid2+1;
            }
            else{l2=mid2-1;}
            }
        }
        return res;
    }
};