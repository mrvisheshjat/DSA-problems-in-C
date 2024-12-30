#include <stdio.h>

// function to calculate the GCD of two numbers
int gcd(int a, int b)
{
    // base case: if b is 0, the GCD is a
    if (b == 0)
    {
        return a;
    }
    // recursive case: calculate the GCD of b and the remainder of a divided by b
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    // prompt the user for two numbers
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // calculate the GCD of the two numbers
    int gcd_value = gcd(a, b);

    // print the result
    printf("GCD of %d and %d is %d\n", a, b, gcd_value);

    return 0;
}
