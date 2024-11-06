#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Stucts */
typedef struct participant{
    char *name;
    bool uniqueChararacter; // True for player character or Unique Enemy
    int initiative;
    int initiativeSpot;
    int turnCount;
    int armorClass;
    int hitPoints;
    struct participant *next;
}participant;

int main(void)
{
    char * name = "name";
    int numberOf;
    printf("%s's initiatve: ", name);    
    while(1)
    {
        if (scanf("%d", &numberOf) != 1 || numberOf < 0)
        {
            getchar();
            printf("Error - must be a positive integer: ");
        }
        else
        {
            break;
        }
    }
}