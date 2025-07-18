class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int m = mat.size(), n= mat[0].size();
        int strow = 0, stcol =0;
        int endrow = m-1, endcol = n-1;
        vector<int>ans;
        
        while(strow <= endrow && stcol <= endcol){
            // i = col && j = row
            //Top
           for(int i=stcol; i<=endcol; i++){
               ans.push_back(mat[strow][i]);
           }
            //right
           for(int j=strow+1; j<=endrow; j++){
               ans.push_back(mat[j][endcol]);
           }
            //bottom
           for(int i=endcol-1; i>=stcol; i--){
               if(strow == endrow){ 
                   break;
                   
               }
               ans.push_back(mat[endrow][i]);
           }
            //left
           for(int j=endrow-1; j>=strow+1; j--){
               if(stcol == endcol){
                   break;
                   
               }
               ans.push_back(mat[j][stcol]);
           }
            strow++;endrow--;
            stcol++;endcol--;
        }
        return ans;
    }
};