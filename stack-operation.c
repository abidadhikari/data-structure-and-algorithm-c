#include <stdio.h>
#define MAX 5

struct STACK
{
    int top;
    int stack[MAX];
};

void menu()
{
    printf("\n---------------------\n");
    printf("1. POP data\n");
    printf("2. PUSH data\n");
    printf("3. STACK data display\n");
    printf("4. Exit menu\n");
    printf("\n---------------------\n");
}

void POP(struct STACK *s)
{
    if (s->top == -1)
    {
        printf("Can't POP,stack is empty.\n");
    }
    else
    {
        printf("%d is popped from stack\n", s->stack[s->top]);
        s->top = (s->top) - 1;
    }
}

void PUSH(struct STACK *s)
{
    if (s->top + 1 == MAX)
    {
        printf("Can't PUSH,stack is full.\n");
    }
    else
    {
        s->top = (s->top) + 1;
        int data;
        printf("Enter data to push : ");
        scanf("%d", &data);
        s->stack[s->top] = data;
        printf("%d is pushed to stack\n", s->stack[s->top]);
    }
}

void display(struct STACK *s)
{
    if (s->top == -1)
    {
        printf("Can't display. Stack is empty.\n");
    }
    else
    {
        int i;
        for (i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->stack[i]);
        }
    }
}

int main()
{
    struct STACK s;
    s.top = -1;
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