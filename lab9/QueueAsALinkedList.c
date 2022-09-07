#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct QUEUE
{
    int data;
    struct QUEUE *next;
} node;

int isEmpty(node **s)
{
    if (*s == NULL)
        return 1;
    else
        return 0;
}

int isFull(node **s)
{
    node *temp = *s;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return (count == MAX) ? 1 : 0;
}

void ENQUEUE(node **s)
{
    node *temp;
    int num;
    printf("Enter data : ");
    scanf("%d", &num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    if (isEmpty(s))
        *s = temp;
    else
    {
        if (isFull(s))
            printf("Can't enqueue !!!. QUEUE full \n");
        else
        {
            temp->next = *s;
            *s = temp;
            printf("%d is added to the top of the queue\n", num);
        }
    }
}

void DEQUEUE(node **s)
{
    if (isEmpty(s))
        printf("Can't dequeue!!!. QUEUE empty \n");
    else
    {
        node *toDel, *temp;
        temp = *s;
        while (temp != NULL)
        {
            if (temp->next == NULL)
            {
                printf("%d is dequeued from the queue\n", temp->data);
                free(temp);
                *s = NULL;
                break;
            }
            else if ((temp->next)->next == NULL)
            {
                toDel = temp->next;
                temp->next = NULL;
                printf("%d is dequeued from the queue\n", toDel->data);
                free(toDel);
                break;
            }
            else
                temp = temp->next;
        }
    }
}

void display(node **s)
{
    if (isEmpty(s))
        printf("Can't dequeue!!!. QUEUE empty \n");
    else
    {
        node *temp = *s;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

void menu()
{
    printf("\n---------------------\n");
    printf("1. ENQUEUE data\n");
    printf("2. DEQUEUE data\n");
    printf("3. QUEUE data display\n");
    printf("4. Exit menu\n");
    printf("\n---------------------\n");
}

int main()
{
    node *s;
    s = NULL;
    int exit = 1;
    while (exit != 4)
    {
        menu();
        printf("Enter menu option : ");
        scanf("%d", &exit);
        switch (exit)
        {
        case 1:
            ENQUEUE(&s);
            break;
        case 2:
            DEQUEUE(&s);
            break;
        case 3:
            display(&s);
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