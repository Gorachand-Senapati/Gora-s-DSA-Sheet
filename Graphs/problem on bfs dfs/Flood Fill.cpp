class Solution {
private: 
   void dfs(vector<vector<int>>& image,vector<vector<int>>&ans ,int row, int col,
   int dr[], int dc[],int color, int iniColor){
    ans[row][col]= color;
    int m= image.size(), n= image[0].size();//row , col size
    for(int i=0;i<4;i++){
        int nr = row + dr[i], nc = col + dc[i];
          //check next row  and col is in boundary and same as initial color and not privious colored
        if(nr>=0 && nc>=0 && nr<m && nc<n && image[nr][nc]== iniColor && ans[nr][nc] != color){
            dfs(image,ans , nr, nc, dr, dc, color, iniColor);
        }
    }
   }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;//copy of image I dont change in main matrix
        int iniColor = image[sr][sc];
        //make array for top right bottom left
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        dfs(image, ans, sr, sc, dr,dc,color,iniColor);
        return ans;
    }
};