class Solution {
  public:
  void helper(vector<vector<int>>& maze, int row, int col ,string path, vector<string>&ans){
      int n = maze.size();
      //Base case 1- check boundaris and then check if 0 then dont go
      if(row<0 || col <0 || row>= n || col >= n || maze[row][col] == 0 || maze[row][col] == -1) return;
      //here -1 means visited and 1 means not visited  we convert visited to non visited . so if I find visitd then
      //I dont go there because so for multiple choice all time it create infinte loop
      //ans found
      if(row== n-1 && col == n-1){
          ans.push_back(path);
          return;
      }
      
      maze[row][col] = -1;//visited
      
      helper(maze, row+1,col,path+"D",ans);//D
      helper(maze, row-1,col,path+"U",ans);//U
      helper(maze, row,col +1,path+"R",ans);//R
      helper(maze, row,col-1,path+"L",ans);//L
      // after get 1 path we search another path so if there -1 so dont go there base case so we need back tracking so change it 1
      maze[row][col] = 1;//unvisited
  }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
         if (maze[0][0] == 0) return ans; // starting point blocked
        string path= "";
        helper(maze, 0,0, path, ans);
        sort(ans.begin(), ans.end());// Sort the paths in lexicographical order
        return ans;
    }
};