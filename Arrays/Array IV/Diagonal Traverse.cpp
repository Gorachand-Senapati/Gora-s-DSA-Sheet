class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size()== 0 || mat[0].size() == 0) return {};
        int m= mat.size(), n= mat[0].size();//assign row and col size
        vector<int>ans(m*n);
        int row=0 , col=0;
        for(int i=0;i<m*n;i++){
            ans[i]=mat[row][col];
            //if row+col even  r-- c++ and if odd r++ c--
            if((row+col) %2 ==0){
                if(col==n-1)row++;
                else if(row==0) col++;
                else {row--; col++;}
            } else {
                if(row == m-1)col++;
                else if(col==0)row++;
                else{row++; col--;}
            }
        }
        return ans;
    }
};