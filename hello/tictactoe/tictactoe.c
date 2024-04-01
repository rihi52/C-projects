#include <stdio.h>
#include <math.h>

char *choices = "012345678";
char choice;
int position, turns;

void print_grid(void);
void printDivider(void);

int main(void)
{
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose if you want to go first (1) or second (2): ");
    scanf("%i", &position);

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

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("Enter your choice: ");
            scanf("%c", &choices[i]);
            print_grid();
        }
    }
}

void print_grid(void)
{
    for(int i = 0; i < 3; i++)
    {
        if (i < 2 || (i > 2 && i < 5) || (i < 8 && i > 5))
        {
            printf("|");
        }
        else if (i == 2 || i == 5)
        {
            printf("\n");
            printDivider();
            printf("\n");
        }
        else if (i == 8)
        {
            printf("\n");
        }
    }
    
}

void printDivider(void)
{
    printf("-----------\n");
}