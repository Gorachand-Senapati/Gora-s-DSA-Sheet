class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;//userId, {timestamp, tweetid}
    unordered_map<int, unordered_set<int>>following;//stores the set of followees for each user{userid, floweeId}
    int time=0;//global time counter to sort tweets
public:
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {//function post for a tweet
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {//to get 10 most recent tweets in new feed
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>>pq;//min heap timestamp, tweetId, and heap store it in a vector
        //insert user own tweets
        for(auto& t: tweets[userId]){
            pq.push(t);
            if(pq.size() > 10){//if more than 10 pop it
                pq.pop();
            }
        }
        //insert tweeets from users being followed 
        for (int followee : following[userId]){
            for(auto& t: tweets[followee]){
                pq.push(t);
                if(pq.size() >10){
                    pq.pop();
                }
            }
        }
             // Extract tweets from heap in reverse order
             vector<int>res;
             while(!pq.empty()){
                res.push_back(pq.top().second);//tweet id
                pq.pop();
             }
             reverse(res.begin(), res.end());
             return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};