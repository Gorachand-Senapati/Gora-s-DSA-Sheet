class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>ans(numRows);
        bool flag= false;
        int i=0;
        for(auto ch:s){
            ans[i]+=ch;
            if(i==0 || i== numRows-1){
                flag=!flag;
            }
            if(flag){//true
            i+=1;
            } else{
                i-=1;
            }
        }
        string zigzag="";
        for(auto str:ans){
            zigzag +=str;
        }
        return zigzag;
    }
};
// using matrix 


class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows <= 1 || s.size() <= numRows) {
            return s;
        }

     
        vector<vector<char>> matrix(numRows, vector<char>(s.size(), ' '));
        
        int row = 0, col = 0;
        bool goingDown = true;
        
        for (char c : s) {
            matrix[row][col] = c;
            
            if (goingDown) {
                
                if (row == numRows - 1) {
                    // Reached the bottom, change direction and move diagonal up
                    goingDown = false;
                    row--;
                    col++;
                } else {
                    row++;
                }
            } else {
                // If moving diagonally up
                if (row == 0) {
                    // Reached the top, change direction and move down 
                    goingDown = true;
                    row++;
                } else {
                    row--;
                    col++;
                }
            }
        }
        
        
        string result = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (matrix[i][j] != ' ') {
                    result += matrix[i][j];
                }
            }
        }
        
        return result;
    }
};