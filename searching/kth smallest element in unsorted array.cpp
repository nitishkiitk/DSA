/*

Given an integer array, find k'th smallest element in the array where k is a positive integer less than or equal to the length of array.

Input : [7, 4, 6, 3, 9, 1], k = 3
Output: 4
Explanation: The 3rd smallest array element is 4

Input : [1, 5, 2, 2, 2, 5, 5, 4], k = 5
Output: 4
Explanation: The 5th smallest array element is 4

*/

class Solution
{
public:
	int count_element(vector<int> const &nums, int ele){
		int i=0, n=nums.size(),count=0;
		for(i=0;i<n;i++){
			if(nums[i]<=ele){
				count++;
			}
		}
		return count;
	}
	int findKthSmallest(vector<int> const &nums, int k)
	{
		// Write your code here...
		int n=nums.size();
		int l=INT_MAX,h=INT_MIN, mid;
		for(int j=0;j<n;j++){
			if(nums[j]<=l){
				l=nums[j];
			}
			if(nums[j]>=h){
				h=nums[j];
			}
		}
		
		while(l<=h){
			mid=l+(h-l)/2;
			// int count=count_element(nums,nums[mid]);
			int count=count_element(nums,mid);
			if(count<k){
				l=mid+1;
			}
			else{
				int count_1=count_element(nums,mid-1);
				if(count_1<k){
					return mid;
				}
				else{
					h=mid-1;
				}
			}
		}
		return -1;
	}
};
