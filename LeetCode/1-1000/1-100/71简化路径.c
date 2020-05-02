/*
71. 简化路径
以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
示例 1：
输入："/home/"
输出："/home"
解释：注意，最后一个目录名后面没有斜杠。
示例 2：
输入："/../"
输出："/"
解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
示例 3：
输入："/home//foo/"
输出："/home/foo"
解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
示例 4：
输入："/a/./b/../../c/"
输出："/c"
示例 5：
输入："/a/../../b/../c//.//"
输出："/c"
示例 6：
输入："/a//b////c/d//././/.."
输出："/a/b/c"
*/

//function 1， 分类比较混乱，比较慢 
char * simplifyPath(char * path){
    int size = strlen(path);
    char *result = (char*)malloc(sizeof(char) * (size + 2));
    memset(result, 0, sizeof(char) * (size + 2));
    if(size == 0)
        return result;
    int tail = 0;
    result[size] = '\0';
    for(int i = 0; i < size;)
    {
        if(path[i] == '/')
        {
            if(0 == tail)
            {
                result[tail++] = path[i++];
            }
            else if(result[tail - 1] == '/')
            {
                i++;
            }
            else if(path[i + 1] != '\0')
            {
                result[tail++] = path[i++];
            }
            else
            {
                i++;
            }
        }
        else if(path[i] == '.')
        {
            if(result[tail - 1] == '/')
            {
                // ..出栈, .跳过
                if((i + 2 <= size) && (path[i + 1] == '.') && ((path[i + 2] == '/') || (path[i + 2] == '\0')))
                {
                    if(tail == 1)
                    {
                        i = i + 2;
                        continue;
                    }
                    tail--;
                    while(result[tail - 1] != '/')
                    {
                        tail--;
                    }
                    i = i + 2;
                }
                else if((path[i + 1] == '/') || (path[i + 1] == '\0'))
                {
                    i++;
                }
                else
                {
                    while(path[i] != '/' && i < size)
                    {
                        result[tail++] = path[i++];
                    }
                }
            }
            else    //作为普通字符名
            {
                result[tail++] = path[i++];
            }
        }
        else
        {
            if(tail == 0)
                result[tail++] = '/';
            result[tail++] = path[i++];
        }
    }
    if(tail > 1 && result[tail - 1] == '/')
        tail--;
    result[tail] = '\0';
    return result;
}

//function 2, 分类更清晰，比较快
char * simplifyPath(char * path){
    int size = strlen(path);
    char *result = (char*)malloc(sizeof(char) * (size + 2));
    memset(result, 0, sizeof(char) * (size + 2));
    if(size == 0)
        return result;
    result[0] = '/';
    int tail = 0;
    for(int i = 0; i < size;)
    {
        if(path[i] == '/' || path[i] == '.' && (path[i + 1] == '/' || path[i + 1] == '\0')) 
        {
            i++;
            continue;
        }
        else if(path[i] == '.' && path[i + 1] == '.' && (path[i + 2] == '/' || path[i + 2] == '\0'))
        {
            while(tail > 0 && result[--tail] != '/');
            i = i + 2;
        }
        else
        {
            while(i < size && path[i] != '/')
            {
                result[++tail] = path[i++];
            }
            if((path[i] == '/') && (path[i + 1] != '\0'))
            {
                result[++tail] = path[i++];
            }
        }
    }
    if(tail > 0 && result[tail] == '/')
    {
        result[tail] = '\0';
    }
    else
    {
        result[++tail] = '\0';
    }   
    return result;
}