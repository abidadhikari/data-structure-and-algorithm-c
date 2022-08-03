#include <stdio.h>
#define MAX 5
struct CQUEUE
{
    int front;
    int rear;
    int queue[MAX];
};

void enqueue(struct CQUEUE *q)
{
    if ((q->rear + 1) % MAX == q->front)
        printf("QUEUE is full.\n");
    else
    {
        q->rear = (q->rear + 1) % MAX;
        int temp;
        printf("Enter data : ");
        scanf("%d", &temp);
        q->queue[q->rear] = temp;
        printf("%d is queued.\n", temp);
    }
}

void dequeue(struct CQUEUE *q)
{
    if (q->front == q->rear)
        printf("QUEUE is empty.\n");
    else
    {
        q->front = (q->front + 1) % MAX;
        printf("%d is dequeued.\n", q->queue[q->front]);
    }
}

void display(struct CQUEUE *q)
{
    if (q->front == q->rear)
        printf("QUEUE is empty.\n");
    else
    {
        int i;
        for (i = q->front; i <= q->rear; i = (i + 1) % MAX)
        {
            printf("%d\t", q->queue[i]);
        }
    }
}

void menu()
{
    printf("\n---------------------\n");
    printf("1. Enqueue data\n");
    printf("2. Dequeue data\n");
    printf("3. Display queue data\n");
    printf("4. Exit menu\n");
    printf("\n---------------------\n");
}

int main()
{
    struct CQUEUE q;
    q.front = MAX - 1;
    q.rear = MAX - 1;
    int exit = 1;
    while (exit != 4)
    {
        menu();
        printf("Enter menu option : ");
        scanf("%d", &exit);
        switch (exit)
        {
        case 1:
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
        default:
            printf("\n------MENU EXIT------\n");
            exit = 4;
            break;
        }
    }

    return 0;
}
