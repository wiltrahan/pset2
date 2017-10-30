#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[]) {

    if(argc != 2) {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    string k = argv[1];
    int caesar = atoi(k);
    char space = ' ';

    printf("plaintext: ");
    string plainText = get_string();

    printf("ciphertext: ");

    for(int i = 0, stringLen = strlen(plainText); i < stringLen; i++) {

        if(isalpha(plainText[i])) {
            if(islower(plainText[i])) {
                int lowCaesar = (((plainText[i] - 97 + caesar) % 26) + 97);
                // caesar = (p + k) % 26
                    printf("%c", lowCaesar);
            }

            if(isupper(plainText[i])) {
                int upCaesar = (((plainText[i] - 65 + caesar) % 26) + 65);
                printf("%c", upCaesar);
            }
        }
        else if(plainText[i] == ' ') {
            printf("%c", space);
        }
    }
    printf("\n");
}


