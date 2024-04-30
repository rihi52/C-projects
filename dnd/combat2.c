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

/* Global players and enemies */
part ravi;
part finn;
part pax;
part theon;
part okssort;
part ildmane;

/* Global Variables*/
int initSpread = 30;
part *initOrder[30];

/* part Names */
char *orcNames[] = {"orc1", "orc2","orc3", "orc4","orc5", "orc6","orc7", "orc8","orc9", "orc10"};
char *axeNames[] = {"axe1", "axe2","axe3", "axe4","axe5", "axe6","axe7", "axe8","axe9", "axe10"};
char *orogNames[] = {"orog1", "orog2","orog3", "orog4","orog5", "orog6","orog7", "orog8","orog9", "orog10"};
char *magminNames[] = {"magmin1", "magmin2","magmin3", "magmin4","magmin5", "magmin6","magmin7", "magmin8","magmin9", "magmin10"};

/* Function Prototypes*/
void setInitiative(struct part *person, int size);
void addEnemy (struct part *enemy, int size, int initiative);
void printInitOrder(struct part *array[]);
// void initPlayercombat(struct player *array, int size, int init);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0, numPlayer = 4, numGiant = 2;    
    int initOrc = 0, initOrog = 0, initMagmin = 0;
    char type;

    /* Initialize initiative brackets with NULL */
    for (int i = 0; i < 30; i++)
    {
        initOrder[i] = NULL;
    }

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

    /* Orc Enemies */
    part orc = {"orc", 0, 13, 15, NULL};

    /* Orog Enemies */
    part orog = {"orog", 0, 18, 53, NULL};

    /* Magmin Enemies */
    part magmin = {"magmin", 0, 15, 9, NULL};
    
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

    printf("Orog initiative: ");
    scanf("%i", &initOrog);

    printf("Magmin initiative: ");
    scanf("%i", &initMagmin);

    addEnemy(&orc, numOrc, initOrc);
    addEnemy(&orog, numOrog, initOrog);
    addEnemy(&magmin, numMagmin, initMagmin);

    
    initOrder[ravi.init] = &ravi;
    initOrder[finn.init] = &finn;
    initOrder[pax.init] = &pax;
    initOrder[theon.init] = &theon;
    /*while(temp != NULL){        
        temp = temp->next;
    }*/

    initOrder[okssort.init] = &okssort;
    initOrder[ildmane.init] = &ildmane;
    /*while(temp != NULL){
        temp = temp->next;
    }*/

    initOrder[orc.init] = &orc;
    initOrder[orog.init] = &orog;
    initOrder[magmin.init] = &magmin;

    printInitOrder(initOrder);

    return 0;
}

void setInitiative(struct part *person, int size)
{
    part *temp = person;

    for (int i = 0; i < size; i++)
    {
        printf("%s's initiative: ", temp->name);
        scanf("%i", &temp->init);
        temp = temp->next;
    }
    return;
}

void addEnemy (struct part *enemy, int size, int initiative)
{
    if (size <= 1)
    {
        return;
    }

    //part *temp = malloc(sizeof(part));
    enemy->init = initiative;
    part *temp = enemy;
    for (int i = 0; i < size; i++)
    {
        temp->next = enemy;
        printf("added %s\n", temp->name);
        if (i == size - 1){
            temp->next = NULL;
        }else{
        temp = temp->next->next;    
        }
    }

    temp = enemy->next;

    /*while (temp != NULL){
    free(temp);
    temp = temp->next;
    }*/
    return;
}

void printInitOrder(struct part *array[])
{
    part *temp;
    printf("\n****** Intiative Order Start******\n\n");

    for(int i = initSpread - 1; i >= 0; i--){
        if (initOrder[i] == NULL){
            continue;
        }
        temp = initOrder[i];
        printf("%s: %i\n", temp->name, temp->init);
    }
    printf("\n****** Intiative Order End ******\n");
}