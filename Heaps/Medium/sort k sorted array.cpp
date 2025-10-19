class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>>minHeap;//create a min heap
        int n = arr.size();
        int idx=0;//for change in the main array
        // push in minheap 1st k+1 elements
        for(int i=0; i<=k && i<n ;i++){
            minHeap.push(arr[i]);
        }
        //for reamining element push in minheap and sorted push in ans
        for(int i= k+1;i<n;i++){
            arr[idx++]= minHeap.top();//sorted push from front
            minHeap.pop();//also clear top
            minHeap.push(arr[i]);//reaming element push in array
        }
        while(!minHeap.empty()){
             arr[idx++]= minHeap.top();
            minHeap.pop();
        }

    }
};

//check k sorted or not means check atmost k place distance from current sort position
class Solution {
  public:
    string isKSortedArray(int arr[], int n, int k) {
        // code here.
        vector<pair<int, int>>ans;//pair val, index
        for(int i=0;i<n;i++){
            ans.push_back({arr[i],i});
        }
        sort(ans.begin(), ans.end());
        for(int i=0;i<n;i++){
            if(abs(i-ans[i].second) > k) return "No";
        }
        return "Yes";
    }
};
