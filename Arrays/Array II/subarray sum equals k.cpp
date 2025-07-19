class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
       int count =0;
        vector<int>ps(n,0);//prefixSum which size n and initialize with 0
        ps[0] = arr[0];

        for(int i=1;i<n;i++){
            ps[i] = ps[i-1] +arr[i];
        }
        unordered_map<int, int>m; //ps and frequency

        for(int j=0;j<n;j++){
            if(ps[j] == k) count++;
            int val = ps[j] - k;
            if(m.find(val) != m.end()) { //ache
                count += m[val]; //count the frequency how many time this 
            }
            if(m.find(ps[j]) == m.end()) { //if does not store the prefix sum 
                m[ps[j]] = 0; 
            }
           m[ps[j]]++ ; // 0 thakle 1 , 1 thakle 2
        }
        return count;
    }
};