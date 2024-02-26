#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define STD_DICE 2
#define STD_SIDES 6

int F_MainMenu(){

    system("clear");
    int F_Opt;
    do{

        printf("\n_________________________\n");
        printf("--Roller Dice Simulator--\n\n");
        printf("[1]...Roll Dices(default)\n");
        printf("[2].......Customize Dices\n");
        printf("[3]...........Flip a coin\n");
        printf("[0]..................Exit\n");

        printf("\nSelect a option: ");
        scanf("%d", &F_Opt);

        if(F_Opt < 0 || F_Opt > 3){
            system("clear");
            printf("\nInvalid option, please, try again!");
        }

    }while((F_Opt < 0 || F_Opt > 3) && F_Opt != 0);

    return F_Opt;
}
void F_CustomizeGame(int *Dices, int *Sides){

    do{
        printf("\nHow many sides should the dice have: ");
        scanf("%d", Sides);
        if(*Sides < 4){
            printf("The number of sides of the dice must be at least four!\n");
        }
    }while(*Sides < 4);

    do{
        printf("How many dice do you want to roll: ");
        scanf("%d", Dices);
        if(*Dices < 1){
            printf("Impossible to roll something you don't have!\n");
        }
    }while(*Dices < 1);

    printf("\n");
    system("clear");
}
void F_RollDice(int Dices, int Sides){

    int Tot_Points = 0, Steps = 0;

    setbuf(stdin, NULL);

    char F_Opt = 'y';
    do{
        Steps++;
        printf("\n%dº Play\n----------------------------------\n", Steps);
        for(int i = 0; i < Dices; i++){
            int Moves = (rand() % Sides) + 1;
            printf("%dº roll: %d\n", (i + 1), Moves);
            Tot_Points += Moves;
        }
        printf("Total of points: %d\n", Tot_Points);

        printf("\nPress 'y' to play again or any other \nkey to return to the main menu: ");
        F_Opt = getchar();
        getchar();
        Tot_Points = 0;

    }while(F_Opt == 'y' || F_Opt == 'Y');
    system("clear");
}
void F_FlipACoin(){

    setbuf(stdin, NULL);

    char F_Opt = 'y';
    int Coin, Moves = 0, CountHead = 0, CountTails = 0;

    do{

        Moves++;
        printf("\n%dº Play\n----------------------------------\n", Moves);
        Coin = rand() % 9;
        if(Coin >= 0 && Coin <=4){
            printf("\nResult: HEAD!\n");
            CountHead++;
        }
        if(Coin >= 5 && Coin <= 9){
            printf("\nResult: TAILS!\n");
            CountTails++;
        }

        printf("\nPress 'y' to play again, 'r' to see \nthe result or some other key to \nreturn to the main menu: ");
        F_Opt = getchar();
        getchar();

        if(F_Opt == 'r' || F_Opt == 'R'){
            printf("\nMoves: %d\n", Moves);
            printf("Head: %d\n", CountHead);
            printf("Tails: %d\n", CountTails);
            printf("\nPress y to play again, or some other \nkey to return to the main menu: ");
            F_Opt = getchar();
            getchar();
        }

    }while(F_Opt == 'y' || F_Opt == 'Y');

}

int main(){

    srand(time(NULL));

    int Qty_Dices, Num_Sides, Opt;

    do{
        
        Opt = F_MainMenu();

        switch(Opt){
            case 1:
                F_RollDice(STD_DICE, STD_SIDES);
            break;
            case 2:
                F_CustomizeGame(&Qty_Dices, &Num_Sides);
                F_RollDice(Qty_Dices, Num_Sides);
            break;
            case 3:
                F_FlipACoin();
            break;
        }
        
    }while(Opt != 0);

    return 0;
}
