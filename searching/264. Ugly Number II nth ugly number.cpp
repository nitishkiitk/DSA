class Solution {
public:
    bool isUgly(int n) {
        while(n>=1){
            if(n==1){return true;}
            if(n%2!=0 && n%3!=0 && n%5!=0){return false;}
            if(n%2==0){n=n/2;}
            else if(n%3==0){n=n/3;}
            else if(n%5==0){n=n/5;}
        }
        return false;
    }
    // int count(int n){
    //     int count=0;
    //     for(int i=1;i<=n;i++){
    //         if(isUgly(i)){count++;}
    //     }
    //     return count;
    // }
    int nthUglyNumber(int n) {
        // int l=1, h=INT_MAX-1,mid;
        // while(l<=h){
        //     if(count(mid)<n){l=mid+1;}
        //     else{
        //         if(count(mid-1)<n){return mid;}
        //         else{h=mid-1;}
        //     }
        // }
        // return -1;
        int cnt=1;
        int i=1;
        while(cnt<=n){
            if(isUgly(i)){cnt++;}
            i++;
        }
        return i-1;
    }
};