class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ansRow;
        long long ans = 1;
         ansRow.push_back(1); //0st start with 1
        for(int col =1; col<=rowIndex;col++){
            ans = ans*(rowIndex-col+1);//0 index 1 element 1 idx 2 ele so col+1 
            ans= ans /col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};