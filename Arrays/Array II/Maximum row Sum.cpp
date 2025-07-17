int getMaxSum(int matrix[][total cols size], int rows, int cols) {
    int maxrowSum = INT_MIN;
    for(int i=0;i<rows;i++){
        int rowSum = 0;
        for(int j=0;j<cols;j++){
            rowSum += matrix[i][j];
        }
        maxrowSum =max(rowSum, maxrowSum);
    }
    return maxrowSum;
}