
class Solution {
  public:
    int DiagonalSum(vector<vector<int> >& matrix) {
        // Code here
    int sum = 0;
    for( int i=0;i<matrix.size(); i++){
        sum += matrix[i][i];
        sum += matrix[i][matrix.size()-i-1];
        //If want that common print 1 time and sum it 
        // if(i!= matrix.size() - i- 1){
        //     sum += matrix[i][matrix.size()-i-1];
            
        // }
    }
    return sum;
    }
};