#include <stdio.h>
#include <math.h>

void printRow(void);
void printDivider(void);

int main(void)
{
    printRow();
    printDivider();
    printRow();
    printDivider();
    printRow();    
}

void printRow(void)
{
    printf("  ");
    printf("|");
    printf("   ");
    printf("|");
    printf(" \n");
}

void printDivider(void)
{
    printf("---------\n");
}