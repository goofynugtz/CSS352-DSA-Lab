#include <stdio.h>
#include <stdbool.h>
#define SIZE 5

/* 
Roll No: 20CS8016

Q2. Write a menu driven program in C to perform following 
data structure operations on circular queue using array. 
- ENQUEUE 
- DEQUEUE
- queueFRONT [Extract the information from FRONT of the queue]
- queueREAR [Extract the information from REAR of the queue]
- queueCOUNT [Return the number of elements in the queue]
- DISPLAY [Display all the elements stored in a queue]
*/

typedef struct queue {
  int front, rear;
  int size;
  int array[SIZE];
} queue;

queue q;

void createQueue (queue *q){
  q -> front = -1;
  q -> rear = -1;
  q -> size = 0;
}

bool isFull (queue *q){
  return ((q -> front == q -> rear + 1) || (q -> front == 0 && q -> rear == SIZE - 1));
}

bool isEmpty (queue *q){
  return (q -> front == -1);
}

int queueFront (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is Empty\n");
    return -1;
  }
  return q -> array[q -> front];
}

int queueRear (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is Empty\n");
    return -1;
  }
  return q -> array[q -> rear];
}

int queueCount (queue *q){
  return (q -> size);
}


void enqueue (queue *q, int value){

  if (isFull(q)){
    printf("Error: Overflow\n");
    return;
  }

  if (q -> front == -1) q -> front = 0;
  q -> rear = (q -> rear + 1) % SIZE;
  q -> size++;
  q -> array[q -> rear] = value;
}


void enqueueMultiple (queue *q){
  if (isFull(q)){
    printf("Error: Queue is full.\n");
    return;
  }

  printf("Enter the number of elements to be enqueued: ");
  int x; scanf("%d", &x);

  if (x > SIZE - queueCount(q)){
    printf("Not enough space available.\n");
    printf("Free Space: %d\n", SIZE - queueCount(q));
  } else {
    printf("Enter #values below\n");
    for (int i = 0; i < x; i++){
      int value; scanf("%d", &value);
      enqueue(q, value);
    }
  }
}


void dequeue (queue *q){
  if (isEmpty(q)){
    printf("Error: Queue is empty.\n");
    return;
  }

  int value = queueFront(q);
  if (q -> front == q -> rear){
    q -> front = -1;
    q -> rear = -1;
    q -> size = 0;
  } else {
    q -> front = (q -> front + 1) % SIZE;
    q -> size--;
  }
  printf(">> %d has been removed\n", value);
}



void displayQueue (queue *q){\

  int i;
  printf("Queue: ");
  for (i = q -> front; i != q -> rear; i = (i+1) % SIZE){
    printf("%d ", q -> array[i]);
  }
  printf("%d ", q -> array[i]);
  printf("\n");
}


int main (){

  createQueue(&q);

  printf("\n");
  printf("1: Insert / Enqueue\n");
  printf("2: Insert / Enqueue multiple elements\n");
  printf("3: Delete / Dequeue\n");
  printf("4: Front of Queue\n");
  printf("5: Rear of Queue\n");
  printf("6: No. of elements in queue\n");
  printf("7: All elements of queue\n");
  printf("0: Exit Program\n");

  bool wantToExit = 0;

  while (!wantToExit){
    printf("\nChoose Option: ");

    int n; scanf("%d", &n);

    int value;

    switch (n){
      case 1:
        if (isFull(&q))
          printf("Error: Queue is full\n");
        else {
          printf("Enter #value to be pushed: ");
          scanf("%d", &value);
          enqueue(&q, value);
        }
        break;

      case 2:
        enqueueMultiple(&q);
        break;

      case 3:
        dequeue(&q);
        break;

      case 4:
        printf("Queue -> [Front]: ");
        printf("%d\n", queueFront(&q));
        break;

      case 5:
        printf("Queue -> [Rear]: ");
        printf("%d\n", queueRear(&q));
        break;

      case 6:
        printf("No. of items are: ");
        printf("%d\n", queueCount(&q));
        break;

      case 7:
        if (isEmpty(&q))
          printf(">> Queue is Empty.\n");
        else 
          displayQueue(&q);
        break;

      default:
        wantToExit = true;
        break;
    }
  }

  return 0;
}