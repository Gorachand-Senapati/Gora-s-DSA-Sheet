class Solution {
private:
 vector<int>topoSort(int V,vector<vector<int>>&adj){
     vector<int>inDeg(V,0);
     //give indeg
     for(int i=0;i<V;i++){
         for(auto& it:adj[i]){
             inDeg[it]++;
         }
     }
     queue<int>q;
     for(int i=0;i<V;i++){
         if(inDeg[i] == 0){
             q.push(i);
         }
     }
     vector<int>ans;
     while(!q.empty()){
         int node = q.front();
         q.pop();
         ans.push_back(node);
         for(auto&it: adj[node]){
             inDeg[it]--;
             if(inDeg[it] == 0) q.push(it);
         }
     }
     return ans;
     
 }
  public:
    string findOrder(vector<string> &words) {
        // code here
        int N = words.size();
        int V= INT_MIN;//V = maxLen of the words any string
        for(auto & s:words){
            V= max(V, (int) s.size());
        }
        //vector<int>adj[V];//make a adjlis //but it not legal because if it not constant in compile time 
        vector<vector<int>>adj(V);
        
        //check pair of 2 strings
        for(int i=0;i<N-1;i++){
            string s1= words[i];
            string s2 =words[i+1];
            //check for both array
            int minLen = min(s1.size(), s2.size());//go only which min len
            for(int ptr =0;ptr<minLen;ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr]- 'a'].push_back(s2[ptr]- 'a');//make directed graph using num from 0 to 25
                    break;
                }
            }
        }
        //perform topological sort for the graph
        vector<int>topo = topoSort(V,adj);
        //convert numeric value in char
        string ans ="";
        for(auto node: topo){
            ans+= char(node+'a');
        }
        return ans;
    }
};



//for GFG check the same pattern but slightly different on some places
class Solution {
  public:
  
    vector<int> topoSort(int V, unordered_map<int, vector<int>> adj)
    {
        // Compute indegree (number of incoming edges) for each node
        vector<int> indegree(V, 0) ;
        for(int i=0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                indegree[it]++ ;
            }
        }
        
        // Push all nodes with indegree = 0 into the queue
        queue<int> q ;
        for(int i=0; i<V; i++)
        {
            if(indegree[i] == 0) q.push(i) ;
        }
        
        vector<int> topo ;
        while(!q.empty())
        {
            int node = q.front() ;
            q.pop() ;
            
            topo.push_back(node) ;
            
            // Decrease indegree of all connected nodes
            for(auto it : adj[node])
            {
                indegree[it]-- ;
                if(indegree[it] == 0) q.push(it) ;
            }
        }
        
        return topo ;
    }
  
    string findOrder(vector<string> &words) {
        int n = words.size() ;
        unordered_map<int, vector<int>> adj ;
        vector<bool> present(26, false);

        // Track which characters appear
        for (auto& word : words) {
            for (auto c : word)
                present[c - 'a'] = true;
        }
        
        // Build the graph using adjacent word pairs
        for(int i=0; i<n-1; i++)
        {
            string s1 = words[i] ;
            string s2 = words[i+1] ;
            
            int len = min(s1.length(), s2.length()) ;
            int ptr = 0 ;
            
            // Find the first mismatched character
            while (ptr < len && s1[ptr] == s2[ptr]) ptr++ ;

            if (ptr < len) 
            {
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a') ;
            } 
            else if (s1.length() > s2.length()) 
            {
                // invalid lexicographical order like "abc" before "ab"
                return "" ;
            }
        }
        
        vector<int> topo = topoSort(26, adj) ;
        string ans = "" ;
        
        // Validate result — check for cycles or disconnected parts
        int presentCount = count(present.begin(), present.end(), true) ;
        int presentInTopo = 0 ;
        for (auto node : topo)
        {
            if (present[node]) presentInTopo++ ;
        }
        if (presentInTopo != presentCount) return "" ;
        
        // even letters like 'x', 'y', 'z' (which never appeared)
        // will have indegree[i] == 0, and thus get pushed into the queue.
        // So, topo will contain all 26 nodes (a–z) even though only {a,b,c,d} were used.
        // Hence, we must check if (present[it]) to filter out irrelevant letters
        for(auto it : topo)
        {
            if(present[it])
            {
                ans.push_back(char(it + 'a')) ;
            }
        }
        
        return ans ;
    }
};