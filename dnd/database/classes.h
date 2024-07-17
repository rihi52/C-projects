#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "proficiencies.h"
#include "defines.h"

struct class{
    char *name;
    int hitDie;
    // armorProf profs;
};

const struct class fifthEd[] ={
 [BARBARIAN] = {"Barbarian", 12},
 [BARD] = {"Bard", 8},
};