class Solution {
  public:
    int findOnce(vector<int>& arr) {
        // code here.
        int n = arr.size();
        if(n == 1) return arr[0];
        
        int st = 0, end = n-1;
        while(st<= end){
            int mid = st + (end- st)/2;
            if(mid == 0 && arr[0] != arr[1]) return arr[mid];
            if(mid == n-1 && arr[n-1] != arr[n-2]) return arr[mid];
            if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid]) return arr[mid];
            
            if(mid % 2 != 0){//odd number in mid 2 side left and right 
                if(arr[mid-1] == arr[mid]) {
                    st = mid+1;
                }else{
                    end = mid-1;
                }
                
            } else {//even number both side in array
                if(arr[mid-1] == arr[mid]) {
                    end = mid-1;
                }else{
                    st = mid+1;
                }
            }
        }
        
        return -1;
    }
};

//Striver Approach

class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n= A.size();

        if(n==1) return A[0];

        int st=0, end= n-1;
        while(st<=end) { 
            int mid = st+ (end-st)/2;

            if(mid == 0 && A[0] != A[1]) return A[mid];
            if(mid == n-1 && A[n-1] != A[n-2]) return A[mid];

            if(A[mid-1] !=A[mid] && A[mid] != A[mid+1]) return A[mid];

            if((mid %2 == 0 && A[mid] == A[mid+1]) ||(mid % 2 == 1 && A[mid] ==A[mid-1]) ){
                st= mid+1;
            } else{
                end =mid-1;
            }
        };
        return -1;
        
    }
};