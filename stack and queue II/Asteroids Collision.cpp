class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;//create a list;
        int n= asteroids.size();
        for(int i=0; i<n;i++){
            if(asteroids[i]> 0){
                st.push_back(asteroids[i]);
            } else{
                while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])){ //if small top
                    st.pop_back();
                }
                if(!st.empty() && st.back()== abs(asteroids[i])){//if both are same
                    st.pop_back();
                } else if(st.empty() || st.back()<0){ //also if starting value negative also push negative or positive value
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};