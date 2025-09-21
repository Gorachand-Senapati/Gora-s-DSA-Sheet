class Solution { // TC= O(3n) SC= O(2n)
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size(); int ans=0;
        vector<int>l(n,1);//left array intitalise at least one candy
        vector<int>r(n,1);// right array intitalise at least one candy
        //assign left array
        for(int i=1;i<n;i++){
            if(ratings[i-1]< ratings[i]){
                l[i]=l[i-1]+1;
            }
        }
        //ASSIGN right array
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]< ratings[i]){
                r[i]=r[i+1]+1;
            }
        }
        //find ans
        for(int i=0;i<n;i++){
             ans+= max(l[i],r[i]);
        }
        return ans;
    }
};

//O(2n) SC= O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> l(n, 1);
        
        // Left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                l[i] = l[i - 1] + 1;
            }
        }

        // Right to left (optimized)
        int curr = 1;
        int maxSum = max(l[n - 1], curr);
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                curr++;
            } else {
                curr = 1;
            }
            maxSum += max(l[i], curr);
        }

        return maxSum;
    }
};

//O(n) SC= O(1)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n, i=1;
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1]){
                peak++;
                candy += peak;
                i++;
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                valley++;
                candy += valley;
                i++;
            }
            candy -= min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};