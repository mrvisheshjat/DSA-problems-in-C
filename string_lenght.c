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

int main()
{
    // create a string
    char *str = "Vishesh is GREAT";

    // find the length of the string
    int length = string_length(str);

    // print the length of the string
    printf("%d\n", length);

    return 0;
}
