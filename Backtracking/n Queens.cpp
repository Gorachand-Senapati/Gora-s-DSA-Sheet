class Solution {
public:
 bool isSafe(vector<string>& board, int row, int col, int n) { //O(n)
    //horizontal row same
    for(int j=0; j<n; j++){
        if(board[row][j] == 'Q'){
            return false;
        }
    }
    //vertical col same
     for(int i=0; i<n; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    //left diagonal
    for(int i=row , j= col; i>=0 && j>= 0; i--, j--) {
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    //right diagonal
    for(int i=row , j= col; i>=0 && j<=n; i--, j++) {
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;

 }

 void nQueens(vector<string>& board, int row, int n,vector<vector<string>> &ans ) {
    if(row == n) { //base case
        ans.push_back({board});
        return;
    }

    for(int j=0; j<n;j++) {
        if(isSafe(board, row, j,n)){
            board[row] [j] = 'Q';
            nQueens(board, row+1, n , ans);//next row next queen
            board[row] [j] = '.';//backtracking and convert position .(empty)
        }
    }
 }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n, '.')); //start a string all position is now empty which size equal queen
        vector<vector<string>> ans;
        nQueens(board,0, n, ans);
        return ans;
    }
};