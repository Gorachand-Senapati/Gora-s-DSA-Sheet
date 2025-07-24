class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        //base case 
        if(low>= high) return;
        int pivIdx= partition(arr,low,high);
        quickSort(arr,low,pivIdx-1);//left part
        quickSort(arr, pivIdx+1,high);//righ part
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int idx = low-1,pivot= arr[high];
        for(int j =low;j<high;j++){
            if(arr[j] <= pivot){
                idx++;
                swap(arr[j],arr[idx]);
            }
        }
        idx++;
            swap(arr[idx],arr[high]);//place pivot correct position
        return idx;
    }
};