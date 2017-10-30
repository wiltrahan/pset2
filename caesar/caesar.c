#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {
    if(argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    //Argv[1] is taken from command line as string.
    //Then is converted into int so can be used as key.
    string k = argv[1];
    int caesar = atoi(k);
    char space = ' ';
    char comma = ',';

    printf("plaintext: ");
    string plainText = get_string();

    printf("ciphertext: ");

    for(int i = 0, stringLen = strlen(plainText); i < stringLen; i++) {

        //If what was entered is a-z or A-Z:
        if(isalpha(plainText[i])) {
            //If what was entered is a-z:
            if(islower(plainText[i])) {
                char lowCaesar = (((plainText[i] - 97 + caesar) % 26) + 97);
                //Start with plain text corresponding ascii value.
                //Subtract 97..add caesar value..mod by 26..re-add 97.
                //BAM ---CAESAR CIPHERED!
                    printf("%c", lowCaesar);
            }
            //if what was entered is A-Z
            if(isupper(plainText[i])) {
                //Same as lower case but subtract & add 65.
                char upCaesar = (((plainText[i] - 65 + caesar) % 26) + 65);
                printf("%c", upCaesar);
            }
        }
        //Print space if there is one in entered string.
        else if(plainText[i] == ' ') {
            printf("%c", space);
        }
        //Print comma if there is one in entered string.
        else if(plainText[i] == ',') {
            printf("%c", comma);
        }
    }
    printf("\n");
    return 0;
}


