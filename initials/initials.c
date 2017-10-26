#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void) {

    string user = get_string();
    int nameLength = strlen(user);

    for(int i = 0; i < nameLength; i++) {
        if(i == 0) {
            //always print first initial(uppercase)
            printf("%c", toupper(user[i]));
        } else if(user[i] == ' ') {
            //if space, print the next char(uppercase)
            printf("%c", toupper(user[i + 1]));
        }
    }
    //loop ends, print new line
     printf("\n");
}