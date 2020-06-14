/*
1300. 转变数组后最接近目标值的数组和
给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。
如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。
请注意，答案不一定是 arr 中的数字。
示例 1：
输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
示例 2：
输入：arr = [2,3,5], target = 10
输出：5
示例 3：
输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361
提示：
1 <= arr.length <= 10^4
1 <= arr[i], target <= 10^5
*/

//function 1, 先排序， 然后缩小范围
#define min(x, y) (x < y ? x : y)
void swap(int* arr, int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
int get_q(int* arr, int start, int end)
{
    int i = start;
    int j = start;
    for(; j < end; ++j)
    {
        if(arr[j] < arr[end])
        {
            swap(arr, j, i);
            ++i;
        }
    }
    swap(arr, i, end);
    return i;
}
void quik_sort(int* arr, int start, int end)
{
    if(start >= end)
        return ;
    int q = get_q(arr, start, end);
    quik_sort(arr, start, q - 1);
    quik_sort(arr, q + 1, end);
}
int findBestValue(int* arr, int arrSize, int target){
    //快排
    quik_sort(arr, 0, arrSize - 1);
    int avg = target / arrSize;
    avg = abs(avg * arrSize - target) <= abs((avg + 1) * arrSize - target) ? avg : avg + 1;
    int sum = 0;
    int count = 0;
    while(arr[count] <= avg && count < arrSize)
    {
        sum += arr[count];
        count++;
    }
    if(count == arrSize || count == 0)
        return avg;
    int min = sum + (arrSize - count) * avg;
    for(;count < arrSize; ++count)
    {
        int tmp = sum + (arrSize - count) * arr[count];
        if(abs(tmp - target) < abs(min - target))
        {
            min = tmp;
        }
        else
        {
            break;
        }
        sum += arr[count];
    }
    if(count == arrSize)
        return arr[count - 1];
    int left, right;
    if(min > target)
    {
        right = arr[count - 1];
        left = arr[count - 2] > avg ? arr[count - 2] : avg;
        sum = sum - arr[count - 1];
        count = count - 1;
        for(int i = right - 1; i > left; --i)
        {
            int tmp = sum + i * (arrSize - count);
            if(abs(tmp - target) < abs(min - target))
            {
                min = tmp;
            }
            else
            {
                return i + 1;
            }            
        }
    }
    else
    {
        right = arr[count];
        left = arr[count - 1] > avg ? arr[count - 1] : avg;
        for(int i = left + 1; i < right; ++i)
        {
            int tmp = sum + i * (arrSize - count);
            if(abs(tmp - target) < abs(min - target))
            {
                min = tmp;
            }
            else
            {
                return i - 1;
            }
        }
    }

    return left;
}

//function 2, 优化
#define min(x, y) (x < y ? x : y)
void swap(int* arr, int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
int get_q(int* arr, int start, int end)
{
    int i = start;
    int j = start;
    for(; j < end; ++j)
    {
        if(arr[j] < arr[end])
        {
            swap(arr, j, i);
            ++i;
        }
    }
    swap(arr, i, end);
    return i;
}
void quik_sort(int* arr, int start, int end)
{
    if(start >= end)
        return ;
    int q = get_q(arr, start, end);
    quik_sort(arr, start, q - 1);
    quik_sort(arr, q + 1, end);
}
int findBestValue(int* arr, int arrSize, int target){
    //快排
    quik_sort(arr, 0, arrSize - 1);
    int avg = target / arrSize;
    avg = abs(avg * arrSize - target) <= abs((avg + 1) * arrSize - target) ? avg : avg + 1;
    int sum = 0;
    int count = 0;
    while(arr[count] <= avg && count < arrSize)
    {
        sum += arr[count];
        count++;
    }
    if(count == arrSize || count == 0)
        return avg;
    int min = sum + (arrSize - count) * avg;
    int left = avg + 1;
    int right = arr[arrSize - 1];
    int tmp;
    while(left <= right)
    {
        if(left > arr[count])
        {
            sum += arr[count];
            count++;
        }
        tmp = sum + (arrSize - count) * left;
        if(abs(tmp - target) < abs(min - target))
        {
            min = sum + (arrSize - count) * left;
            left++;
        }
        else
            break;
    }

    return left - 1;
}

//functinon 3, 如果当前数与后面数的平均值比当前数小，则返回四舍五入的平均值
#define min(x, y) (x < y ? x : y)
void swap(int* arr, int x, int y)
{
    int tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}
int get_q(int* arr, int start, int end)
{
    int i = start;
    int j = start;
    for(; j < end; ++j)
    {
        if(arr[j] < arr[end])
        {
            swap(arr, j, i);
            ++i;
        }
    }
    swap(arr, i, end);
    return i;
}
void quik_sort(int* arr, int start, int end)
{
    if(start >= end)
        return ;
    int q = get_q(arr, start, end);
    quik_sort(arr, start, q - 1);
    quik_sort(arr, q + 1, end);
}
int findBestValue(int* arr, int arrSize, int target){
    if(arr == NULL)
        return 0;
    //快排
    quik_sort(arr, 0, arrSize - 1);
    int sum = 0;
    for(int i = 0; i < arrSize; ++i)
    {
        int avg = (target - sum) / (arrSize - i);
        if(avg < arr[i])
        {
            if(abs(sum + avg * (arrSize - i) - target) <= abs(sum + (avg + 1) * (arrSize - i) - target))
                return avg;
            else
                return avg + 1;
        }
        sum += arr[i];
    }
    return arr[arrSize - 1];   
}