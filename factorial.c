#include <stdio.h>

// function to calculate the factorial of a given number
int factorial(int n)
{
    // base case: if n is 0, the factorial is 1
    if (n == 0)
    {
        return 1;
    }
    // recursive case: multiply n by the factorial of n - 1
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    // prompt the user for a number
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // calculate the factorial of the number
    int fact = factorial(n);

    // print the result
    printf("%d! = %d\n", n, fact);

    return 0;
}
