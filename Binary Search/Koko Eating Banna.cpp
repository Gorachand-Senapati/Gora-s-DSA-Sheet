class Solution {
public:

    long long calculateH(vector<int>& piles, int hr) {
        long long totalH = 0;

        for(int i = 0; i < piles.size(); i++) {
            totalH += ((long long)piles[i] + hr - 1) / hr;
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1;

        for(int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }

        while(low <= high) {
            int mid = low + (high - low) / 2;

            long long totalh = calculateH(piles, mid);

            if(totalh > h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};