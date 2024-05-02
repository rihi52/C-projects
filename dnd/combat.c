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

/* Orc Enemies */
part orc = {"Frost Giant", false, 0, 13, 15, NULL};

/* Orog Enemies */
part orog = {"Mercenary", false, 0, 18, 53, &orc};

/* Magmin Enemies */
part magmin = {"Wolf", false, 0, 15, 9, &orog};

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

/* Function Prototypes*/
void setInitiative(struct part *person, int size);
void printInitOrder(struct part *head);
part *createNode(struct part *enemy);

int main(void)
{
    int numOrc = 0, numOrog = 0, numMagmin = 0, numPlayer = 4, numGiant = 2;

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

part *createNode(struct part *enemy)
{
    part *new = malloc(sizeof(part));
    if (new == NULL){
        return NULL;
    }

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
