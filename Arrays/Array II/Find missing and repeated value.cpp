class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int>s; vector<int>ans;
        int a; //repeating
        int b; //missing
        int actualsum = 0, expectedsum =0;

        for(int i=0;i<n;i++){ //row
            for(int j=0;j<n;j++) { //col
            actualsum+= grid[i][j];
            if(s.find(grid[i][j]) != s.end()){
                a = grid[i][j];
                ans.push_back(a);
            }
            s.insert(grid[i][j]);
            }
            
        }
        //original sum = {n * (n +1)}/2
         expectedsum = (n *n)  * (n *n+1) /2;
        b = expectedsum +a - actualsum;
        ans.push_back(b);
        return ans;
    }
};