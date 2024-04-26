#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Stucts */
typedef struct enemy{
    char *name;
    int init;
    int ac;
    int hp;
}enemy;

typedef struct orc{
    int init;
    int ac;
    int hp;
}orc;

/* Global Variables*/
/* Enemy Names */
char *orcNames[] = {"orc1", "orc2","orc3", "orc4","orc5", "orc6","orc7", "orc8","orc9", "orc10"};
char *axeNames[] = {"axe1", "axe2","axe3", "axe4","axe5", "axe6","axe7", "axe8","axe9", "axe10"};
char *orogNames[] = {"orog1", "orog2","orog3", "orog4","orog5", "orog6","orog7", "orog8","orog9", "orog10"};
char *magminNames[] = {"magmin1", "magmin2","magmin3", "magmin4","magmin5", "magmin6","magmin7", "magmin8","magmin9", "magmin10"};

/* Function Prototypes*/
void addStats(struct enemy* array, int size, char type, int init);
bool checkHp(struct enemy* orcArray, int orcSize, struct enemy* axeArray, int axeSize, struct enemy* orogArray, int orogSize, struct enemy* magminArray, int magminSize);
void printInitbracket(struct enemy *array, int size);
void initCountcombat(struct enemy *array, int size, int init);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0;    
    int initOrc = 0, initOrog = 0, initMagmin = 0;
    char type;
    
    /* Enemy count */
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

    /* Initialize enemy arrays*/
    enemy orcs[numOrc];
    enemy orogs[numOrog];
    enemy magmins[numMagmin];
    enemy axes[numAxe];

    /* Add stats to enemy arrays*/
    type = 'a';
    addStats(orcs, numOrc, type, initOrc);
    type = 'b';
    addStats(orogs, numOrog, type, initOrog);
    type = 'c';
    addStats(magmins, numMagmin, type, initMagmin);
    type = 'd';
    addStats(axes, numAxe, type, initAxe);

    /* Unique enemy stats */
    enemy okssort = {"okssort", 0, 17, 162};
    enemy ildmane = {"ildmane", 0, 18, 162};

    

    do
    {
        for(int i = 25; i > 0; i--)
        {
            if (orcs[0].init == i)
            {
                initCountcombat(orcs, numOrc, i);
            }
            if (orogs[1].init == i)
            {

            }
            if (magmins[1].init == i)
            {

            }
        }
        
        


    } while (checkHp(orcs, numOrc, axes, numAxe, orogs, numOrog, magmins, numMagmin));
    

    return 0;
}

void addStats(struct enemy* array, int size, char type, int init)
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

bool checkHp(struct enemy* orcArray, int orcSize, struct enemy* axeArray, int axeSize, struct enemy* orogArray, int orogSize, struct enemy* magminArray, int magminSize)
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

void printInitbracket(struct enemy *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%s AC:%i HP:%i\n", array[i].name, array[i].ac, array[i].hp);
    }
}

void initCountcombat(struct enemy *array, int size, int init)
{
    char initState = '\0';
    int dmgEnemy = 0, dmgAmount = 0;
    do
    {
        printf("*** Enemies at Initiative %i ***\n\n", init);
        printInitbracket(array, size);
        printf("\n********************************\n");
        printf("What next: ");
        scanf(" %c", &initState);
        if (initState == 'd')
        {
            printf("Damage to: ");
            scanf("%i", &dmgEnemy);
            // Checking printf("%i\n", orcs[dmgEnemy].hp);
            if (array[dmgEnemy].hp <= 0)
            {
                printf("*** Already dead ***\n");
            }
            else
            {
            printf("Damage amount: ");
            scanf("%i", &dmgAmount);

            array[dmgEnemy].hp -= dmgAmount;
            }
            // Checking printf("%i\n", orcs[dmgEnemy].hp);

            initState = 'w';
        }
    } while (initState == 'w');
}