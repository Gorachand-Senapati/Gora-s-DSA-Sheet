class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int, pair<int, int>>>q;
        int n = grid.size();//row size
        int m= grid[0].size();//col size
       vector<vector<int>>dist(n,vector<int>(m,1e9));//make a dist matrix all value infinity
        dist[source.first][source.second]=0;//src to src dist 0
        if(source == destination){
            return 0;//if src and destinatoin same
        }
        q.push({0,{source.first,source.second}});
        int dr[4]= {-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc= c+dc[i];
                if(nr >=0 && nr<n && nc>=0 && nc<m &&
                grid[nr][nc] == 1 && dis+1 < dist[nr][nc]){
                    dist[nr][nc] = dis+1;//update min
                    if(nr == destination.first && nc== destination.second){
                        return dis+1;//this is ans;
                    }
                    q.push({dis+1,{nr,nc}});
                }
                
            }
        }
        return -1;
    }
};
//TC:O(n*m*4) SC:O(n*m) for dist matrix and O(n*m) for queue in worst case
//LC:shortest path in binary matrix
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>>q;
        int n = grid.size();//row size
        int m= grid[0].size();//col size
        pair<int,int>source = {0,0};
        pair<int,int>destination = {n-1,n-1};
        if(grid[0][0] ==1 ||grid[n-1][n-1]) return -1;
        if(source == destination) return 1;
       //create a matrix which assign dist 1e9
       vector<vector<int>>dist(n,vector<int>(m,INT_MAX));//Int_max= 1e9
       dist[source.first][source.second] = 1;//1cell 1 dist
       q.push({1,{source.first,source.second}});
        int dr[8]= {-1,-1,0,1,1,1,0,-1};
        int dc[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            auto it =q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<8;i++){
                int nr = r+dr[i];
                int nc= c+dc[i];
                if(nr >=0 && nr<n && nc>=0 && nc<m &&
                grid[nr][nc] == 0 && dis+1 < dist[nr][nc]){
                    dist[nr][nc] = dis+1;//update min
                    if(nr == destination.first && nc== destination.second){
                        return dis+1;//this is ans;
                    }
                    q.push({dis+1,{nr,nc}});
                }
                
            }
        }
        return -1;
    }
};