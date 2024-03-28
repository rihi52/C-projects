#include <stdio.h>
#include <math.h>

int choices[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
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
            scanf("%i", &choices[i][j]);
            print_grid();
        }
    }
}

void print_grid(void)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf(" %i ", choices[i][j]);
            if (j < 2)
            {
                printf("|");
            }
            else
            {
                printf("\n");
            }
        }
        if (i < 2)
        {
            printDivider();
        }
    }
    
}

void printDivider(void)
{
    printf("-----------\n");
}