//maxheap

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0;i<=n/2-1;i++){
            int left = 2 *i+1;
            if(arr[left] > arr[i]) return false;
            int right = 2*i+2;
            if(arr[right] > arr[i]) return false;
        }
        return true;
    }
};

//minheap
class Solution {
  public:
    bool isMinHeap(int arr[], int n) {
        for(int i=0;i<=n/2-1;i++){
            int left = 2 *i+1;
            if(arr[left] < arr[i]) return false;
            int right = 2*i+2;
            if(arr[right] < arr[i]) return false;
        }
        return true;
    }
};