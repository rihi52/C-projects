#include <stdio.h>
#include <stdlib.h>

// typedef struct subClass;
// typedef struct classFeat;

typedef struct class{
    char *name;
    char *subClass;
    char *classFeat;
    /*subClass subClass1;
    subClass subClass2;
    classFeat classFeat1;
    classFeat classFeat2;*/
}class;

typedef struct subClass{
    char *name;
}subClass;

typedef struct classFeat{
    char *name;
    int level;
}classFeat;

subClass subClass1 = {"Champion"};
subClass subClass2 = {"Battle Master"};
classFeat classFeat1 = {"Action Surge", 2};
classFeat classFeat2 = {"Extra Attack", 5};

class fighter = {"Fighter", "Champion", "Action Surge"};