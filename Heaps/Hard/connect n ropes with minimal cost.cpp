class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<long long , vector<long long>, greater<long long>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        long long totalCost=0;
        while(pq.size() > 1){
            long long cost =0;
            long long x= pq.top();
            pq.pop();
            long long y= pq.top();
            pq.pop();
            cost = x + y;
            pq.push(cost);
            totalCost+= cost;
        }
        return totalCost;
    }
};