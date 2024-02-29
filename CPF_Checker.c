#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int F_CPFChecker(char F_cpf[]);

int main(){

    char CPF[12];

    printf("Enter the CPF to be consulted: ");
    fgets(CPF, sizeof(CPF), stdin);

    if(F_CPFChecker(CPF)){
        printf("\nThe CPF %s is VALID.\n", CPF);
    }else{
        printf("\nThe CPF %s is INVALID.\n", CPF);
    }

    return 0;
}

int F_CPFChecker(char F_cpf[]){

    int flag, result[10], first_digit = 0, second_digit = 0;

    F_cpf[strcspn(F_cpf, "\n")] = '\0';

    //Block responsible for removing the characters 
    //that separate numbers if any have been entered 
    //by the user
    char swap;
    for(int i = 0; i < (strlen(F_cpf)); i++){
        for(int j = i+1; j <= strlen(F_cpf); j++){
            if(F_cpf[i] < 48 || F_cpf[i] > 57){
                swap = F_cpf[i];
                F_cpf[i] = F_cpf[j];
                F_cpf[j] = swap;
            }
        }
    }

    //In this block the first check digit is obtained
    for(int i = 1; i <= 9; i++){
        result[i-1] = (F_cpf[i-1]-48)*i;
        first_digit += result[i-1];
    }
    first_digit = first_digit%11;
    if(first_digit >= 10){
        first_digit = 0;
    }

    //In this block the second check digit is obtained
    for(int i = 0; i <= 9; i++){
        result[i] = (F_cpf[i]-48)*i;
        second_digit += result[i];
    }
    second_digit = second_digit%11;
    if(second_digit >= 10){
        second_digit = 0;
    }

    //Check whether the check digit values match the values entered
    if((F_cpf[9] - '0') == first_digit && (F_cpf[10] - '0') == second_digit){
        flag = 1;
    }else{
        flag = 0;
    }
    
    return flag;
}