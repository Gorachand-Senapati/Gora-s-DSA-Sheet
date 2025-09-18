class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
        // Step 1: store {end, start} pairs
        vector<pair<int,int>> meetings;
        for(int i = 0; i < n; i++){
            meetings.push_back({end[i], start[i]});
        }
        
        // Step 2: sort by ending time
        sort(meetings.begin(), meetings.end());
        
        // Step 3: greedy selection
        int cnt = 0;
        int endTime = -1;
        for(int i = 0; i < n; i++){
            if(meetings[i].second > endTime){ // start > last end
                cnt++;
                endTime = meetings[i].first;
            }
        }
        return cnt;
    }
};// Time Complexity: O(N log N) due to sorting . Space Complexity: O(N) for storing the meetings

//if need position of meeting then store index also in pair {end, {start, index}} and return index array
class Solution {
  public:
    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
        // Step 1: store {end, start, index}
        vector<tuple<int,int,int>> meetings;
        for(int i = 0; i < n; i++){
            meetings.push_back({end[i], start[i], i+1}); // index is 1-based
        }
        // Step 2: sort by end time
        sort(meetings.begin(), meetings.end());
        // Step 3: greedy selection
        vector<int> result;
        int endTime = -1;
        
        for(int i = 0; i < n; i++){
            int e = get<0>(meetings[i]);
            int s = get<1>(meetings[i]);
            int idx = get<2>(meetings[i]);
            
            if(s > endTime){
                result.push_back(idx);
                endTime = e;
            }
        }
        // Optional: sort result by meeting index if problem demands
        sort(result.begin(), result.end());
        return result;
    }
};
// Time Complexity: O(N log N) due to sorting . Space Complexity: O(N) for storing the meetings and result