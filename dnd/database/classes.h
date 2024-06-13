#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "proficiencies.h"

typedef const struct class{
    armorProf profs;
}class;

class barbarian = { {"Light",
                    NULL, /**/
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL}};

/*= {   "Light",
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };*/