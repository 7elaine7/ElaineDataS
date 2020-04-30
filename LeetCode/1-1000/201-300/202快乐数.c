/*
202. 快乐数
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 True ；不是，则返回 False 。
示例：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
//如果不是快乐数，那么一定会成环
//判断环：快慢指针，快指针一定会在慢指针没走完一圈的时候与之相遇！
int get_sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum = sum + (n % 10) * (n % 10);
        n = n / 10;
    }
    return sum;
}
bool isHappy(int n){
    int slow = n;
    int fast = n;
    while(true)
    {
        slow = get_sum(slow);
        fast = get_sum(fast);
        fast = get_sum(fast);
        if(fast == 1)
            return true;
        if(fast == slow)
            return false;
    }
}
