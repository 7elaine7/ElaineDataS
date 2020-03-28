#define MAX_SIZE 2000*7+2000
typedef struct word{
    int len;
    int index;
}Word;
//快排从大到小
void swap(Word *arr, int m, int n)
{
    Word tmp = arr[m];
    arr[m] = arr[n];
    arr[n] = tmp;
}
int get_q(Word *arr, int start, int end)
{
    int i, j;
    i = j = start;
    for(;j < end; ++j)
    {
        if(arr[j].len > arr[end].len)
        {
            swap(arr, i, j);
            ++i;
        }
    }
    swap(arr, i, end);
    return i;
}
void quik_sort(Word *arr, int start, int end)
{
    if(start >= end)
        return;
    int q = get_q(arr, start, end);
    quik_sort(arr, start, q-1);
    quik_sort(arr, q+1, end);
}

int minimumLengthEncoding(char ** words, int wordsSize){
    Word* arr = (Word*)malloc(sizeof(Word) * wordsSize);
    if(!arr)
        return -1;
    //将字符串每个单词字母数统计填入结构体数组
    for(int i = 0; i < wordsSize; ++i)
    {
        arr[i].len = strlen(words[i]);
        arr[i].index = i;
    }

    quik_sort(arr, 0, wordsSize - 1);

    //索引字符串S
    int count = arr[0].len;
    char *S = (char*)malloc(sizeof(char) * MAX_SIZE);
    strcpy(S, words[arr[0].index]);
    S[count] = '#';
    count++;

    for(int m = 1; m < wordsSize; ++m)
    {
        char A[10];
        strcpy(A, words[arr[m].index]);
        strcat(A, "#");

        if(!strstr(S, A))
        {
            strcpy(&(S[count]), A);
            count = count + arr[m].len;
            S[count] = '#';
            count++;            
        }
    }

    return count;
}