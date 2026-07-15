class Twitter {
public:
//see again
    class Tweet {
    public:
        int id;
        int time;
        Tweet* next;

        Tweet(int id, int time) {
            this->id = id;
            this->time = time;
            next = nullptr;
        }
    };

    int timer = 0;

    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, Tweet*> tweetMap;

    Twitter() {}

    void postTweet(int userId, int tweetId) {

        Tweet* tweet = new Tweet(tweetId, timer++);
        tweet->next = tweetMap[userId];
        tweetMap[userId] = tweet;
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<
            pair<int, Tweet*>
        > pq;

        followMap[userId].insert(userId);

        for (int user : followMap[userId]) {

            if (tweetMap[user])
                pq.push({tweetMap[user]->time, tweetMap[user]});
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {

            Tweet* tweet = pq.top().second;
            pq.pop();

            feed.push_back(tweet->id);

            if (tweet->next)
                pq.push({tweet->next->time, tweet->next});
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        if (followeeId != followerId)
            followMap[followerId].erase(followeeId);
    }
};