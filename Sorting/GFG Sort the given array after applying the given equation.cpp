// Given a sorted integer array Arr[ ] of size N, and three integers A, B, and C. The task is to find a new array  where ith element of the new array = A * Arr[i] * Arr[i] + B * Arr[i] + C. You have to print the new array in sorted (ascending) order.

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int a, b, c;
        cin >> a >> b >> c;
        int n;
        cin >> n;
        vector<long long int>arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long int>ans = sortArray(arr, n, a, b, c);
        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
return 0;
}

// } Driver Code Ends


vector<long long> sortArray(vector<long long>arr, int n, long long A, long long B, long long C){
    //complete the function here
    // finding the peak point of the curve
    long long mid= -B/(2*A);
    int peak;
    for(int i=0;i<n;i++){
        if(mid<=arr[i]){
            peak=i;
            break;
        }
    }
    vector<long long>res;
    // when A>0 then one is dec and another in inc so this one
    if(A>=0){
        int i=peak;
        int j=peak-1;
        for(;i<n && j>=0;){
            long long f1=A*arr[i]*arr[i]+B*arr[i]+C;
            long long f2=A*arr[j]*arr[j]+B*arr[j]+C;
            if(f1<f2){
                res.push_back(f1);
                i++;
            }
            else{
                res.push_back(f2);
                j--;
            }
        }
        for(;i<n;){
            long long f1=A*arr[i]*arr[i]+B*arr[i]+C;
            res.push_back(f1);
            i++;
        }
        for(;j>=0;){
            long long f2=A*arr[j]*arr[j]+B*arr[j]+C;
            res.push_back(f2);
            j--;
        }
    }
    // when A<0 both part will be decreasing so this one
    else{
        int i=n-1;
        int j=0;
        for(;i>=peak && j<peak;){
            long long f1=A*arr[i]*arr[i]+B*arr[i]+C;
            long long f2=A*arr[j]*arr[j]+B*arr[j]+C;
            if(f1<f2){
                res.push_back(f1);
                i--;
            }
            else{
                res.push_back(f2);
                j++;
            }
        }
        for(;i>=peak;){
            long long f1=A*arr[i]*arr[i]+B*arr[i]+C;
            res.push_back(f1);
            i--;
        }
        for(;j<peak;){
            long long f2=A*arr[j]*arr[j]+B*arr[j]+C;
            res.push_back(f2);
            j++;
        }
    }
    return res;
    
}