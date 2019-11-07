/*****************************************************************************
File name: ElaineDataS/DS/C/search/sqrt.c
Description: Square root by binary search
Author: Elaine Sun
Date: 19-11-06
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define E 0.000001

double searchq(double num)
{
    double low = 0.0;
    double high = num;
    double mid;

    if(num < 1.0 && num > 0.0)
    {
        low = 0;
        high = 1.0;
    }
    else if(num == 1.0 || num == 0.0)
    {
        return mid = num;
    }
    mid = low + (high - low) / 2;
    printf("mid is %lf\n", mid);

    while(fabs(mid * mid - num) > E)
    {
        if(mid * mid < num)
            low = mid;
        else
            high = mid;
        mid = low + (high - low) / 2;      
    }
    return mid;
}

double searcht(double num)
{
    double start = 0.0;
    double end = num;
    double mid;
    if(num < 1.0 && num > 0.0)
    {
        start = 0;
        end = 1.0;
    }
    else if(num == 1.0 || num == 0.0)
    {
        return mid = num;
    }
    while(1)
    {
        mid = end + (start - end) / 2;
        //if(fabs(mid*mid - num) > E)
        if(((mid*mid - E) <= num) && ((mid*mid + E) >= num))
        {
            return mid;
        }
        if((mid*mid - num) > E)
        //if(mid*mid > num)
        {
            end = mid;
        }
        else
        {
            start = mid;
        }
    }
    return 0;
}

int main(int argv, char *argc[])
{
    double num = 0.0;
    while(true)
    {
        printf("Pls. enter the number:");
        scanf("%lf", &num);

        double result = searcht(num);

        printf("The square root for %lf is: %lf\n", num, result);

        printf("Do you want to continue to find? Y/N\n");
        char ch;
        scanf(" %c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }
    return EXIT_SUCCESS;
}