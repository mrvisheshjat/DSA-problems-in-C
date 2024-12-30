#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

// function to convert a string to uppercase
char *string_to_upper(char *str)
{
    // find the length of the string
    int length = string_length(str);

    // allocate memory for the uppercase string
    char *upper = malloc(length + 1);

    // create a pointer to the beginning of the string
    char *p = str;
    char *q = upper;

    // convert the characters to uppercase and copy them to the uppercase string
    while (*p != '\0')
    {
        *q = toupper(*p);
        p++;
        q++;
    }

    // add the null terminator to the uppercase string
    *q = '\0';

    // return the uppercase string
    return upper;
}

// function to convert a string to lowercase
char *string_to_lower(char *str)
{
    // find the length of the string
    int length = string_length(str);

    // allocate memory for the lowercase string
    char *lower = malloc(length + 1);

    // create a pointer to the beginning of the string
    char *p = str;
    char *q = lower;

    // convert the characters to lowercase and copy them to the lowercase string
    while (*p != '\0')
    {
        *q = tolower(*p);
        p++;
        q++;
    }

    // add the null terminator to the lowercase string
    *q = '\0';

    // return the lowercase string
    return lower;
}

int main()
{
    // create a string
    char *str = "Hello, world!";

    // convert the string to uppercase
    char *upper = string_to_upper(str);

    // print the uppercase string
    printf("%s\n", upper);

    // free the memory used by the uppercase string
    free(upper);

    // convert the string to lowercase
    char *lower = string_to_lower(str);

    // print the lowercase string
    printf("%s\n", lower);

    // free the memory used by the lowercase string
    free(lower);

    return 0;
}
