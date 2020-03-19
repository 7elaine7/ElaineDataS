int hash_a(char a)
{
    return a - 'A';
}

int longestPalindrome(char * s){
    int hash_array[60];
    memset(hash_array, 0, sizeof(hash_array));
    char *p = s;
    bool flag = false;
    int count = 0;
    while('\0' != *p)
    {
        hash_array[hash_a(*p)]++;
        p++;
    }
    for(int n = 0; n < sizeof(hash_array)/sizeof(hash_array[0]); ++n)
    {
        if(0 == (hash_array[n] % 2))
        {
            count = count + hash_array[n];
        }
        else
        {
            count = count + hash_array[n] - 1;
            if(false == flag)
            {
                flag = true;
            }            
        }
    }
    if(true == flag)
        count++;
    return count;
}