class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int>mp;//store arr[val] and freq
        typedef pair<int, int>p;
        priority_queue<p, vector<p>, greater<p>>minHeap;//store pair in minheap
         
         for(int& num: arr){
             mp[num]++;//store freq in map
         }
        //push element in heap maintain k size only
       for(auto & it: mp) {
           int value = it.first;
           int freq = it.second;
           minHeap.push({freq,value});
           if(minHeap.size() > k) {
               minHeap.pop();
           }
       }
       //store in ans
       vector<int>ans;
       while(!minHeap.empty()){
           ans.push_back(minHeap.top().second);//push only value
           minHeap.pop();
       }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};

//using bucket O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n= nums.size();
        unordered_map<int, int>mp;//store value and freq
        for(int & num: nums){
            mp[num]++;
        }
        //make a buccket array 
        vector<vector<int>>bucket(n+1);//if maximum freq n bcz we use index as freq
        //index= freq, value= elements, bucket[i]= element having i freq
        for(auto& it: mp){
            int element =it.first;
            int freq= it.second;
            bucket[freq].push_back(element);//push element in the bucket in every index=freq
        }
        //pick element from right to left need max freq 
        vector<int>ans;
        for(int i=n;i>=0;i--){
            if(bucket[i].size() == 0) continue;//means if bucket empty check next bucket
            while(bucket[i].size() >0  && k >0){//if bucket has elements need only k elements
                ans.push_back(bucket[i].back());//O(1) for back element of bucket 
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};