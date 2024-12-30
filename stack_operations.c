#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// stack data structure
struct stack
{
    int data[MAX_SIZE];
    int top;
};

// function to create an empty stack
struct stack *create_stack()
{
    // allocate memory for the stack
    struct stack *s = malloc(sizeof(struct stack));

    // set the top of the stack to -1
    s->top = -1;

    // return the stack
    return s;
}

// function to check if the stack is empty
int is_empty(struct stack *s)
{
    // if the top of the stack is -1, the stack is empty
    return s->top == -1;
}

// function to check if the stack is full
int is_full(struct stack *s)
{
    // if the top of the stack is at the maximum size, the stack is full
    return s->top == MAX_SIZE - 1;
}

// function to push an element onto the stack
void push(struct stack *s, int element)
{
    // if the stack is full, display an error message
    if (is_full(s))
    {
        printf("Error: Stack overflow\n");
    }
    else
    {
        // increment the top of the stack
        s->top++;

        // insert the element at the top of the stack
        s->data[s->top] = element;
    }
}

// function to pop an element from the stack
int pop(struct stack *s)
{
    // if the stack is empty, display an error message
    if (is_empty(s))
    {
        printf("Error: Stack underflow\n");
        return -1;
    }
    else
    {
        // save the element at the top of the stack
        int element = s->data[s->top];

        // decrement the top of the stack
        s->top--;

        // return the element
        return element;
    }
}

// function to display the elements of the stack
void display(struct stack *s)
{
    // if the stack is empty, display an error message
    if (is_empty(s))
    {
        printf("Error: Stack is empty\n");
    }
    else
    {
        printf("Stack: ");

        // create a pointer to the top of the stack
        int *p = s->data + s->top;

        // loop through the elements of the stack
        while (p >= s->data)
        {
            printf("%d ", *p);
            p--;
        }

        printf("\n");
    }
}

int main()
{
    // create a stack
    struct stack *s = create_stack();

    // display the menu
    printf("Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    int choice;
    do
    {
        // prompt the user for a choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // push
                {
                    // prompt the user for an element
                    int element;
                    printf("Enter an element: ");
                    scanf("%d", &element);

                    // push the element onto the stack
                    push(s, element);
                }
                break;
            case 2: // pop
                {
                    // pop an element from the stack
                    int element = pop(s);

                    // if the element is not -1, print it
                    if (element != -1)
                    {
                        printf("Popped element: %d\n", element);
                    }
                }
                break;
            case 3: // display
                {
                    // display the elements of the stack
                    display(s);
                }
                break;
            case 4: // exit
                {
                    // free the memory used by the stack
                    free(s);
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
        }

    } while (choice != 4);

    return 0;
}