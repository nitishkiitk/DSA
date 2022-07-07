// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
class Solution{   
public:
    int getPairsCount(int arr[], int n, int x) {
        // code here
        map<int,int>m;
        int i=0;
        int count=0;
        for(;i<n;){
            if(arr[i]==(x-arr[i])){
                int c=0;
                int val1=arr[i];
                while(i<n && arr[i]==val1){
                    i++;
                    c++;
                }
                count+=(c*(c-1))/2;
                // cout<<"alone"<<count<<endl;
            }
            else if(m.find(arr[i])!=m.end()){
                int c1=0;
                int j=i;
                int val=arr[i];
                while(i<n && arr[i]==val){
                    c1++;
                    i++;
                }
                m[(x-arr[j])]=c1;
                count+=c1*m[arr[j]];
                // cout<<"adding"<<count<<endl;
            }
            else{
                int c2=0;
                int j=i;
                int val2=arr[i];
                while(i<n && arr[i]==val2){
                    c2++;
                    // cout<<"c2"<<c2<<endl;
                    i++;
                }
                m[(x-arr[j])]=c2;
                // cout<<"insert"<<count<<m[5]<<endl;
            }
            
        }
        return count;
    }
};
