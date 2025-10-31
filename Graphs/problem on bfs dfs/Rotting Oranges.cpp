class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size()== 0) return 0;//if empty return 0
        //m= rowSize, n= colSize,time= mintime req ans, tot= rotten+fresh , cnt= which rotten by us
        int m=grid.size(),n=grid[0].size(), time=0, tot=0, cnt=0;
        queue<pair<int,int>>rotten;//make q where store row, col pair which is rotten means 2
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] !=0) tot++;
                if(grid[i][j] == 2) rotten.push({i,j});//if rootten push in queue
            }
        }
        //for 4 side direction need Drow, Dcol when add its idx it go top right bottom left
        int dr[4]= {-1,0,1,0};
        int dc[4]= {0,1,0,-1};
        while(!rotten.empty()){//untill queue empty
            int k= rotten.size();
            cnt+=k;//cnt total rotten orrange
            while(k--){//until k=0
                int r= rotten.front().first, c= rotten.front().second;//row,and col 
                rotten.pop();
                for(int i=0;i<4;i++){
                    int nr= r + dr[i], nc= c + dc[i];//next row and col assign
                    //check next row  and col is in boundary and is not fresh or empty
                    if(nr<0 || nc<0 || nr>=m || nc>=n || grid[nr][nc] != 1) continue;
                    grid[nr][nc] =2;
                    rotten.push({nr,nc});
                }
            }
            if(!rotten.empty()) time++;
        }
        return tot == cnt ? time: -1;//if tot == cnt return time else return -1
    }
};