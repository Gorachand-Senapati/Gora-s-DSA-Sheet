//using heap to find kth largest element in an array
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);//automatic push in sorted order
        }
        int f= k-1;
        while(f>0){
            pq.pop();
            f--;
        };
        return pq.top();
    }
};
//using minheap to find kth largest element in an array
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);//automatic inset in sorted order
        }
        int f= k-1;
        while(f>0){
            pq.pop();
            f--;
        }
        return pq.top();
    }
};//TC= O(nlogn) SC=O(n)