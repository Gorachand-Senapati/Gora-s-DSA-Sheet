class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      vector<int>sortArr = arr;//copy the original arr value for sort
      sort(sortArr.begin(), sortArr.end());
      unordered_map<int, int>rank;//store num with rank value->rank
      int r=1;//rank start from 1
      for(int num:sortArr){//assign rank for unique value
        if(rank.find(num) == rank.end()){//if not find
            rank[num]=r++;//rank increase
        }
      }
      vector<int>ans;
      for(int num:arr){
        ans.push_back(rank[num]);//push the rank of the number
      }
      return ans;
    }
};

//BFA
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int rank = 1; // rank starts from 1
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) {
                    rank++;
                }
            }
            ans[i] = rank;
        }

        return ans;
    }
};