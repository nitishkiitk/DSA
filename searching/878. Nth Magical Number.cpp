class Solution {
public:
    
    int gcd(int a, int b){
        if(a==0){return b;}
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int n, int a, int b) {
        int min_number=min(a,b);
        long long int l=min_number, h=l*n;
        long long int mid;
        long long int res=0;
        while(l<=h){
            mid=(l+(h-l)/2);
            // number of factor of A till X is X/A
            // sum of number of factor of A and B till X is x/A + X/B - X/LCM(A,B)
            // LCM(A,B)=A*B/HCF(A,B);
            long long int count=mid/a +mid/b -mid/(a*b/gcd(a,b));
            if(count<n){l=mid+1;}
            else{
                res=mid;
                h=mid-1;
            }
            
        }
        long long int mod=1e9+7;
        res = res%mod;
        return res;
    }
};