#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void) {

    string user = get_string();
    char userFirstInitial = user[0];

    printf("%c\n", userFirstInitial);
}