// C++ program to find the only repeating element in an
// array of size n and elements from range 1 to n-1.
#include <bits/stdc++.h>
using namespace std;


// Returns index of second appearance of a repeating element
// The function assumes that array elements are in range from
// 1 to n-1.
int FindRepeatingElement(int arr[], int size){
	int lo = 0;
	int hi = size - 1;
	int mid;
	
	while(lo <= hi){
		mid = (lo+hi)/2;
		
		if(arr[mid] <= mid){
			hi = mid-1;
		}
		else{
			lo = mid + 1;
		}
	}
	
	return lo;
}

// Driver code
int main()
{
	int arr[] = {1, 2, 3, 3, 4, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int index = findRepeatingElement(arr, n);
	if (index != -1)
		cout << arr[index];
	return 0;
}
