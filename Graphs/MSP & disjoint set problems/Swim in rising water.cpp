class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;//store (elivitor, row, col) vector
        vector<vector<int>>vis(n,vector<int>(n,0));//a vis matrix
        pq.push({grid[0][0], 0, 0});//src push
        vis[0][0]=1;
        //for traverse 4 directions make a pair of these 4
        vector<pair<int, int>>dirs = {{-1,0}, {0,1},{1,0},{0,-1}};//top right bottm left

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int elivation = it[0], r = it[1], c = it[2];//hight, row, col
            if(r == n-1 && c == n-1) return elivation;//if destination achive
            //check 4 direction
            for(auto dir: dirs){
                int nr = r + dir.first;
                int nc = c + dir.second;//next row, next col
                if(nr >= 0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    pq.push({max(elivation, grid[nr][nc]), nr, nc});//need max time for wait hight
                }
            }
        }
        return -1;
    }
};