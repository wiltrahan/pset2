#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]) {

    if(argc != 2) {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string k = argv[1];

    printf("plaintext: ");
    string plainText = get_string();

    printf("ciphertext: ");

    for(int i = 0, stringLen = strlen(plainText); i < stringLen; i++) {

        if(isalpha(plainText[i])) {
            if(islower(plainText[i])) {
                // char lowVig = (k[i] - 97) + (plainText[i]);
                char lowVig = (((plainText[i] - 97) + (k[i] - 97)) % 27) + 97;
                //(14 + 13 = 27 mod 26 = 1) + 96 = 97
                printf("%c", lowVig);
            }

            if(isupper(plainText[i])) {
                char highVig = (((plainText[i] - 65 + k[i] - 65) % 26) + 65);
                printf("%c", highVig);
            }
        }
    }
    printf("\n");
    return 0;
}