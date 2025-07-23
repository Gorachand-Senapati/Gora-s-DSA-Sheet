class Solution {
public: 
   bool isSafe(vector<vector<char>>& board, int row, int col, char dig){
    //horizontal check
    for(int j=0;j<9;j++){
        if(board[row][j] == dig){
            return false;
        }
    }
    //verticle  check
    for(int i=0;i<9;i++){
        if(board[i][col] == dig){
            return false;
        }
    }
    //grid check so 1grid start from stgrid ,stcol to strow+2 and stcol+2 means 3 row col
    int strow = row/3 * 3;
    int stcol = col/3*3;
    for(int i=strow;i< strow+3;i++){
        for(int j= stcol;j<stcol+3;j++){
            if(board[i][j] == dig){
                return false;
            }
        }
    }
    return true;
   }

    bool helper(vector<vector<char>>& board, int row, int col){
        //base case
        if(row == 9) return true;
        int nextrow = row, nextcol = col+1;//bcz after 0,0 fill wego next 0,1 position ...
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        //if see that fill
        if(board[row][col] != '.'){
            return helper(board, nextrow,nextcol);
        }
        //if not fill then give correct position each number
        for(char dig ='1'; dig<= '9'; dig++){
            if(isSafe(board,row, col,dig)){
                board[row][col] = dig;
                if(helper(board,nextrow, nextcol)){//if 2nd position give true then return true
                    return true;
                }
                // if not possible then backtrack and conver empty .
                board[row][col] = '.';
            }

        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0,0); //(0,0)start 
    }
};