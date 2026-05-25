class Twitter {
    // person to their followers:
    unordered_map<int, unordered_set<int>> match;
    // person to their posts:
    unordered_map<int, vector<vector<int>>> posts;
    int count;
public:
    Twitter() {
        count = 0; // we need a way to keep track of most recent
    }
    
    void postTweet(int userId, int tweetId) {
        int num_posts = (int)posts[userId].size() - 1; // for index
        // the order: time : id : tweet_id : next_earlier_post
        vector<int> info = {count, userId, tweetId, num_posts};
        posts[userId].push_back(info);
        ++count;
    }
    
    vector<int> getNewsFeed(int userId) {
        // we will grab the most recent post from us, and followers 
        // and put it in a priority queue
        priority_queue<vector<int>> pq; // max_heap
        // we can just add ourselves into it and so we don't have to deal
        // about that extra case
        match[userId].insert(userId);
        for (const auto& peop : match[userId]) {
            // if that person has a most recent post let's put it in
            if (posts[peop].size() > 0) {
                // we want to add the top one in
                pq.push(posts[peop].back());
            }
        }
        vector<int> result;
        while (result.size() < 10 && !pq.empty()) {
            // we will get the one at the very top of the priority queue
            vector<int> at_top = pq.top();
            pq.pop();
            // tweet id is at the second index:
            result.push_back(at_top[2]);
            // then we need to add the next if there is one:
            int u_id = at_top[1];
            int next = at_top[3];
            if (next != -1) {
                pq.push(posts[u_id][next]);
            }
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        match[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        match[followerId].erase(followeeId);
    }
};
