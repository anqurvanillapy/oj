/**
 *  189. Rotate Array
 *
 *  Write a function that takes a string as input and returns the string reversed.
 *  
 *  - Example:
 *      + Given s = "hello", return "olleh".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s);

int
main(int argc, char const *argv[])
{
    char *rev, str[] = "Hello,\nsucc!";
    rev = reverseString(str);
    printf("%s\n", rev);

    return 0;
}

/* === solution === */

char*
reverseString(char* s)
{
    int len = strlen(s), i, j = len - 1;
    char *rev = (char *)malloc((len + 1) * sizeof(char));

    for (i = 0; i < len; i++) {
        rev[i] = s[j];
        j--;
    }

    rev[len] = '\0';

    return rev;
}

/* === EOS === */
