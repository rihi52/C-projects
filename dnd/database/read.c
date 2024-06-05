#include <stdio.h>
#include <stdlib.h>
#include "classes.h"

int main(void)
{
    printf("%s\n", fighter.name);
    printf("%s: %i\n", fighter.feat1->name, fighter.feat1->level);

    printf("%s\n %s: %s\n", rogue.name, rogue.sub1->name, rogueFeat1.name);
}