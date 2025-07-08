class Solution {
  public:
  bool isPossible(vector<int>& stalls, int k, int minDist){
      int cow = 1, lastStallpos = stalls[0];
      int n = stalls.size();

      for(int i = 1; i < n; i++) {
          if(stalls[i] - lastStallpos >= minDist) {
              cow++;
              lastStallpos = stalls[i];
          }
          if(cow == k) {
              return true;
          }
      }
      return false;
  }

  int aggressiveCows(vector<int> &stalls, int k) {
      sort(stalls.begin(), stalls.end());  // Only sort once

      int st = 1;
      int end = stalls.back() - stalls.front();  // Max distance
      int ans = 0;

      while(st <= end) {
          int mid = st + (end - st) / 2;
          if(isPossible(stalls, k, mid)) {
              ans = mid;
              st = mid + 1;  // Try for bigger distance
          } else {
              end = mid - 1;  // Try for smaller distance
          }
      }
      return ans;
  }
};
