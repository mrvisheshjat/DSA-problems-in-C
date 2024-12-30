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

// function to reverse a string
char *string_reverse(char *str)
{
    // find the length of the string
    int length = string_length(str);

    // allocate memory for the reversed string
    char *reverse = malloc(length + 1);

    // create pointers to the beginning and end of the strings
    char *p = str;
    char *q = str + length - 1;
    char *r = reverse;

    // copy the characters from the string to the reversed string in reverse order
    while (q >= p)
    {
        *r = *q;
        q--;
        r++;
    }

    // add the null terminator to the reversed string
    *r = '\0';

    // return the reversed string
    return reverse;
}

int main()
{
    // create a string
    char *str = "Hello, world!";

    // reverse the string
    char *reverse = string_reverse(str);

    // print the reversed string
    printf("%s\n", reverse);

    // free the memory used by the reversed string
    free(reverse);

    return 0;
}
