#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct armor{
    char *name;
    bool prof;
}armor;

/*typedef struct lightArmor{
    armor light;
    armor padded;
    armor leather;
    armor studded;
}lightArmor;

typedef struct mediumArmor{
    armor medium;
    armor hide;
    armor chainShirt;
    armor scale;
    armor breastPlate;
    armor halfPlate;
}mediumArmor;

typedef struct heavyArmor{
    armor heavy;
    armor ring;
    armor chainMail;
    armor splint;
    armor plate;
}heavyArmor;*/

typedef struct armorProf{
    char *light;
    char *padded;
    char *leather;
    char *studded;
    char *medium;
    char *hide;
    char *chainShirt;
    char *scale;
    char *breastPlate;
    char *halfPlate;
    char *heavy;
    char *ring;
    char *chainMail;
    char *splint;
    char *plate;

    /*armor light;
    armor padded;
    armor leather;
    armor studded;
    armor medium;
    armor hide;
    armor chainShirt;
    armor scale;
    armor breastPlate;
    armor halfPlate;
    armor heavy;
    armor ring;
    armor chainMail;
    armor splint;
    armor plate;*/
}armorProf;

/*typedef struct subClass{
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

typedef struct armorProficiencies{
    bool heavy;
    bool medium;
    bool light;
    bool shields;    
}armorProficiencies;

typedef struct simpleWeaponProficienies{
    bool all;
    bool club;
    bool dagger;
    bool greatclub;
    bool handaxe;
    bool javelin;
    bool lightHammer;
    bool mace;
    bool quarterstaff;
    bool spear;
    bool lightCrossbow;
    bool dart;
    bool shortbow;
    bool sling;
}simpleWeaponProficienies;

typedef struct maritialWeaponProficienies{
    bool all;
    bool battleaxe;
    bool flail;
    bool glaive;
    bool greataxe;
    bool greatsword;
    bool halberd;
    bool lance;
    bool longsword;
    bool maul;
    bool morningstar;
    bool pike;
    bool rapier;
    bool scimitar;
    bool shortsword;
    bool trident;
    bool warPick;
    bool warhammer;
    bool whip;
    bool blowgun;
    bool handCrossbow;
    bool heavyCrossbow;
    bool longbow;
    bool net;
}martialWeaponProficienies;*/

/*typedef struct class{
    char *name;
    char *hitDie;
    armorProficiencies *armor;
    simpleWeaponProficienies *simple;
    martialWeaponProficienies *martial;
    subClass *sub1;
    subClass *sub2;
    subClass *sub3;
    classFeat *feat1;
    classFeat *feat2;
    classFeat *feat3;
    subFeat *subFeat1;
}class;*/

/***** Fighter *****/

/*armorProficiencies fighterArmor = {true};

const classFeat secondWind = {
    "Second Wind",
    1,
    "You have a limited well of stamina that you can draw on to protect yourself\n"
    "from harm. On your turn, you can use a bonus action to regain hit points\n"
    "equal to 1d10 + your fighter level.\n"
    "Once you use this feature, you must finish a short or long rest before you\n"
    "can use it again."
};

const classFeat fighterActionSurge = {
    "Action Surge",
    2,
    "Starting at 2nd level, you can push yourself\n"
    "beyond your normal limits for a moment. On your turn, you can\n"
    "take one additional action.\n"
    "Once you use this feature, you must finish a short or long rest\n"
    "before you can use it again. Starting at 17th level, you can use\n"
    "it twice before a rest, but only once on the same turn."
};

const subClass fighterChampion = {"Champion", NULL};
const subClass fighterBmaster = {"Battle Master", NULL};

const classFeat fighterExtraAttack = {"Extra Attack", 5, NULL};

const class fighter = {"Fighter", "d10", &fighterChampion, &fighterBmaster, NULL, &fighterActionSurge, &fighterExtraAttack, NULL};*/

/***** Rogue *****/
/*const subClass rogueThief = {"Thief", NULL};
const subClass rogueArcaneTrickster = {"Arcane Trickster", NULL};
const subClass rogueAssassin = {"Assassin", NULL};
const classFeat rogueFeat1 = {"Sneak Attack", 1, NULL};
const classFeat rogueFeat2 = {"Expertise", 2, NULL};

const class rogue = {"Rogue", &rogueThief, &rogueArcaneTrickster, &rogueAssassin, &rogueFeat1, &rogueFeat2, NULL};*/
