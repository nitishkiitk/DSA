class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here 
        int done =0;
        while(!done){
            int i=0;
            done=1;
            while(i<n-1){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i+1];
                    arr[i+1]=arr[i];
                    arr[i]=temp;
                    done=0;
                }
                i++;
            }
            
        }
    }
};