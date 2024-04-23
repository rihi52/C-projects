#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
Program should take following arguments:
    1. which table to roll on
Program will then prompt how many times to roll
Return items
*/
/****** Fire Giant's Bag ******/
const char *fireBag[] = {"Ball", "Rock", "Gold"};

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Incorrect input format.\n");
        printf("Use: ./giantbag gianttype\n");
        return 0;
    }

    srand(time(0));

    char *giantType = argv[1];
    int length = strlen(giantType);

    return 0;
}