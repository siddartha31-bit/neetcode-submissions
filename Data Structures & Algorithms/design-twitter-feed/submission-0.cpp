class Twitter {
public:
    int timer;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;

        following[userId].insert(userId);

        for (int user : following[userId]) {
            auto &t = tweets[user];
            if (!t.empty()) {
                int idx = t.size() - 1;
                pq.push({t[idx].first, t[idx].second, user, idx});
            }
        }

        vector<int> res;

        while (!pq.empty() && res.size() < 10) {
            auto cur = pq.top();
            pq.pop();

            int tweetId = cur[1];
            int user = cur[2];
            int idx = cur[3];

            res.push_back(tweetId);

            if (idx > 0) {
                idx--;
                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId) {
            following[followerId].erase(followeeId);
        }
    }
};