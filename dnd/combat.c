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
    struct part *next;
}part;

part enemies[] = {{"Orc", false, 0, 0, 0, 13, 15, NULL}, {"Orog", false, 0, 0, 0, 18, 53, NULL}}; // Test - do I need individually named structs or array of structs?

/***** Combatants *****/
/* To add more enemies, create a new part struct and point orc to it*/

/* Orc Enemies */
part orc = {"Orc", false, 0, 0, 0, 13, 15, NULL};

/* Orog Enemies */
part orog = {"Orog", false, 0, 0, 0, 18, 53, &orc};

/* Magmin Enemies */
part magmin = {"Magmin", false, 0, 0, 0, 15, 9, &orog};

/* Linked list of unique part stats */
part ildmane = {"ildmane", true, 0, 0, 0, 18, 162, &magmin};
part okssort = {"okssort", true, 0, 0, 0, 17, 162, &ildmane};

/* Linked list of player stats */
part theon = {"theon", true, 0, 0, 0,16, 55, &okssort};
part pax = {"pax", true, 0, 0, 0, 16, 57, &theon};
part finn = {"finn", true, 0, 0, 0, 15, 36, &pax};
part ravi = {"ravi", true, 0, 0, 0, 16, 34, &finn};

/* Global Variables*/
#define initSpread 30
int highestInit = 30;
int currentInit = 0;
int roundCount = 0;
int numCombatants = 1;
part *combatants[initSpread];

/* Function Prototypes*/
void setInitiative(struct part *person, int size);
void addToInitiativeOrder(part *pAddition, part *tail, int numAddition);
void makeListofCombatants(struct part *head);
void printCurrentTurn(struct part *head);
void printInitOrder(struct part *head);
part *createNode(struct part *enemy);
void dealDamage(struct part *head, int init, int count, int amount);

void checkIntegerInputs(int *numberOf);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0, numPlayer = 4, numGiant = 2, damaged = 0, damAmount = 0, damInit = 0;
    char event = ' ';
    /*
    d = damage
    e = end
    */
    bool combat = true;

    part *head = &ravi;
    part *tail = &orc;
    
    for(int i = 0; i < initSpread; i++){
        combatants[i] = NULL;
    }

    printf("\nBegin acquiring player character information\n");

    /* Assign player and unique initiative */
    setInitiative(&ravi, numPlayer);
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

        addToInitiativeOrder(&orc, tail, numOrc);
    }

    if (0 < numOrog)
    {
        printf("%s's initiative: ", orog.name);
        checkIntegerInputs(&orog.init);
        addToInitiativeOrder(&orog, tail, numOrog);
    }

    if (0 < numMagmin)
    {
        printf("%s's initiative: ", magmin.name);
        checkIntegerInputs(&magmin.init);
        addToInitiativeOrder(&magmin, tail, numMagmin);
    }
    
    printf("\n*** End acquiring enemy information ***\n\n");

    /* Count total combatants */
    part *tempCount = head;
    // tempCount = head; blacked out for testing, don't think I need this at all
    while(tempCount != NULL)
    {
        if (tempCount->next == NULL)
        {
            numCombatants++;
            tempCount = tempCount->next;
            break;
        }
        else if (tempCount->init < tempCount->next->init)
        {
            highestInit = tempCount->next->init;
        }
        tempCount = tempCount->next;
        numCombatants++;
    }

    for(int i = 0; i < highestInit; i++)
    {
        combatants[i] = NULL;
    }
   
    // makeListofCombatants(head); DEBUG - blacked out to test not using it

    // for(int i = initSpread; i < 0; i--){

    // }

    printInitOrder(head);
    printCurrentTurn(head);

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
            dealDamage(head, damInit, damaged, damAmount);
            printInitOrder(head);
            break;
            case 'e':            
            printf("\n********** Combat Over **********\n\n");
            combat = false;
            break;
            case 'n':
            printf("Next Turn\n");
            printCurrentTurn(head);            
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

void setInitiative(struct part *person, int size)
{
    part *current = person;

    while (current->next != NULL){
        if (current->uniqueChar == false)
        {
            break;
        }
        printf("%s's initiative: ", current->name);
        // scanf("%i", &current->init);
        
        checkIntegerInputs(&current->init);
        combatants[current->init] = current;
        current = current->next;
    }
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

void addToInitiativeOrder(part *pAddition, part *tail, int numAddition)
{
    part *temp = NULL;
    part *newEnemy = NULL;
    if(NULL == combatants[pAddition->init])
    {
        combatants[pAddition->init] = pAddition;
    }
    else
    {
        temp = combatants[pAddition->init];
        while(NULL == temp->next)
        {
            temp = temp->next;
        }
        temp = pAddition;
        temp = NULL;
    }
    
    temp = pAddition;

    for(int i = 0; i < numAddition - 1; i++)
    {
        newEnemy = createNode(&orc);
        temp->next = newEnemy;
        temp = newEnemy;
        tail->next = newEnemy;
        tail = newEnemy;
    }
}

void makeListofCombatants(struct part *head) /* Array of combatants by initiative order, use this for printing */
{    
    part *temp = head;
    part *tempLoop;
    int tempInit = 0;
    // printf("%i\n",temp->init);
    while(temp != NULL)
    {
        tempInit = 0;
        if(combatants[temp->init] == NULL)
        {
            tempInit = temp->init;
            combatants[tempInit] = temp;
            temp = temp->next; /* Save spot in loop through head */
            combatants[tempInit]->next = NULL; /* Make array->next NULL */
        }
        else /* combatants[initiative] is occupied so make a linked list */
        {
            tempInit = temp->init;  /* Save initiative number */
            tempLoop = combatants[temp->init]; /* Set tempLoop to ->next of the current combatants[initiative]*/
            while(tempLoop != NULL){ /* Loop through tempLoop (linked list in current array position) until at the next empty position */
                tempLoop = tempLoop->next;
            }
            tempLoop = temp; /* Set empty position to the current combatant */
            temp = temp->next; /* Set current combatant to the next one in the head list */
            tempLoop->next = NULL; /* set combatants[] last position to NULL */
        }        
    }
}


void printCurrentTurn(struct part *head)
{
    part *temp = head;
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
    temp = head;
    return;
}

void printInitOrder(struct part *head)
{
    // part *temp = head;
    part *temp;
    int count = 1;
    printf("\n****** Intiative Order Start******\n\n");

    for(int i = initSpread; i > 0; i--){
        count = 1;
        temp = combatants[i];
        if(/*combatants[i] != NULL*/ temp != NULL){
            // printf("%i-%i. %s, AC: %i, HP: %i\n", combatants[i]->init, count, combatants[i]->name, combatants[i]->ac, combatants[i]->hp);
            // combatants[i]->initSpot = count;
            // count++;
            
            while(temp != NULL){                
                printf("%i-%i. %s, AC: %i, HP: %i\n", temp->init, count, temp->name, temp->ac, temp->hp);
                temp->initSpot = count;
                count++;     
                temp = temp->next;           
            }
        }
    }

    // for(int i = initSpread; i > 0; i--)
    // {
    //     count = 1;
    //     while (temp != NULL)
    //     {
    //         if (temp->init == i && temp->hp > 0) /* Does the given combatant's initiative match i? If yes, print */
    //         {
    //             printf("%i-%i. %s, AC: %i, HP: %i\n", temp->init, count, temp->name, temp->ac, temp->hp);
    //             temp->initSpot = count;
    //             count++;
    //         }
    //         temp = temp->next;
    //     }
    //     temp = head;
    // }
    printf("\n****** Intiative Order End ******\n");
    return;
}

void dealDamage(struct part *head, int init, int count, int amount)
{
    part *temp = head;
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