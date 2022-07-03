//  we have given two array and have to find the extra element index in a array
// we will apply the binary search according to largest one array i.e l=0, h=n-1
int findExtra(int a[], int b[], int n) {
        // add code here.
        int l=0, h=n-1, m=(l+h)/2;
        while(l<=h){
            m=(l+h)/2;
            // if they inserted at starting then we will check if m==0 then return if they didn't match
            if(m==0){
                if(a[m]!=b[m]){
                    return m;
                }
            }
            // if they inserted at last then in smaller array that last index number doesn't exist so will return that
            if(b[m]==NULL){
                return m;
            }
            // if both element match it means they inserted somewhere next to that
            if(a[m]==b[m]){
                l=m+1;
            }
            else{
                // if that does,'t match then we will check with previous one if match then it means they inserted before so h=m-1
                if(a[m]==b[m-1]){
                    h=m-1;
                }
                // if previous also didn't match then it means they inserted at that point only so will return that
                else{
                    return m;
                }
            }
        }
    }