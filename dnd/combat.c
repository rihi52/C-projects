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
    int turnCount;
    int ac;
    int hp;
    struct part *next;
}part;

/***** Combatants *****/
/* To add more enemies, create a new part struct and point orc to it*/

/* Orc Enemies */
part orc = {"Orc", false, 0, 0, 13, 15, NULL};

/* Orog Enemies */
part orog = {"Orog", false, 0, 0, 18, 53, &orc};

/* Magmin Enemies */
part magmin = {"Magmin", false, 0, 0, 15, 9, &orog};

/* Linked list of unique part stats */
part ildmane = {"ildmane", true, 0, 0, 18, 162, &magmin};
part okssort = {"okssort", true, 0, 0, 17, 162, &ildmane};

/* Linked list of player stats */
part theon = {"theon", true, 0, 0,16, 55, &okssort};
part pax = {"pax", true, 0, 0, 16, 57, &theon};
part finn = {"finn", true, 0, 0, 15, 36, &pax};
part ravi = {"ravi", true, 0, 0, 16, 34, &finn};

/* Global Variables*/
int initSpread = 30;
int currentInit = 0;
int roundCount = 0;

/* Function Prototypes*/
void setInitiative(struct part *person, int size);
void printCurrentTurn(struct part *head);
void printInitOrder(struct part *head);
part *createNode(struct part *enemy);
void dealDamage(struct part *head, int init, int count, int amount);

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
    
    /* Assign player and unique initiative */
    setInitiative(&ravi, numPlayer);

    part *newEnemy;
    
    /* part count */
    printf("How many %s: ", orc.name);
    scanf("%i", &numOrc);
   
    printf("How many %s: ", orog.name);
    scanf("%i", &numOrog);

    printf("How many %s: ", magmin.name);
    scanf("%i", &numMagmin);

    /* Assign Enemy Initiative */
    printf("%s's initiative: ", orc.name);
    scanf("%i", &orc.init);

    for(int i = 0; i < numOrc - 1; i++)
    {
        if(numOrc <= 1)
        {
            break;
        }
        newEnemy = createNode(&orc);
        tail->next = newEnemy;
        tail = newEnemy;
    }

    printf("%s's initiative: ", orog.name);
    scanf("%i", &orog.init);

    for(int i = 0; i < numOrog - 1; i++)
    {
        if(numOrog <= 1)
        {
            break;
        }
        newEnemy = createNode(&orog);
        tail->next = newEnemy;
        tail = newEnemy;
    }

    printf("%s's initiative: ", magmin.name);
    scanf("%i", &magmin.init);
    
    for(int i = 0; i < numMagmin - 1; i++)
    {
        if(numMagmin <= 1)
        {
            break;
        }
        newEnemy = createNode(&magmin);
        tail->next = newEnemy;
        tail = newEnemy;
    }

    printInitOrder(head);
    printCurrentTurn(head);

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
            roundCount++;
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
        scanf("%i", &current->init);
        current = current->next;
    }
    return;
}

part *createNode(struct part *enemy)
{
    part *new = malloc(sizeof(part));
    if (new == NULL){
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
    }
    else if(enemy == &magmin)
    {
        new->name = magmin.name;
        new->uniqueChar = magmin.uniqueChar;
        new->ac = magmin.ac;
        new->hp = magmin.hp;
        new->init = magmin.init;        
        new->next = NULL;
    }
    return new;
}

void printCurrentTurn(struct part *head)
{
    part *temp = head;

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
                currentInit = temp->init;
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
    part *temp = head;
    int count = 1;
    printf("\n****** Intiative Order Start******\n\n");

    for(int i = initSpread; i > 0; i--)
    {
        count = 1;
        while (temp != NULL)
        {
            if (temp->init == i && temp->hp > 0)
            {
                printf("%i-%i. %s, AC: %i, HP: %i\n", temp->init, count, temp->name, temp->ac, temp->hp);
                temp->turnCount = count;
                count++;
            }
            temp = temp->next;
        }
        temp = head;
    }
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