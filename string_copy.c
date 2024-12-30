#include <stdio.h>
#include <stdlib.h>

// function to find the length of a string
int string_length(char *str)
{
    // create a pointer to the beginning of the string
    char *p = str;

    // loop until we reach the null terminator
    while (*p != '\0')
    {
        // move the pointer to the next character
        p++;
    }

    // return the number of characters we traversed
    return p - str;
}

// function to copy a string to another string
void string_copy(char *dest, char *src)
{
    // create pointers to the beginning of the source and destination strings
    char *p = src;
    char *q = dest;

    // loop until we reach the null terminator in the source string
    while (*p != '\0')
    {
        // copy the character from the source string to the destination string
        *q = *p;

        // move the pointers to the next characters
        p++;
        q++;
    }

    // add the null terminator to the destination string
    *q = '\0';
}

int main()
{
    // create a source string and a destination string
    char *src = "follow vishesh on instagram @mrvisheshjat";
    char *dest = malloc(string_length(src) + 1);

    // copy the source string to the destination string
    string_copy(dest, src);

    // print the destination string
    printf("%s\n", dest);

    // free the memory used by the destination string
    free(dest);

    return 0;
}

