class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        if(n1>n2)  return findMedianSortedArrays(b,a);
        int n = n1+ n2;
        int left = (n1+n2+1)/2;
        int low = 0, high = n1;

        while(low <= high){
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(n1> mid1) r1= a[mid1];
            if(n2> mid2) r2= b[mid2];

            if(mid1 -1 >= 0) l1 = a[mid1 -1];
            if(mid2-1 >= 0) l2 = b[mid2-1];

            if(l1<= r2 && l2 <= r1){

            if(n %2 == 1) return max(l1,l2);
            return  double (max(l1,l2) + min(r1,r2)) /2.0 ;
            }
            else if(l1> r2) high = mid1-1;
            else low = mid1 +1;
        }

        return 0.0;//Damy 
    }
};