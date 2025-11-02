class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        //here say how much dis 0
        int m = mat.size();//row size
        int n= mat[0].size();//col size
        //make a copy of mat because we not change the original for dist
        vector<vector<int>>dist=mat;//copy
        vector<vector<int>>vis(m, vector<int>(n,0));//making a visited array assign 0
        queue<pair<pair<int,int>, int>>q;//make a q for BFS traverse {{r,c}, step}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){
                    vis[i][j]= 1;
                    q.push({{i,j},0});//push row, col with 0 step because self 0 it is so no need check
                } 
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;//first pair first int
            int c = q.front().first.second;//first pair 2nd int
            int step = q.front().second;
            q.pop();
            dist[r][c]= step;//asign dist in the copy mat
            int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
            for(int i=0;i<4;i++){
              int nr = r + dr[i], nc = c + dc[i];//next row and next col assing
              if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc] == 0){//if valid and not visited
                vis[nr][nc] =1;
                q.push({{nr, nc}, step+1});
              }
            }
        }
        return dist;
    }
};