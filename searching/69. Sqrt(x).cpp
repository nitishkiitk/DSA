class Solution {
public:
    int mySqrt(int x) {
        if(x==0){return 0;}
        if(x==1){return 1;}
        long long int l=1, h=x/2, mid;
        while(l<=h){
            mid=l+(h-l)/2;
            if(mid*mid==x){return mid;}
            else if(mid*mid>x && (mid-1)*(mid-1)<x){
                return mid-1;
            }
            else if(mid*mid<x && (mid+1)*(mid+1)>x){return mid;}
            else if(mid*mid>x){h=mid-1;}
            else{l=mid+1;}
        }
        return 1;
    }
};