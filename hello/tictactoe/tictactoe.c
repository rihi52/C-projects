#include <stdio.h>
#include <math.h>

char *choices = "012345678";
int choice;
int position, turns = 9;
char a = '0', b = '1', c = '2', d = '3', e = '4', f = '5', g = '6', h = '7', k = '8';

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

    while(turns > 0)
    {
        printf("Enter your choice: ");
        scanf("%i", &choice);
        if (choice == 0)
        {
            a = 'X';
        }
        else if (choice == 1)
        {
            b = 'X';
        }
        else if (choice == 2)
        {
            c = 'X';
        }
        else if (choice == 3)
        {
            d = 'X';
        }
        else if (choice == 4)
        {
            e = 'X';
        }
        else if (choice == 5)
        {
            f = 'X';
        }
        else if (choice == 7)
        {
            g = 'X';
        }
        else if (choice == 8)
        {
            h = 'X';
        }
        else if (choice == 9)
        {
            k = 'X';
        }
        else
        {
            printf("Choice not valid");
        }
        print_grid();
        turns--;
        
    }

    /*for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("Enter your choice: ");
            scanf("%c", &choices[i]);
            print_grid();
        }
    }*/
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