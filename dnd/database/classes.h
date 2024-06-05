#include <stdio.h>
#include <stdlib.h>

typedef struct subClass{
    char *name;
    char *description;
}subClass;

typedef struct classFeat{
    char *name;
    int level;
    char *description;
}classFeat;

typedef struct subFeat{
    char *name;
    int level;
    char *description;
}subFeat;

typedef struct class{
    char *name;
    subClass *sub1;
    subClass *sub2;
    subClass *sub3;
    classFeat *feat1;
    classFeat *feat2;
    classFeat *feat3;
    subFeat *subFeat1;
}class;

classFeat secondWind = {
    "Second Wind",
    1,
    "You have a limited well of stamina that you can draw on to protect yourself\n"
    "from harm. On your turn, you can use a bonus action to regain hit points\n"
    "equal to 1d10 + your fighter level.\n"
    "Once you use this feature, you must finish a short or long rest before you\n"
    "can use it again."
};

classFeat fighterActionSurge = {
    "Action Surge",
    2,
    "Starting at 2nd level, you can push yourself\n"
    "beyond your normal limits for a moment. On your turn, you can\n"
    "take one additional action.\n"
    "Once you use this feature, you must finish a short or long rest\n"
    "before you can use it again. Starting at 17th level, you can use\n"
    "it twice before a rest, but only once on the same turn."
};

subClass fighterChampion = {"Champion", NULL};
subClass fighterBmaster = {"Battle Master", NULL};

classFeat fighterExtraAttack = {"Extra Attack", 5, NULL};

class fighter = {"Fighter", &fighterChampion, &fighterBmaster, NULL, &fighterActionSurge, &fighterExtraAttack, NULL};

subClass rogueThief = {"Thief", NULL};
subClass rogueArcaneTrickster = {"Arcane Trickster", NULL};
subClass rogueAssassin = {"Assassin", NULL};
classFeat rogueFeat1 = {"Sneak Attack", 1, NULL};
classFeat rogueFeat2 = {"Expertise", 2, NULL};

class rogue = {"Rogue", &rogueThief, &rogueArcaneTrickster, &rogueAssassin, &rogueFeat1, &rogueFeat2, NULL};
