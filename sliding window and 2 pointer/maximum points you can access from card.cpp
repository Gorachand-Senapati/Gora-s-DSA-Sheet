class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n= cardPoints.size();
        int leftSum=0, rightSum=0, maxSum=0;
        for(int i=0;i<k;i++){
            leftSum+=cardPoints[i];
            maxSum=leftSum;
            }
            int rightIdx=n-1;
            for(int j=k-1;j>=0;j--){
                leftSum-=cardPoints[j];
                rightSum+= cardPoints[rightIdx];
                rightIdx= rightIdx-1;
                maxSum= max(maxSum,leftSum+ rightSum);
            }
        
        return maxSum;
    }
};