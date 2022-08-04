#include <stdio.h>
#define MAX 5

struct item
{
    int value;
    int priority;
};
struct item pr[MAX];
int rear = -1;

int isEmpty()
{
    return rear == -1 ? 1 : 0;
}

int isFull()
{
    return rear == (MAX - 1) ? 1 : 0;
}

int getHighestPriority()
{
    int i, p = -1;
    if (!isEmpty())
    {
        for (i = 0; i <= rear; i++)
        {
            if (pr[i].priority > p)
                p = pr[i].priority;
        }
    }
    return p;
}

void enqueue(int v, int p)
{
    rear++;
    pr[rear].value = v;
    pr[rear].priority = p;
}

void dequeue()
{
    if (isEmpty())
        printf("Priority QUEUE is empty.\n");
    else
    {
        int i, j, p, ele;
        p = getHighestPriority();
        for (i = 0; i <= rear; i++)
        {
            if (pr[i].priority == p)
            {
                ele = pr[i].value;
                break;
            }
        }
        if (i < rear)
        {
            for (j = i; j < rear; j++)
            {
                pr[j].value = pr[j + 1].value;
                pr[j].priority = pr[j + 1].priority;
            }
        }
        rear--;
        printf("%d is dequeued.\n", ele);
    }
}

void display()
{
    if (isEmpty())
        printf("Priority QUEUE is empty.\n");
    else
    {
        int i;
        printf("\nPriority QUEUE (value,priority) : [ ");
        for (i = 0; i <= rear; i++)
        {
            printf("(%d,%d) ", pr[i].value, pr[i].priority);
        }
        printf("]");
    }
}

void menu()
{
    printf("\n---------------------\n");
    printf("1. Enqueue data\n");
    printf("2. Dequeue data\n");
    printf("3. Display queue data\n");
    printf("4. Display hightest priority\n");
    printf("5. Exit menu\n");
    printf("\n---------------------\n");
}

int main()
{
    int exit = 1, v, p;
    while (exit != 5)
    {
        menu();
        printf("Enter menu option : ");
        scanf("%d", &exit);
        switch (exit)
        {
        case 1:
            if (isFull())
            {
                printf("Priority QUEUE is full.\n");
            }
            else
            {
                printf("Enter value to enqueue : ");
                scanf("%d", &v);
                printf("Enter priority : ");
                scanf("%d", &p);
                enqueue(v, p);
            }
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            if (isEmpty())
                printf("Priority QUEUE is empty.\n");
            else
                printf("Highest Priority is %d.\n", getHighestPriority());

            break;
        case 5:
        default:
            exit = 5;
            printf("\n------MENU EXIT------\n");
            break;
        }
    }
    return 0;
}
