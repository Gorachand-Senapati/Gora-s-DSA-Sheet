class Solution {
private: 
  void dfs(int row, int col,vector<vector<char>>& board,vector<vector<int>>&vis,
  int m, int n, int dr[], int dc[]){
    vis[row][col] = 1;
    for(int i=0;i<4;i++){
        int nr = row + dr[i];//next row assign
        int nc = col + dc[i];//next col assign
        if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == 'O'){
            dfs(nr, nc, board, vis,m,n,dr, dc);
        }
    }
  }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();//row size
        int n = board[0].size();//col size
        vector<vector<int>>vis(m, vector<int>(n,0));//make a vis array assing 0
          int dr[4] = {-1,0,1,0};//dirction row
            int dc[4] = {0,1,0,-1};//dirction col
        //now traverse all boundary char i- row , j- col
        for(int j=0;j<n;j++){//search for 1st and last row all coll
            if(board[0][j] == 'O'){//1st row 
                dfs(0,j,board, vis, m,n, dr, dc);
            }
            if(board[m-1][j] == 'O'){//last row 
                dfs(m-1,j,board, vis, m,n, dr, dc);
            }
        }
        for(int i=0;i<m;i++){//search for 1st and last col and its all rows
            if(board[i][0] == 'O'){//1st col
                dfs(i,0,board, vis, m,n, dr, dc);
            }
            if(board[i][n-1] == 'O'){//last col
                dfs(i,n-1,board, vis, m,n, dr, dc);
            }
        }
        //NOw traverse all board and check if it 0 and not visited make it 'X'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';//make x
                }
            }
        }
    }
};