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

// function to concatenate two strings
char *string_concat(char *str1, char *str2)
{
    // find the lengths of the strings
    int len1 = string_length(str1);
    int len2 = string_length(str2);

    // allocate memory for the concatenated string
    char *concat = malloc(len1 + len2 + 1);

    // create pointers to the beginning of the strings
    char *p = str1;
    char *q = str2;
    char *r = concat;

    // copy the characters from the first string to the concatenated string
    while (*p != '\0')
    {
        *r = *p;
        p++;
        r++;
    }

    // copy the characters from the second string to the concatenated string
    while (*q != '\0')
    {
        *r = *q;
        q++;
        r++;
    }

    // add the null terminator to the concatenated string
    *r = '\0';

    // return the concatenated string
    return concat;
}

int main()
{
    // create two strings
    char *str1 = "Hello, ";
    char *str2 = "world!";

    // concatenate the strings
    char *concat = string_concat(str1, str2);

    // print the concatenated string
    printf("%s\n", concat);

    // free the memory used by the concatenated string
    free(concat);

    return 0;
}
