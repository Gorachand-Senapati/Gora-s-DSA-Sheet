class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        for(int i=0;i<n-1;i++){
              for(int j=0;j<n-i-1; j++){
        if(arr[j]> arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
       }
    }
    }
};
//using recursion 
class Solution {
  public:
   void bubSort(vector<int>& arr, int n){
       //base case
       if(n ==1)return;
       int didSwap =0;//no swap
       for(int i=0;i<n-1;i++){
           if(arr[i] > arr[i+1]){
               int temp = arr[i];
               arr[i]=arr[i+1];
               arr[i+1]=temp;
               didSwap =1;
           }
       }
       if(didSwap ==0)return ;//already sorted
       bubSort(arr,n-1);
   }
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
       return bubSort(arr,n);
    }
};