#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// char *choices = "012345678";
int playerChoice = 0, comChoice = 0;
int position = 0, turns = 8, row = 0, col = 0;
int choices[3][3]; //= {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
char a = '1', b = '2', c = '3', d = '4', e = '5', f = '6', g = '7', h = '8', k = '9', first = 'X', second = 'O';

void print_grid(void);
void printDivider(void);
int checkChoice(int a);
int checkPCChoice(int a);
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

    while(turns >= 0)
    {
        if (position == 1)
        {
            if (turns % 2 == 0)
            {
                do{
                printf("Enter your choice: ");
                scanf("%i", &playerChoice);
                } while (checkChoice(playerChoice) == 1);
                assignChoice(playerChoice, first);
                print_grid();
                //choices[row][col] = playerChoice;
                turns--;
                row++;
                col++;
            }
            else
            {
                do
                {
                    comChoice = computerChoice();
                } while ( checkPCChoice(comChoice) == 1);
                assignChoice(comChoice, second);
                //choices[row][col] = comChoice;
                print_grid();
                turns--;
                row++;
                col++;
            }
        }
        else if(position != 2)
        {
            if (turns % 2 == 0)
             {
                do{
                printf("Enter your choice: ");
                scanf("%i", &playerChoice);
                } while (checkChoice(playerChoice) == 1);
                assignChoice(playerChoice, first);
                print_grid();
                //choices[row][col] = playerChoice;
                turns--;
                row++;
                col++;
            }
            else
            {
                do
                {
                    comChoice = computerChoice();
                } while ( checkPCChoice(comChoice) == 1);
                assignChoice(comChoice, second);
                //choices[row][col] = comChoice;
                print_grid();
                turns--;
                row++;
                col++;
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
    printDivider();
    printf(" %c | %c | %c\n", a, b, c);
    printDivider();
    printf(" %c | %c | %c\n", d, e, f);
    printDivider();
    printf(" %c | %c | %c\n", g, h, k);
    printDivider();
}

void printDivider(void)
{
    printf("-----------\n");
}

int checkChoice(int a)
{
    int i, j;
    if (a < 1 || a > 9)
    {
        printf("less or greater\n");
        return 1;
    }
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (a == choices[i][j])
            {
                printf("Already Chosen\n");
                return 1;
            }
        }        
    }
    choices[i][j] = a;
    return 0;
}

int checkPCChoice(int a)
{
    int i, j;
    if (a < 1 || a > 9)
    {
        return 1;
    }
    for(i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (a == choices[i][j])
            {
                return 1;
            }
        }        
    }
    return 0;
}

int computerChoice(void)
{
    int lower = 1, upper = 9, count = 1;
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
