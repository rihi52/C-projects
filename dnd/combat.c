#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Stucts */
typedef struct part{
    char *name;
    bool uniqueChar; // True for player character or Unique Enemy
    int init;
    int initSpot;
    int turnCount;
    int ac;
    int hp;
    bool isMalloc;
    struct part *next;
}part;

part enemies[] = {{"Orc", false, 0, 0, 0, 13, 15, NULL}, {"Orog", false, 0, 0, 0, 18, 53, NULL}}; // Test - do I need individually named structs or array of structs?

/***** Combatants *****/
/* To add more enemies, create a new part struct and point orc to it*/

/* Orc Enemies */
part orc = {"Orc", false, 0, 0, 0, 13, 15, NULL};

/* Orog Enemies */
part orog = {"Orog", false, 0, 0, 0, 18, 53, false, NULL};

/* Magmin Enemies */
part magmin = {"Magmin", false, 0, 0, 0, 15, 9, false, NULL};

/* Linked list of unique part stats */
part ildmane = {"ildmane", true, 0, 0, 0, 18, 162, false, NULL};
part okssort = {"okssort", true, 0, 0, 0, 17, 162, false, NULL};

/* Linked list of player stats */
part theon = {"theon", true, 0, 0, 0,16, 55, false, NULL};
part pax = {"pax", true, 0, 0, 0, 16, 57, false, NULL};
part finn = {"finn", true, 0, 0, 0, 15, 36, false, NULL};
part ravi = {"ravi", true, 0, 0, 0, 16, 34, false, NULL};

/* Global Variables*/
#define initSpread 30
int highestInit = 30;
int currentInit = 0;
int roundCount = 0;
int numCombatants = 1;
part *combatants[initSpread];

/* Function Prototypes*/
void setPlayerInitiative(struct part *person);
void addToInitiativeOrder(part *pAddition, int numAddition);
void countCombatants(int x);
void makeListofCombatants();
void printCurrentTurn();
void printInitOrder();
part *createNode(struct part *enemy);
void dealDamage(int init, int count, int amount);

void checkIntegerInputs(int *numberOf);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0, numGiant = 2, damaged = 0, damAmount = 0, damInit = 0;
    char event = ' ';
    /*
    d = damage
    e = end
    */
    bool combat = true;
    
    for(int i = 0; i < initSpread; i++){
        combatants[i] = NULL;
    }

    printf("\nBegin acquiring player character information\n");

    /* Assign player and unique initiative */
    printf("ravi\n");
    setPlayerInitiative(&ravi);
    printf("finn\n");
    setPlayerInitiative(&finn);
    setPlayerInitiative(&pax);
    setPlayerInitiative(&theon);

    printf("\n*** End acquiring player character information ***\n");
    
    printf("\n*** Begin acquiring enemy information ***\n");

    part *newEnemy;
    
    /* part count - establish how many enemies of which type*/
    printf("How many %s: ", orc.name);
    checkIntegerInputs(&numOrc);
   
    printf("How many %s: ", orog.name);
    checkIntegerInputs(&numOrog);

    printf("How many %s: ", magmin.name);
    checkIntegerInputs(&numMagmin);

    /* Assign Enemy Initiative */
    if (0 < numOrc)
    {
        printf("%s's initiative: ", orc.name);
        checkIntegerInputs(&orc.init);
        addToInitiativeOrder(&orc, numOrc);
        countCombatants(numOrc);
    }

    if (0 < numOrog)
    {
        printf("%s's initiative: ", orog.name);
        checkIntegerInputs(&orog.init);
        addToInitiativeOrder(&orog, numOrog);
        countCombatants(numOrog);
    }

    if (0 < numMagmin)
    {
        printf("%s's initiative: ", magmin.name);
        checkIntegerInputs(&magmin.init);
        addToInitiativeOrder(&magmin, numMagmin);
        countCombatants(numMagmin);
    }
    
    printf("\n*** End acquiring enemy information ***\n\n");

    

    printInitOrder();
    // printCurrentTurn();

 /* Main loop for combat */
    while (combat == true){
        printf("What happens: ");
        scanf(" %c", &event);
        switch (event){
            case 'd':
            printf("Which initiative count takes damage (enter initiative): ");
            scanf("%i", &damInit);
            printf("Which creature on %i initiative: ", damInit);
            scanf("%i", &damaged);
            printf("How much damage: ");
            scanf("%i", &damAmount);
            dealDamage(damInit, damaged, damAmount);
            printInitOrder();
            break;
            case 'e':            
            printf("\n********** Combat Over **********\n\n");
            combat = false;
            break;
            case 'n':
            printf("Next Turn\n");
            // printCurrentTurn();            
            break;
            default:
            printf("Invalid Choice: d for damage\ne for end combat\nn for next turn\n");
            break;
        }
        
    }

    /* Free mallocs */
    part *temp = NULL;
    part *current = orc.next;
    while(current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

void setPlayerInitiative(struct part *person)
{
    printf("%s's initiative: ", person->name);
    
    checkIntegerInputs(&person->init);

    if (0 != person->init)
    {
        numCombatants++;
    }
    //combatants[person->init] = person;
    addToInitiativeOrder(person, 1);
    return;
}

void checkIntegerInputs(int *numberOf)
{
    int check = 1;    
    while(check == 1)
    {
        if (scanf("%d", numberOf) != 1 || *numberOf < 0)
        {
            getchar();
            printf("Error - must be a positive integer: ");
        }
        else
        {
            check++;
        }
    }
}

void countCombatants(int x)
{
    if (x > 0)
    {
        numCombatants = numCombatants + x;
    }
}

part *createNode(struct part *enemy)
{
    part *new = malloc(sizeof(part));
    if (NULL == new){
        return NULL;
    }

    if (enemy == &orc)
    {
        new->name = orc.name;
        new->uniqueChar = orc.uniqueChar;
        new->ac = orc.ac;
        new->hp = orc.hp;
        new->init = orc.init;        
        new->next = NULL;
    }
    else if(enemy == &orog)
    {
        new->name = orog.name;
        new->uniqueChar = orog.uniqueChar;
        new->ac = orog.ac;
        new->hp = orog.hp;
        new->init = orog.init;        
        new->next = NULL;
        combatants[orog.init]->next = new;
    }
    else if(enemy == &magmin)
    {
        new->name = magmin.name;
        new->uniqueChar = magmin.uniqueChar;
        new->ac = magmin.ac;
        new->hp = magmin.hp;
        new->init = magmin.init;        
        new->next = NULL;
        combatants[magmin.init]->next = new;
    }
    else
    {

    }
    return new;
}

void addToInitiativeOrder(part *pAddition, int numAddition)
{
    part *temp = NULL;
    part *newEnemy = NULL;
    if(NULL == combatants[pAddition->init])
    {
        combatants[pAddition->init] = pAddition;
    }
    else
    {
        temp = combatants[pAddition->init]->next;
        while(NULL != temp)
        {
            temp = temp->next;
        }
        temp = pAddition;
        temp = NULL;
    }
    
    if (temp->uniqueChar == false)
    {
        temp = pAddition;
        for(int i = 0; i < numAddition - 1; i++)
        {
            newEnemy = createNode(&orc);
            temp->next = newEnemy;
            temp = newEnemy;
        }
    }
}

void printCurrentTurn()
{
    part *temp;
    int count = 1;

    if (roundCount == 0 && currentInit == 0)
    {
        while (temp->next != NULL)
        {
            if (temp->init > temp->next->init && temp->hp > 0)
            {
                currentInit = temp->init;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    else
    {
        while (temp->next != NULL)
        {
            if (temp->init == currentInit && temp->hp > 0 && temp->turnCount == roundCount)
            {
                if (temp->init == count) break;
                count++;
            }
            else
            {
                temp = temp->next;                
            }
            currentInit--;
        }
    }
    printf("%s's turn\n", temp->name);
    temp->turnCount++;
    return;
}

void printInitOrder()
{
    printf("\n****** Intiative Order Start******\n\n");

    part *temp = NULL;
    int count = 1;
    for (int i = highestInit; i >= 0; i--)
    {
        temp = combatants[i];
        while(temp != NULL)
        {
            printf("%i-%i. %s, AC: %i, HP: %i\n", temp->init, count, temp->name, temp->ac, temp->hp);
            temp->initSpot = count;
            count++;     
            temp = temp->next;
        }
    }

    printf("\n****** Intiative Order End ******\n");
    return;
}

void dealDamage(int init, int count, int amount)
{
    part *temp;
    int counter = 1;

    while (temp != NULL)
    {
        if (temp->init == init && counter != count)
        {
            counter++;
        }
        else if (temp->init == init && counter == count)
        {
            temp->hp -= amount;
            break;
        }      
        temp = temp->next;
    }    
    return;
}