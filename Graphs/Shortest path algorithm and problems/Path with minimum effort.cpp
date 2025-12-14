class Solution {
public://E log v == n* m * 4 log (n*m )
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size(), m= heights[0].size();//row & col size
        //make a pq stor{diff, {row, col}}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));//make a dist mat with value int max
        dist[0][0]= 0;//src
        pq.push({0, {0,0}});//src diff 0
        int dr[4] = {-1,0,1,0};//top righ bot left
        int dc[4]= {0,1,0,-1};//"
        while(!pq.empty()){
            auto it = pq.top();//pq. top
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c== m-1) return diff;
            
            for(int i=0;i<4;i++){
                int nr = r+dr[i], nc = c+ dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int effort = max(abs(heights[r][c] - heights[nr][nc]), diff);
                    if(effort < dist[nr][nc]){
                        dist[nr][nc]= effort;
                        pq.push({effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;// If unreachable (although it should not reach here)
    }
};