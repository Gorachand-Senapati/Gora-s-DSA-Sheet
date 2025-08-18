// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n = heights.size();
//         int largeRec = 0;

//         for (int i = 0; i < n; i++) {
//             int minHeight = heights[i];
//             for (int j = i; j < n; j++) {
//                 minHeight = min(minHeight, heights[j]);
//                 int width = j - i + 1;
//                 int area = width * minHeight;
//                 largeRec = max(largeRec, area);
//             }
//         }

//         return largeRec;
//     }
// };

//optimal approach
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n,0); //left smalller nearest
        vector<int>right(n,0); //right smaller nearest

        stack<int>s;
        //Right smaller
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

            right[i] = s.empty() ? n: s.top();//if empty then n bcz rigt boundari 6min size  else top value
            s.push(i);
        }
        //abar left use korar jonno stack khali korte hobe
        while(!s.empty()) {
            s.pop();
        }

        //left smaller
        for(int i=0;i<n;i++){
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }

           left[i] = s.empty() ? -1: s.top();//if empty then-1 else top value
            s.push(i);
        }

        int ans = 0;
        for (int i=0;i<n;i++){
            int width = right[i]-left[i]-1;// r[i] -l[i] You are counting one extra space,for 0 index because both walls are outside the rectangle.//So you remove 1:
            int currArea = heights[i] * width;
            ans = max(ans, currArea);
        }
        return ans;
    }
};

//more optimal
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        stack<int> s;
        int maxArea = 0;
        int n = arr.size();

        for (int i = 0; i <= n; i++) {
            // when i == n, treat height as 0
            int currHeight = (i == n ? 0 : arr[i]);
//here s.top() is previous small idx and i is the next small idx
            while (!s.empty() && arr[s.top()] > currHeight) {
                int height = arr[s.top()];
                s.pop();
                int width;
                if (s.empty()) {
                    width = i;  // whole range till i
                } else {
                    width = i - s.top() - 1;  // between smaller bars
                }

                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }
        return maxArea;
    }
};
