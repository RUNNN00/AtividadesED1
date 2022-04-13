#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "Date.h"

int main()
{
    Date* date1 = newDate(12, 04, 2022);
    Date* date2 = newDate(24, 04, 2021);

    printDate(date1);
    printDate(date2);

    return 0;
}