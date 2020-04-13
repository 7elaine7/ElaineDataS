/*
355. 设计推特
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：
postTweet(userId, tweetId): 创建一条新的推文
getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
follow(followerId, followeeId): 关注一个用户
unfollow(followerId, followeeId): 取消关注一个用户
示例:
Twitter twitter = new Twitter();
// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);
// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);
// 用户1关注了用户2.
twitter.follow(1, 2);
// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);
// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);
// 用户1取消关注了用户2.
twitter.unfollow(1, 2);
// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);
*/
typedef struct follower{
    int fId;
    struct follower* next;
}Follower;
typedef struct user{
    int usrId;
    Follower *follow;
    struct user* next;
}User;
typedef struct tweet{
    int usrId;
    int twId;
    struct tweet* next;
}Tweet;
typedef struct twitter{
    User *user_list;
    Tweet *tweet_list;
} Twitter;

/** Initialize your data structure here. */

Twitter* twitterCreate() {
    Twitter *new = (Twitter*)malloc(sizeof(Twitter));
    new->user_list = NULL;
    new->tweet_list = NULL;
    return new;
}
User* find_user(Twitter*obj, int userId)
{
    User* p =  obj->user_list;
    while(p)
    {
        if(p->usrId == userId)
            return p;
        else
            p = p->next;
    }
    return NULL;
}
void addUser(Twitter* obj, int userId)
{
    User *user = (User*)malloc(sizeof(User));
    user->usrId = userId;
    user->next = obj->user_list;
    user->follow = NULL;
    obj->user_list = user;  //user链表头插
    //关注自己
    Follower *follow = (Follower*)malloc(sizeof(Follower));
    follow->fId = userId;
    follow->next = NULL;
    user->follow = follow;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    User* user = find_user(obj, userId);
    if(NULL == user)
    {
        addUser(obj, userId);
    }
    
    Tweet* tweet = (Tweet*)malloc(sizeof(Tweet));
    tweet->usrId = userId;
    tweet->twId = tweetId;
    tweet->next = obj->tweet_list;
    obj->tweet_list = tweet;    //tweet链表头插
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
bool isFollower(User* user, int followId)
{
    Follower *f = user->follow;
    while(f)
    {
        if(f->fId == followId)
        {
            return true;
        }
        f = f->next;
    }
    return false;
}
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    int* array = (int*)malloc(sizeof(int) * 10);
    int count = 0;
    User* user = find_user(obj, userId);
    //没有此用户，或者此用户无关注者
    if(NULL == user || NULL == user->follow)
    {
        *retSize = count;
        return array;
    }
    Tweet* p = obj->tweet_list;
    while(count < 10 && p)
    {
        if(isFollower(user, p->usrId))
        {
            array[count] = p->twId;
            count++;
        }
        p = p->next;
    }
    *retSize = count;
    return array;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
        User* user = find_user(obj, followerId);
        if(NULL == user)
        {
            addUser(obj, followerId);
            user = obj->user_list;
        }
        Follower *p = user->follow;
        while(p)
        {
            printf("pfid = %d\n", p->fId);
            if(followeeId == (p->fId))
                return;
            else
                p = p->next;
        }
        //follower list里面没有，添加新的，头插
        Follower *follow = (Follower*)malloc(sizeof(Follower));
        follow->fId = followeeId;
        follow->next = user->follow;
        user->follow = follow;
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    User* user = find_user(obj, followerId);
    //自己不能取消自己
    if(NULL == user || followerId == followeeId)
        return;
    Follower **p = &(user->follow); 
    while(*p)
    {
        if((*p)->fId == followeeId)
            break;
        else
            p = &((*p)->next);
    }
    if(NULL == *p)
        return;
    else
    {
        Follower *tmp = *p;
        *p = (*p)->next;
        free(tmp);
    }
}

void twitterFree(Twitter* obj) {
    User *u;
    Tweet *t;
    while(obj->user_list)
    {
        u = obj->user_list;
        Follower *f;
        while(u->follow)
        {
            f = u->follow;
            u->follow = f->next;
            free(f);
        }
        obj->user_list = u->next;
        free(u);
    }
    while(obj->tweet_list)
    {
        t = obj->tweet_list;
        obj->tweet_list = t->next;
        free(t);
    }
    free(obj); 
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/