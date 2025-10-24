class KthLargest {
public:
  priority_queue<int, vector<int>, greater<int>>pq;
  int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(pq.size() > k){
            pq.pop();//if heap size exceeds k length the k th largest in top
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > size){
            pq.pop();//if heap size exceeds k length the k th largest in top
        }
        return pq.top();
    }
};