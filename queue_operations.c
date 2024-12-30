#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct {
  int *items;  // array to store queue items
  int front;   // front position
  int rear;    // rear position
  int size;    // current queue size
  int capacity;  // maximum capacity of the queue
} Queue;

// function to create a queue of given capacity
Queue *createQueue(int capacity) {
  Queue *q = (Queue*)malloc(sizeof(Queue));
  q->capacity = capacity;
  q->front = q->size = 0;
  q->rear = capacity - 1;  // rear position is initialized to capacity - 1
  q->items = (int*)malloc(capacity * sizeof(int));
  return q;
}

// function to check if the queue is full
int isFull(Queue *q) {
  return (q->size == q->capacity);
}

// function to check if the queue is empty
int isEmpty(Queue *q) {
  return (q->size == 0);
}

// function to insert an item to the queue
void enqueue(Queue *q, int item) {
  if (isFull(q))
    return;
  q->rear = (q->rear + 1) % q->capacity;  // increase rear position and wrap around if necessary
  q->items[q->rear] = item;
  q->size++;
}

// function to remove an item from the queue
int dequeue(Queue *q) {
  if (isEmpty(q))
    return -1;
  int item = q->items[q->front];
  q->front = (q->front + 1) % q->capacity;  // increase front position and wrap around if necessary
  q->size--;
  return item;
}

// function to get the front item in the queue
int front(Queue *q) {
  if (isEmpty(q))
    return -1;
  return q->items[q->front];
}

// function to get the rear item in the queue
int rear(Queue *q) {
  if (isEmpty(q))
    return -1;
  return q->items[q->rear];
}

// function to display the queue
void displayQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Queue items: ");
  for (int i = q->front; i <= q->rear; i++)
    printf("%d ", q->items[i]);
  printf("\n");
}

int main() {
  Queue *q = createQueue(QUEUE_SIZE);

  int choice;
  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert an item\n");
    printf("2. Delete an item\n");
    printf("3. Display the queue\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
     case 1:
       printf("Enter the item to insert: ");
       int item;
       scanf("%d", &item);
       enqueue(q, item);
       break;
     case 2:
       item = dequeue(q);
       if (item == -1)
         printf("Queue is empty\n");
       else
         printf("Deleted item: %d\n", item);
       break;
     case 3:
       displayQueue(q);
       break;
     case 4:
       exit(0);
       break;
     default:
       printf("Invalid choice\n");
   }
  }
  return 0;
}
