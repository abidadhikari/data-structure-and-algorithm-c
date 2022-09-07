#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct STACK
{
    int data;
    struct STACK *next;
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

void PUSH(node **s)
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
            printf("Can't push !!!. Stack full \n");
        else
        {
            temp->next = *s;
            *s = temp;
            printf("%d is added to the top of the stack\n", num);
        }
    }
}

void POP(node **s)
{
    if (isEmpty(s))
        printf("Can't pop !!!. Stack empty \n");
    else
    {
        node *temp = *s;
        *s = (temp->next);
        printf("%d is popped from the stack\n", temp->data);
        free(temp);
    }
}

void display(node **s)
{
    if (isEmpty(s))
        printf("Can't display . stack empty\n");
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
    printf("1. POP data\n");
    printf("2. PUSH data\n");
    printf("3. STACK data display\n");
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
            POP(&s);
            break;
        case 2:
            PUSH(&s);
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