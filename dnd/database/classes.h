#include <stdio.h>
#include <stdlib.h>

typedef struct class{
    char *name;
    char *subClass1;
    char *subClass2;
    char *classFeat1;
    char *classFeat2;
}class;

typedef struct subClass{
    char *name;
}subClass;

typedef struct classFeat{
    char *name;
}classFeat;