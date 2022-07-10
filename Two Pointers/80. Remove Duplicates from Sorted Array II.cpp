// Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // iterator for accessing the element and remmoving it
        auto it=nums.begin();
        int j;
        // here i am using two pointer one for i and other for j and comparing it
        for(int i=0, j=i+2; j<nums.size();i++,j++){
            // using erase function tp erase the element in a vector vectro.erase(iterator) or vector.erase(it1, it2) for erse a range of values
            if(nums[i]==nums[j]){
                nums.erase(it+i);
                i--;
                j--;
            }
        }
        return nums.size(); 
    }
};
