class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]
    int n = matrix.size(), m = matrix[0].size();
    int col = 1;
    //traverse the matrix and mark 
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                //mark ith row
                matrix[i][0] = 0;
                //mark j th col except the 1st col
                if(j != 0){
                    matrix[0][j] =0;
                }
                else{
                    col = 0;
                }
            }
        }
    }

    //change the mark row and col = 0 from (1,1) to (n-1,m-1)
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            //I ovserve that mark or not 
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    //step 3: Finally mark the 1st col & then 1st row: this strp work as it is not change formation
   if(matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }

    if(col == 0){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
    

    }
};