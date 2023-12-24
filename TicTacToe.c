#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char GameBoard[3][3];
int ItWon = 0, Moves;
char Player_1 = 'X';
char Player_2 = 'O';

void FInitializeBoard(char Board[3][3]);
void FShowBoard(char Board[3][3]);
int FCheckPosition(char Board[3][3], int i, int j);
int FCheckWinner(char Board[3][3], char Player, int Play);

int main(){

    char PlayAgain = 'n';
    do{
        FInitializeBoard(GameBoard);
        do{
            int i, j;
            FShowBoard(GameBoard);
            if(Moves%2 == 0){
                system("clear");
                FShowBoard(GameBoard);
                do{
                    printf("Player One [X]\n");
                    printf("Line: ");
                    scanf("%d", &i);
                    printf("Column: ");
                    scanf("%d", &j);
                }while(FCheckPosition(GameBoard, i, j) == 0);
                GameBoard[i][j] = 'X';
                ItWon = FCheckWinner(GameBoard, Player_1, Moves);
            }else{
                system("clear");
                FShowBoard(GameBoard);
                do{
                    printf("Player Two [O]\n");
                    printf("Line: ");
                    scanf("%d", &i);
                    printf("Column: ");
                    scanf("%d", &j);
                }while(FCheckPosition(GameBoard, i, j) == 0);
                GameBoard[i][j] = 'O';
                ItWon = FCheckWinner(GameBoard, Player_2, Moves);
            }
            Moves++;
            if(Moves == 9){
                system("clear");
                FShowBoard(GameBoard);
                printf("It seems like no one won!\n");
            }
        }while(Moves < 9 && ItWon == 0);

        setbuf(stdin, NULL);
        printf("Play again [Y/N]? ");
        PlayAgain = getchar();
        PlayAgain = toupper(PlayAgain);
        getchar();

    }while(PlayAgain == 'Y');

    return 0;
}

void FInitializeBoard(char Board[3][3]){
    ItWon = 0;
    Moves = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Board[i][j] = ' ';
        }
    }
}

void FShowBoard(char Board[3][3]){
    printf("\t=====Tic Tac Toe====\n");
    printf("\tLC  0     1     2\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){
                printf("\t%d   %c  |", i, Board[i][j]);
            }else if(j == 1){
                printf("  %c  |", Board[i][j]);
            }else{
                printf("  %c  ", Board[i][j]);
            }
        }
        if(i != 2){
            printf("\n\t -------------------\n");
        }else{
            printf("\n\n");
        }
    }
}

int FCheckPosition(char Board[3][3], int i, int j){
    if(Board[i][j] != ' '){
        printf("Invalid position! Try again.\n");
        return 0;
    }else{
        return 1;
    }
}

int FCheckWinner(char Board[3][3], char Player, int Play){
    int flag = 0;
    if(Board[0][0] == Player && Board[0][1] == Player && Board[0][2] == Player ||
        Board[1][0] == Player && Board[1][1] == Player && Board[1][2] == Player ||
        Board[2][0] == Player && Board[2][1] == Player && Board[2][2] == Player){

        flag = 1;
    }else if(Board[0][0] == Player && Board[1][0] == Player && Board[2][0] == Player ||
        Board[0][1] == Player && Board[1][1] == Player && Board[2][1] == Player ||
        Board[0][2] == Player && Board[1][2] == Player && Board[2][2] == Player){

        flag = 1;
    }else if(Board[0][0] == Player && Board[1][1] == Player && Board[2][2] == Player || 
    Board[0][2] == Player && Board[1][1] == Player && Board[2][0] == Player){

        flag = 1;
    }

    if(Play%2 == 0){
        if(flag == 1){
            system("clear");
            FShowBoard(Board);
            printf("Congratulations, player one won!\n");
        }
    }else{
        if(flag == 1){
            system("clear");
            FShowBoard(Board);
            printf("Congratulations, player two won!\n");
        }
    }
    return flag;
}
