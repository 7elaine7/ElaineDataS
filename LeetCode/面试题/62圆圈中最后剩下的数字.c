/*
约瑟夫环
数学公示反推：
最后只剩下一个的时候，就是返回值，假设此时下标为0
每次恢复一个值，都要恢复与新数字三步的距离，一直追踪最后剩下那一个数的下标
当恢复到原有数值时候，下标就是返回的数字
*/
int lastRemaining(int n, int m){
    int index = 0;  //初始为只剩下一个元素时候的下标
    for(int i = 2; i <= n; ++i)
    {
        index = (index + m) % i;
    }
    return index;
}
