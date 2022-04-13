#include "Date.h"
#include<stdio.h>
#include<stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

Date* newDate(int day, int month, int year)
{
    Date* d = (Date*)malloc(sizeof(Date));
    d->day = day;
    d->month = month;
    d->year = year;

    return d;
}

void dateDealloc(Date** d)
{
    Date* daux = *d;
    free(daux);
    *d = NULL;
}

void printDate(Date* d)
{
    printf("%02d/%02d/%d\n", d->day, d->month, d->year);
}