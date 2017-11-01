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
    //check to make sure each char is a letter
    for(int i = 0, len = strlen(k); i < len; i++) {
        if(isalpha(k[i]) == false) {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
    }

    printf("plaintext: ");
    string plainText = get_string();

    printf("ciphertext: ");

    int keyPosition;
    int keySize = 0;

    for(int i = 0, stringLen = strlen(plainText); i < stringLen; i++) {

        //starts key at first keyPosition (0), adds 1 each time through loop
        //keyPostion = size mod length..first time 0, second 1, third 2, etc..
        keyPosition = keySize % strlen(k);

        if(isalpha(plainText[i])) {
            if(islower(plainText[i])) {
                char lowVig = (((plainText[i] - 97) + (tolower(k[keyPosition]) - 97)) % 26) + 97;

                printf("%c", lowVig);
            }

            if(isupper(plainText[i])) {
                char highVig = (((plainText[i] - 65) + (tolower(k[keyPosition]) - 97)) % 26) + 65;
                printf("%c", highVig);
            }

            keySize++;
        }


        else {
            printf("%c", plainText[i]);
        }

    }
    printf("\n");
    return 0;
}
