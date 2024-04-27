#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Stucts */
typedef struct part{
    char *name;
    int init;
    int ac;
    int hp;
    struct part *next;
}part;

part *initOrder[30];

/* Global players and enemies */
part ravi;
part finn;
part pax;
part theon;
part okssort;
part ildmane;

/* Global Variables*/
/* part Names */
char *orcNames[] = {"orc1", "orc2","orc3", "orc4","orc5", "orc6","orc7", "orc8","orc9", "orc10"};
char *axeNames[] = {"axe1", "axe2","axe3", "axe4","axe5", "axe6","axe7", "axe8","axe9", "axe10"};
char *orogNames[] = {"orog1", "orog2","orog3", "orog4","orog5", "orog6","orog7", "orog8","orog9", "orog10"};
char *magminNames[] = {"magmin1", "magmin2","magmin3", "magmin4","magmin5", "magmin6","magmin7", "magmin8","magmin9", "magmin10"};

/* Function Prototypes*/
void setInitiative(struct part *person, int size);
void addStats(struct part* array, int size, char type, int init);
bool checkHp(struct part* orcArray, int orcSize, struct part* axeArray, int axeSize, struct part* orogArray, int orogSize, struct part* magminArray, int magminSize);
void printInitbracket(struct part *array, int size);
void initPartcombat(struct part *array, int size, int init);
// void initPlayercombat(struct player *array, int size, int init);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0, numPlayer = 4, numGiant = 2;    
    int initOrc = 0, initOrog = 0, initMagmin = 0;
    char type;

    /* Linked list of unique part stats */
    part ildmane = {"ildmane", 0, 18, 162, NULL};
    part okssort = {"okssort", 0, 17, 162, &ildmane};    

    part giants[2] = {{"okssort", 0, 17, 162},
                      {"ildmane", 0, 18, 162}};

    /* Linked list of player stats */
    part theon = {"theon", 0, 16, 55, NULL};
    part pax = {"pax", 0, 16, 57, &theon};
    part finn = {"finn", 0, 15, 36, &pax};
    part ravi = {"ravi", 0, 16, 34, &finn};    
    
    part players[4] = {
                        {"ravi", 0, 16, 34},
                        {"pax", 0, 16, 57},
                        {"finn", 0, 15, 36},
                        {"theon", 0, 16, 55}};

    setInitiative(&ravi, numPlayer);

    setInitiative(&okssort, numGiant);
    
    /* part count */
    printf("How many orcs: ");
    scanf("%i", &numOrc);
    int numAxe = numOrc;

    printf("How many orogs: ");
    scanf("%i", &numOrog);

    printf("How many magmins: ");
    scanf("%i", &numMagmin);

    /* Assign Initiative */
    printf("Orc initiative: ");
    scanf("%i", &initOrc);
    int initAxe = initOrc;

    printf("Orog initiative: ");
    scanf("%i", &initOrog);

    printf("Magmin initiative: ");
    scanf("%i", &initMagmin);

    int totalCombatants = numPlayer + numOrc + numOrog + numMagmin + numGiant;
    int totalInits = numPlayer + 4;
    int initiatives[totalInits];
    initiatives[0] = players[0].init;
    initiatives[1] = players[1].init;
    initiatives[2] = players[2].init;
    initiatives[3] = players[3].init;

    initiatives[4] = initOrc;
    initiatives[5] = initOrog;
    initiatives[6] = initMagmin;
    initiatives[7] = giants[0].init;

    /* Initialize part arrays*/
    part orcs[numOrc];
    part orogs[numOrog];
    part magmins[numMagmin];
    part axes[numAxe];

    /* Add stats to part arrays*/
    type = 'a';
    addStats(orcs, numOrc, type, initOrc);
    type = 'b';
    addStats(orogs, numOrog, type, initOrog);
    type = 'c';
    addStats(magmins, numMagmin, type, initMagmin);
    type = 'd';
    addStats(axes, numAxe, type, initAxe);
    
    do
    {
        for(int i = 30; i > 0; i--)
        {
            for(int j = 0; j < totalInits; j++)
            {
                if (i == initiatives[j])
                {
                    printf("\n**********************\n");
                    printf("*** Total Combatants ***\n");
                    printInitbracket(players, numPlayer);
                    printInitbracket(giants, numGiant);
                    printInitbracket(orcs, numOrc);
                    printInitbracket(orogs, numOrog);
                    printInitbracket(magmins, numMagmin);
                    printf("\n**********************\n");
                    break;
                }                
            }
            for(int j = 0; j < numPlayer; j++)
            {
                if (players[j].init == i)
                {
                    initPartcombat(players, numPlayer, i);
                }
            }
            if (giants[0].init == i)
            {
                initPartcombat(giants, numGiant, i);
            }
            if (orcs[0].init == i)
            {
                initPartcombat(orcs, numOrc, i);
            }
            if (orogs[0].init == i)
            {
                initPartcombat(orogs, numOrog, i);
            }
            if (magmins[0].init == i)
            {
                initPartcombat(magmins, numMagmin, i);
            }
            if (axes[0].init == i)
            {
                initPartcombat(axes, numAxe, i);
            }
        }
    } while (checkHp(orcs, numOrc, axes, numAxe, orogs, numOrog, magmins, numMagmin));
    

    return 0;
}

void setInitiative(struct part *person, int size)
{
    part *temp = malloc(sizeof(part));
    temp = person;
    for (int i = 0; i < size; i++)
    {
        printf("%s's initiative: ", temp->name);
        scanf("%i", &temp->init);
        temp = temp->next;
    }
    free(temp);
    return;
}

void addStats(struct part* array, int size, char type, int init)
{
    switch (type) {
    case 'a':
        for(int i = 0; i < size; i++)
        {
            array[i].name = orcNames[i];
            array[i].init = init;
            array[i].ac = 13;
            array[i].hp = 15;
        }
        break;
    case 'b':
    for(int i = 0; i < size; i++)
        {
            array[i].name = orogNames[i];
            array[i].init = init;
            array[i].ac = 18;
            array[i].hp = 42;
        }
        break;
    case 'c':
    for(int i = 0; i < size; i++)
        {
            array[i].name = magminNames[i];
            array[i].init = init;
            array[i].ac = 14;
            array[i].hp = 9;
        }
        break;
    case 'd':
    for(int i = 0; i < size; i++)
        {
            array[i].name = axeNames[i];
            array[i].init = init;
            array[i].ac = 11;
            array[i].hp = 19;
        }
        break;
    default:
        printf("error: type does not exist\n");
        break;
    }
    return;
}

bool checkHp(struct part* orcArray, int orcSize, struct part* axeArray, int axeSize, struct part* orogArray, int orogSize, struct part* magminArray, int magminSize)
{
    bool orc = false, axe = false, orog = false, magmin = false;
    for(int i = 0; i < orcSize; i++)
    {
        if (orcArray[i].hp > 0) orc = true;
    }

    for(int i = 0; i < axeSize; i++)
    {
        if (axeArray[i].hp > 0) axe = true;
    }

    for(int i = 0; i < orogSize; i++)
    {
        if (orogArray[i].hp > 0) orog = true;
    }

    for(int i = 0; i < magminSize; i++)
    {
        if (magminArray[i].hp > 0) magmin = true;
    }

    if (orc == true || axe == true || orog == true || magmin == true) return true;

    return false;
}

void printInitbracket(struct part *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s AC:%i HP:%i\n", array[i].name, array[i].ac, array[i].hp);
    }
}

void initPartcombat(struct part *array, int size, int init)
{
    char initState = '\0';
    int dmgpart = 0, dmgAmount = 0;

    do
    {
        printf("*** Combatants at Initiative %i ***\n\n", init);
        printInitbracket(array, size);
        printf("\n********************************\n");
        printf("What next: ");
        scanf(" %c", &initState);
        printf("%c\n", initState);
        if (initState == 'd')
        {
            printf("Damage to: ");
            scanf("%i", &dmgpart);
            // Checking printf("%i\n", orcs[dmgpart].hp);
            if (array[dmgpart].hp <= 0)
            {
                printf("*** Already dead ***\n");
            }
            else
            {
            printf("Damage amount: ");
            scanf("%i", &dmgAmount);

            array[dmgpart].hp -= dmgAmount;
            }
            // Checking printf("%i\n", orcs[dmgpart].hp);
            printf("%c\n", initState);
            initState = 'w';
            printf("%c\n", initState);
        }
        printf("%c\n", initState);
    } while (initState == 'w');
    printf("%c final\n", initState);
    return;
}