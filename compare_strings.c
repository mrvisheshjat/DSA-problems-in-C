#include <stdio.h>
#include <stdlib.h>

// function to compare two strings
int string_compare(char *str1, char *str2)
{
    // create pointers to the beginning of the strings
    char *p = str1;
    char *q = str2;

    // loop until we reach the null terminator in one of the strings
    while (*p != '\0' && *q != '\0')
    {
        // if the characters are different, return the difference
        if (*p != *q)
        {
            return *p - *q;
        }

        // move the pointers to the next characters
        p++;
        q++;
    }

    // if we reached the end of one string before the other, return the difference
    if (*p == '\0' && *q != '\0')
    {
        return -*q;
    }
    else if (*p != '\0' && *q == '\0')
    {
        return *p;
    }

    // if the strings are equal, return 0
    return 0;
}

int main()
{
    // create two strings
    char *str1 = "Hello, world!";
    char *str2 = "Hello, world!";

    // compare the strings
    int result = string_compare(str1, str2);

    // print the result of the comparison
    printf("%d\n", result);

    return 0;
}
