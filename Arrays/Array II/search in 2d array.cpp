class Solution {
public:
bool searchtar(vector<vector<int>> & mat, int target, int row){
    int n = mat[0].size();
    int st =0, end = n-1;

    while(st <= end) {
        int mid = st + (end -st) /2;
        if (target == mat[row][mid]){
            return true;
        } else if(target >mat[row][mid]){
            st = mid +1;
        } else {
            end = mid -1;
        }
    }
    return false;
    
}
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        //mat = matrix;
        //bs in total rows
        int m= mat.size() , n= mat[0].size();
        int strow = 0, endrow = m -1;
        while(strow<=endrow) {
            int midrow = strow + (endrow-strow)/2;

            //midrow the target value exist
            if(mat[midrow][0] <= target && target <= mat[midrow][n-1]){
               return  searchtar(mat,target,midrow);

            } else if(target<=mat[midrow][0]){
                endrow = midrow -1;
            } else{
                strow = midrow +1;
            }
        }
        
        return false;
    }
};