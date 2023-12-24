/*Codeland Username Validation
Have the function CodelandUsernameValidation(str) take the str parameter being passed 
and determine if the string is a valid username according to the following rules:

1. The username is between 4 and 25 characters.
2. It must start with a letter.
3. It can only contain letters, numbers, and the underscore character.
4. It cannot end with an underscore character.

If the username is valid then your program should return the string true, otherwise 
return the string false.

https://coderbyte.com/editor/Codeland%20Username%20Validation:C */

#include <stdio.h>
#include <stdalign.h>
#include <string.h>

char * CodelandUsernameValidation(char User[]){

    User[strcspn(User, "\n")] = '\0';
    int flag = 0;

    // Check if the 'User' has between 4 and 25 characters
    if (!(strlen(User) >= 4 && strlen(User) <= 25))
    {
        flag++;
    }

    // Checks if the first character of 'User' is a letter
    if (!((User[0] >= 'a' && User[0] <= 'z') || (User[0] >= 'A' && User[0] <= 'Z')))
    {
        flag++;
    }

    // Checks if the user is made up of only letters, numbers and the underscore character
    for (int i = 0; User[i] != '\0'; i++)
    {
        if (!((User[i] >= 65 && User[i] <= 90) || (User[i] >= 97 && User[i] <= 122) ||
              (User[i] >= 48 && User[i] <= 57) || (User[i] == 95)))
        {
            flag++;
        }
    }

    //Checks if the last character of User ends with the underscore character
    if (User[strlen(User) - 1] == 95)
    {
        flag++;
    }

    //If successful, the flag variable is not incremented and then 'true' is returned.
    if (flag == 0)
    {
        return "true";
    }
    else
    {
        return "false";
    }
}

int main()
{

    char UserName[30];

    printf("User name: ");
    fgets(UserName, 30, stdin);

    printf("Status: %s.\n", CodelandUsernameValidation(UserName));

    return 0;
}