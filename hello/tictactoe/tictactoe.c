#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// char *choices = "012345678";
int playerChoice = 0, comChoice = 0;
int position = 0, turns = 9;
int choices[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
char a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', k = '9', first = 'X', second = 'O';

void print_grid(void);
void printDivider(void);
int checkChoice(int a);
int computerChoice(void);
void assignChoice(int choice, char symbol);

int main(void)
{
    srand(time(0));
    printf("Welcome to Tic Tac Toe!\n");
    do
    {
        printf("Choose if you want to go first (1) or second (2): ");
        scanf("%i", &position);
    }
    while (position < 1 || position > 2);

    if (position == 1)
    {
        printf("You have chosen to go first! You are X's!\nHere is the current board:\n");
        printf("A number indicates an open position that can be played in\n");
    }
    else if (position == 2)
    {
        printf("You have chosen to go second! You are O's!\nHere is the current board:\n");
        printf("A number indicates an open position that can be played on.\n");
    }
    
    print_grid();

    while(turns > 0)
    {
        if (position == 1)
        {
            if (turns % 2 != 0)
            {
                printf("Enter your choice: ");
                scanf("%i", &playerChoice);
                if (checkChoice(playerChoice) == 0)
                {
                    assignChoice(playerChoice, first);
                    print_grid();
                    turns--;
                }
                else
                {
                    printf("Invalid Choice\n");
                }
            }
            else
            {
                do
                {
                    comChoice = computerChoice();
                } while ( checkChoice(comChoice) == 1);
                assignChoice(comChoice, second);
                print_grid();
                turns--;
            }
        }
        else if(position == 2)
        {
            if (turns % 2 == 0)
            {
                printf("Enter your choice: ");
                scanf("%i", &playerChoice);
                if (checkChoice(playerChoice) == 0)
                {
                    assignChoice(playerChoice, first);
                    print_grid();
                    turns--;
                }
                else
                {
                    printf("Invalid Choice\n");
                }
            }
            else
            {
                do
                {
                    comChoice = computerChoice();
                } while ( checkChoice(comChoice) == 1);
                assignChoice(comChoice, second);
                print_grid();
                turns--;
            }
        }
        else
        {
            return 1;
        }        
    }
}

void print_grid(void)
{
    printf(" %c | %c | %c\n", a, b, c);
    printDivider();
    printf(" %c | %c | %c\n", d, e, f);
    printDivider();
    printf(" %c | %c | %c\n", g, h, k);
}

void printDivider(void)
{
    printf("-----------\n");
}

int checkChoice(int a)
{
    for(int i = 0; i < 9; i++)
    {
        if (a > 9 || a < 1)
        {
            return 1;
        }
        else if (a == choices[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int computerChoice(void)
{
    int lower = 0, upper = 8, count = 1;
    int num;
    num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void assignChoice(int choice, char symbol)
{
    if (choice == 1)
    {
        a = symbol;
    }
    else if (choice == 2)
    {
        b = symbol;
    }
    else if (choice == 3)
    {
        c = symbol;
    }
    else if (choice == 4)
    {
        d = symbol;
    }
    else if (choice == 5)
    {
        e = symbol;
    }
    else if (choice == 6)
    {
        f = symbol;
    }
    else if (choice == 7)
    {
        g = symbol;
    }
    else if (choice == 8)
    {
        h = symbol;
    }
    else if (choice == 9)
    {
        k = symbol;
    }
}
