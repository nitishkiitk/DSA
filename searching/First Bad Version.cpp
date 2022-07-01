// find first bad nummber
// isBadVersion was already defined
int firstBadVersion(int n) {
        int l=1, h=n,m=l+(h-l)/2;
        while(l<=h){
            m=l+(h-l)/2;
            if(isBadVersion(m)==false){
                l=m+1;
            }
            else{
                if(m==1){return 1;}
                if(isBadVersion(m-1)==false){
                    return m;
                }
                else{
                    h=m-1;
                }
            }
        }
        return -1;
    }