#include <stdio.h>
#include <stdlib.h>
struct node {
   int info;
   struct node *link;
};

typedef struct node NODE;
NODE *insert_start(int x, NODE *first);
NODE *delete_start(NODE *first);
void display(NODE *first);
void main() {

   int x, choice;
   NODE *first = NULL;

   while (1) { 
      printf("\n 1 for INSERT \n 2 for DELETE \n 3 for DISPLAY \n 4 for EXIT \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
            printf("Enter a value: ");
            scanf("%d", &x);
            first = insert_start(x, first);
            break;
         case 2:
            first = delete_start(first);
            break;
         case 3:
            display(first);
            break;
         case 4:
            exit(0);
         default:
            printf("Invalid Choice...!!!\n");
      }
   }
}

NODE *insert_start(int x, NODE *first) {
   NODE *NEW;
   NEW = (NODE *)malloc(sizeof(NODE));

   if (NEW == NULL) {
      printf("Available list is empty");
      return first;
   }

   NEW->info = x;
   NEW->link = first;

   return NEW;
}
NODE *delete_start(NODE *first) {
   NODE *old;
   if (first == NULL) {
      printf("List is empty\n");
      return first;
   }

   old = first;

   if (first->link == NULL) {
      first = NULL;
   }
   else {
      first = first->link;
   }

   free(old);

   return first;
}

void display(NODE *first) {
   NODE *save = first;

   printf("\nList Members>>>>");
   while (save != NULL) {
      printf("%d\t", save->info);
      save = save->link;
   }
}