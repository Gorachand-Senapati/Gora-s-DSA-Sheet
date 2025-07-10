class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int idx=m+n-1, i=m-1, j=n-1;
        while(i>=0 && j>=0){
            if(A[i]> B[j]){
                A[idx] = A[i];
                idx--, i--;
            } else {
                A[idx] = B[j];
                idx--, j--;
            }
        }
        while(j>=0){
            A[idx] = B[j];
            idx--, j--;
        }
        
    }
};

// int left = n - 1;
//     int right = 0;
//     //Swap the elements until arr1[left] is
//     // smaller than arr2[right]:
//     while (left >= 0 && right < m) {
//         if (arr1[left] > arr2[right]) {
//             swap(arr1[left], arr2[right]);
//             left--, right++;
//         }
//         else {
//             break;
//         }
//     }
//     // Sort arr1[] and arr2[] individually:
//     sort(arr1, arr1 + n);
//     sort(arr2, arr2 + m);