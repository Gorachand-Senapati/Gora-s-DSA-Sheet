class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       int rows = strs.size();//row size
       int cols = strs[0].size();//col size
       int ans =0;
       for(int col =0;col<cols;col++){
        for(int row=0;row<rows-1;row++){
            if(strs[row][col] > strs[row+1][col]){
                ans++;
                break;
            }
        }
       }
       return ans;
    }
};