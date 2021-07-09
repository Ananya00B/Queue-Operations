#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

typedef struct Queues{
    int arr[SIZE];
    int rear;
    int front;
} Queue;

Queue queue;
void Enqueue();
void Dequeue();
void Display_Q();

int main()
{
    int operation;
    queue.rear = -1;
    queue.front = -1;

    printf ("Enter one of following operations to perform queue operations :\n");
    printf("\t 1. ENQUEUE\n");
    printf("\t 2. DEQUEUE\n");
    printf("\t 3. DISPLAY QUEUE\n");
    printf("\t 4. EXIT\n");
    while(1)
      {
        printf("\nChoose an operation : ");
        scanf("%d", &operation);
        switch (operation)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                Display_Q();
                break;
            case 4:
                printf("Thank You!!");
                exit(1);
            default:
                printf("Invalid operation \n");
        }
      }
      return 0;

}

void Enqueue()
{
    int item;

    printf ("Enter an element to be enqueued : ");
    scanf ("%d", &item);

    if(queue.rear == -1)
    {
        queue.rear = queue.front = 0;
        queue.arr[queue.rear] = item;
        printf("Element %d has been inserted successfully.\n", item);
    }
    else if(queue.rear == SIZE-1)
    {
        printf("Queue is already full can't add more items.\n");
    }
    else
    {
        queue.rear++;
        queue.arr[queue.rear] = item;
        printf("Element %d has been inserted successfully.\n", item);
    }
}

void Dequeue()
{
    int dequeueItem;
    if(queue.front  ==  -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        if(queue.front == queue.rear)
        {
            dequeueItem = queue.arr[queue.front];
            queue.front = queue.rear = -1;
        }
        else
        {
            dequeueItem = queue.arr[queue.front];
            queue.front++;
        }
        printf("Element %d has been dequeued.\n",dequeueItem);
    }
}
void Display_Q()
{
    int i;
    if(queue.front == -1)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        printf("Elements :\n");

        for(i = queue.front; i <= queue.rear; i++)
        {
            printf("\t%d\n",queue.arr[i]);
        }
    }
}
