class Solution {
public:
    void nextPermutation(vector<int>& A) { //tc= O(n) SC=O(1)
        int pivot= -1, n= A.size();
        //pivot element find 1st step
        for( int i=n-2;i>=0;i--){
            if(A[i] < A[i+1]){
                pivot= i;
                break;
            }
            
        }
        if(pivot == -1){
            reverse(A.begin(), A.end());
            return;
        }

        //to find right most element 2nd step
        for( int i=n-1; i>pivot; i--){
            if(A[i]> A[pivot]){
              swap(A[i],A[pivot]);
            break;
            }
        }
        // Reverse decrement to increment(piv+1 to n-1)
       int  i=pivot+1, j=n-1; 
        while(i<=j){
            swap(A[i++], A[j--]);

        }
        
    }
};