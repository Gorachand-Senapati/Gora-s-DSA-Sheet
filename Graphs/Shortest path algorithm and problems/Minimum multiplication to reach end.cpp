// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        queue<pair<int,int>>q;
        q.push({start,0});//start position 0
        vector<int>dist(100000,1e9); //0 to 99999 nodes total
        dist[start]=0;
        while(!q.empty()){
            int steps = q.front().second;
            int node = q.front().first;
            q.pop();
            int mod = 100000;
            for(auto it: arr){
                int num = (it * node)% mod;
                if(steps+1 < dist[num]){
                    dist[num]=steps+1;
                    if(num == end) return steps+1;
                    q.push({num ,steps+1});
                }
            }
        }
        return -1;
    }
};