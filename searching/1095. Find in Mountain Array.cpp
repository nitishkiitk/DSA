/// please make a map for storing the values that we have already called from mountainArray.grt()
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
//     int peak_found(MountainArray &mountainArr, int n){
//         int l=0,h=n-1,mid;
//         while(l<=h){
//             mid=(l+h)/2;
//             if(l+1<=h && mountainArr.get(0)>mountainArr.get(1)){return 0;}
//             if(l<=h-1 && mountainArr.get(n-1)>mountainArr.get(n-2)){return n-1;}
//             int a=mountainArr.get(mid), b=mountainArr.get(mid+1),c=mountainArr.get(mid-1) ;
//             if(a>b && a>c){
//                 return mid;
//             }
//             else if(a>c && a<b){
//                 l=mid+1;
//             }
//             else{h=mid-1;}
//         }
//         return -1;
//     }
    
//     int findInMountainArray(int target, MountainArray &mountainArr) {
//         int res=-1;
//         int n=mountainArr.length();
//         int peak=peak_found(mountainArr,n);
//         int pE=mountainArr.get(peak);
//         if(pE==target)
//             return peak;
//         int l1=0, h1=peak,mid1;
//         int l2=peak+1, h2=n-1,mid2;
//         while(l1<=h1){
//             mid1=(l1+h1)/2;
//             int val=mountainArr.get(mid1);
//             if(val==target){
//                 res=mid1;
//             }
//             else if(val>target){
//                 h1=mid1-1;
//             }
//             else{l1=mid1+1;}
//         }
//         if(res==-1){
//             while(l2<=h2){
//             mid2=(l2+h2)/2;
//             int val2=mountainArr.get(mid2);
//             if(val2==target){
//                 res=mid2;
//             }
//             else if(val2>target){
//                 l2=mid2+1;
//             }
//             else{l2=mid2-1;}
//             }
//         }
//         return res;
//     }
int findPeak(MountainArray &mountainArr){
        int s=0,e=mountainArr.length()-1,ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(s+1<=e && mountainArr.get(s+1)<mountainArr.get(s))
                return s;
            if(s<=e-1 && mountainArr.get(e-1)<mountainArr.get(e))
                return e;
            int m0=mountainArr.get(mid-1),m1=mountainArr.get(mid),m2=mountainArr.get(mid+1);
            if(m0<m1 && m1>m2){
                ans = mid;
                break;
            }
            else if(m2<m1)
                e=mid-1;
            else
                s=mid+1;
        }
        return ans;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int s=0,e=mountainArr.length()-1,mn=INT_MAX;
        // if(mountainArr.get(s)==target)
        //     return s;
        // else if(mountainArr.get(e)==target)
        //     return e;
        int peak=findPeak(mountainArr);
        cout<<peak<<endl;
        int pE=mountainArr.get(peak);
        if(pE==target)
            return peak;
        int lo=s,hi=peak-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int m=mountainArr.get(mid);
            if(m==target)
                return mid;
            else if(m<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        lo=peak+1,hi=e;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int m=mountainArr.get(mid);
            if(m==target)
                return mid;
            else if(m<target)
                hi=mid-1;
            else
                lo=mid+1;
        }
        return -1;
    }
};