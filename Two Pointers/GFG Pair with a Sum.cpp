// Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
        //In this case the array is not sorted so I applied map rather than two pointer
	    map<int, int>m;
	    for(int i=0;i<n;i++){
	        if(m.find(arr[i])!=m.end()){
	            return true;
	        }
	        m[(x-arr[i])]=i;
	    }
	    return false;
	}
};