#ifndef _DATE_
#define _DATE_

// definição
typedef struct date Date;

// implementação
Date* newDate(int day, int month, int year);
void dateDealloc(Date** date);
void printDate(Date* date);

#endif