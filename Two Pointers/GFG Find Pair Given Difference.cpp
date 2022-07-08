// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.
bool findPair(int arr[], int n, int k){
    //code
    map<int,int>m;
    // int count=0;
    for(int i=0;i<n;i++){
        int b,c;
        if(arr[i]<k){
            b=k+arr[i];
        }
        else if(arr[i]>k){
            // we have to consider both the case where the both the elements are greater than target 
            // one is larger and other is smaller
            // both are smaller tyhan target
            b=arr[i]-k;
            c=k+arr[i];
        }
        if(m[b]){
            return true;
            break;
        }
        else if(m[c]){
            return true;
            break;
        }
        m[arr[i]]++;
    }
    return false;
    
}