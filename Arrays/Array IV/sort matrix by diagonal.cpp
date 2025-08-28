//1st ask interviewr can I modify the input
class Solution {
public:
  int n;
  void sortDiagonal(int row, int col, vector<vector<int>>& grid, bool asc){
    int i= row, j = col;
    vector<int>vec;
    while(i<n && j<n){
        vec.push_back(grid[i][j]);
        i++;j++;//increse only one add
    }
if (asc== true) {
            sort(vec.begin(), vec.end());  // ascending
        } else {
            sort(vec.begin(), vec.end(), greater<int>()); // descending
        }
    i= row;j= col;
    for(int &val: vec){
        grid[i][j]= val;
        i++;j++;
    }
  }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n= grid.size();
        //for bottom left traingle- non increasing order which col start from 0
        for(int row =0;row<n;row++){
            sortDiagonal(row,0,grid, false);//0 for col and false bcz here need not aceending order
        }
        //for top right traingle- non decreasing order which row start from 0
        for(int col =1;col<n;col++){
            sortDiagonal(0,col,grid, true);//0 for row and true bcz here need aceending order
        }
        return grid;
    }
};

//using map

class Solution {
public:
  int n;
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n= grid.size();
         unordered_map<int, vector<int>>mp;
         //(i-j) -> diagonal elements
         for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                int diag= i-j;
                mp[diag].push_back(grid[i][j]);
            }
         }
         for(auto &it : mp){
            if(it.first >= 0){
                sort(begin(it.second), end(it.second));
            } else{
                sort(rbegin(it.second),rend(it.second));
            }
         }
        
        for(int i=0; i<n;i++){
            for(int j=0;j<n;j++){
                int diag= i-j;
                grid[i][j]= mp[diag].back();
                mp[diag].pop_back();
            }
         }

        return grid;
    }
};