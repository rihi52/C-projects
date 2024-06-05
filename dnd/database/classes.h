#include <stdio.h>
#include <stdlib.h>
typedef struct subClass{
    char *name;
}subClass;

typedef struct classFeat{
    char *name;
    int level;
}classFeat;

typedef struct class{
    char *name;
    subClass *sub1;
    subClass *sub2;
    subClass *sub3;
    classFeat *feat1;
    classFeat *feat2;
}class;

subClass fighterChampion = {"Champion"};
subClass fighterBmaster = {"Battle Master"};
classFeat fighterActionSurge = {"Action Surge", 2};
classFeat fighterExtraAttack = {"Extra Attack", 5};

class fighter = {"Fighter", &fighterChampion, &fighterBmaster, NULL, &fighterActionSurge, &fighterExtraAttack};

subClass rogueThief = {"Thief"};
subClass rogueArcaneTrickster = {"Arcane Trickster"};
subClass rogueAssassin = {"Assassin"};
classFeat rogueFeat1 = {"Sneak Attack", 1};
classFeat rogueFeat2 = {"Expertise", 2};

class rogue = {"Rogue", &rogueThief, &rogueArcaneTrickster, &rogueAssassin, &rogueFeat1, &rogueFeat2};
