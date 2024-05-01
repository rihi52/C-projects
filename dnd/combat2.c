#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Stucts */
typedef struct part{
    char *name;
    bool playerChar; // True for player character
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

//part *temp2;

/* Orc Enemies */
part orc = {"orc", false, 0, 13, 15, NULL};

/* Orog Enemies */
part orog = {"orog", false, 0, 18, 53, &orc};

/* Magmin Enemies */
part magmin = {"magmin", false, 0, 15, 9, &orog};

/* Linked list of unique part stats */
part ildmane = {"ildmane", true, 0, 18, 162, &magmin};
part okssort = {"okssort", true, 0, 17, 162, &ildmane};

/* Linked list of player stats */
part theon = {"theon", true, 0, 16, 55, &okssort};
part pax = {"pax", true, 0, 16, 57, &theon};
part finn = {"finn", true, 0, 15, 36, &pax};
part ravi = {"ravi", true, 0, 16, 34, &finn};

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
void addEnemy (struct part *tail, struct part *enemy);
void printInitOrder(struct part *head);
part *createNode(struct part *enemy);
// void initPlayercombat(struct player *array, int size, int init);

int main(void)
{
    //part *head;
    //part *tail;
    int numOrc = 0, numOrog = 0, numMagmin = 0, numPlayer = 4, numGiant = 2;    
    int initOrc = 0, initOrog = 0, initMagmin = 0;
    char type;

    /* Initialize initiative brackets with NULL */
    for (int i = 0; i < 30; i++)
    {
        initOrder[i] = NULL;
    }

    /* Orc Enemies */
   // part orc = {"orc", false, 0, 13, 15, NULL};

    /* Orog Enemies */
    //part orog = {"orog", false, 0, 18, 53, orc};

    /* Magmin Enemies */
    //part magmin = {"magmin", false, 0, 15, 9, orog};

    /* Linked list of unique part stats */
    //part ildmane = {"ildmane", true, 0, 18, 162, magmin};
    //part okssort = {"okssort", true, 0, 17, 162, &ildmane};    

    /* Linked list of player stats */
    /*part theon = {"theon", true, 0, 16, 55, okssort};
    part pax = {"pax", true, 0, 16, 57, &theon};
    part finn = {"finn", true, 0, 15, 36, &pax};
    part ravi = {"ravi", true, 0, 16, 34, &finn};*/

    part *head = &ravi;
    part *tail = &orc;
    
    setInitiative(&ravi, numPlayer);

    // setInitiative(&okssort, numGiant);
    
    /* part count */
    printf("How many orcs: ");
    scanf("%i", &numOrc);
   
    printf("How many orogs: ");
    scanf("%i", &numOrog);

    printf("How many magmins: ");
    scanf("%i", &numMagmin);

    /* Assign Initiative */
    printf("Orc initiative: ");
    scanf("%i", &orc.init);

    printf("Orog initiative: ");
    scanf("%i", &initOrog);

    printf("Magmin initiative: ");
    scanf("%i", &initMagmin);

    part *newEnemy;

    for(int i = 0; i < numOrc; i++)
    {
        if(numOrc <= 1)
        {
            break;
        }
        newEnemy = createNode(&orc);
        addEnemy(tail, newEnemy);
    }
    for(int i = 0; i < numOrog; i++)
    {
        if(numOrog <= 1)
        {
            break;
        }
        newEnemy = createNode(&orog);
        addEnemy(tail, newEnemy);
    }
    for(int i = 0; i < numMagmin; i++)
    {
        if(numMagmin <= 1)
        {
            break;
        }
        newEnemy = createNode(&magmin);
        addEnemy(tail, newEnemy);
    }
    
    //addEnemy(tail, &orog, numOrog, initOrog);
    //addEnemy(tail, &magmin, numMagmin, initMagmin);

    
    initOrder[ravi.init] = &ravi;
    initOrder[finn.init] = &finn;
    initOrder[pax.init] = &pax;
    initOrder[theon.init] = &theon;

    initOrder[okssort.init] = &okssort;
    initOrder[ildmane.init] = &ildmane;

    initOrder[orc.init] = &orc;
    initOrder[orog.init] = &orog;
    initOrder[magmin.init] = &magmin;

    printInitOrder(head);

    return 0;
}

void setInitiative(struct part *person, int size)
{
    part *current = person;

    while (current->next != NULL){
        if (current->playerChar == false)
        {
            break;
        }
        printf("%s's initiative: ", current->name);
        scanf("%i", &current->init);
        current = current->next;
    }
    return;
}

//void addEnemy (struct part *tail, struct part *enemy, int size, int initiative)
void addEnemy (struct part *tail, struct part *enemy)
{
    tail->next = enemy;
    printf("%p, %p\n", enemy, tail->next);
    tail = tail->next;
    printf("%p, %p\n", enemy, tail->next);
    return;
}

part *createNode(struct part *enemy)
{
    part *new = malloc(sizeof(part));

    if (enemy == &orc)
    {
        new->name = orc.name;
        new->playerChar = orc.playerChar;
        new->ac = orc.ac;
        new->hp = orc.hp;
        new->init = orc.init;        
        new->next = NULL;
    }
    else if(enemy == &orog)
    {
        new->name = orog.name;
        new->playerChar = orog.playerChar;
        new->ac = orog.ac;
        new->hp = orog.hp;
        new->init = orog.init;        
        new->next = NULL;
    }
    else if(enemy == &magmin)
    {
        new->name = magmin.name;
        new->playerChar = magmin.playerChar;
        new->ac = magmin.ac;
        new->hp = magmin.hp;
        new->init = magmin.init;        
        new->next = NULL;
    }
    return new;
}

void printInitOrder(struct part *head)
{
    part *temp = head;
    printf("\n****** Intiative Order Start******\n\n");

    for(int i = initSpread; i > 0; i--)
    {
        while (temp != NULL)
        {
            if (temp->init == i)
            {
            printf("%s, AC: %i, HP: %i\n", temp->name, temp->ac, temp->hp);
            }
            temp = temp->next;
        }
        temp = head;
    }
    printf("\n****** Intiative Order End ******\n");
    return;
}
