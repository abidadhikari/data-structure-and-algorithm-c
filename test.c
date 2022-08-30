#include <stdio.h>
#include <stdlib.h>
typedef struct dlist
{
    int data;
    struct dlist *prev;
    struct dlist *next;
} node;

void add_at_begining(node **head)
{
    node *temp;
    int num;
    printf("enter the data you want to insert");
    scanf("%d", &num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;
    if (*head == NULL)
        *head = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}
void add_at_end(node **head)
{
    node *temp;
    int num;
    printf("enter the data you want to insert");
    scanf("%d", &num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;
    if (*head == NULL)
        *head = temp;
    else
    {
        node *temp1 = *head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }
}
void add_at_specified(node **head)
{
    node *temp;
    int num, pos;
    printf("enter the data you want to insert");
    scanf("%d", &num);
    printf("enter the position where you want to insert");
    scanf("%d", &pos);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;
    if (*head == NULL)
    {
        printf("list is empty so it will be the first node");
        *head = temp;
    }
    else
    {
        node *temp1 = *head;
        if (pos == 1)
        {
            temp->next = *head;
            (*head)->prev = temp;
            *head = temp;
        }
        else
        {
            for (int i = 1; i < (pos - 1); i++)
            {

                temp1 = temp1->next;
            }
            temp1->next->prev = temp;
            temp->next = temp1->next;
            temp1->next = temp;
            temp->prev = temp1;
        }
    }
}
void delete_from_begining(node **head)
{
    node *temp;
    if (*head == NULL)
    {
        printf("list is empty ");
    }

    else
    {
        temp = *head;

        (*head) = (*head)->next;
        printf("%d is deleted from the linked list", temp->data);
        free(temp);
    }
}
void delete_from_end(node **head)
{
    node *temp = *head;
    if (*head == NULL)
    {
        printf("list is empty ");
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        (temp->prev)->next = NULL;
        printf("%d is deleted from the linked list", temp->data);
        free(temp);
    }
}
void delete_from_specific(node **head)
{
    node *temp = *head;
    int pos;
    printf("enter the position where you want to delete");
    scanf("%d", &pos);
    if (*head == NULL)
    {
        printf("list is empty ");
    }
    else
    {
        if (pos == 1)
        {
            temp = *head;

            (*head) = (*head)->next;
            printf("%d is deleted from the linked list", temp->data);
            free(temp);
        }
        else
        {
            for (int i = 1; i < pos; i++)
            {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            printf("%d is deleted from the linked list", temp->data);
            free(temp);
        }
    }
}

void display(node **head)
{

    if (*head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        node *temp = *head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    node *head = NULL;

    int choice;
    do
    {
        printf("\n-------------------------------------------\n");
        printf("1.Add at begining \n");
        printf("2.Add at the end \n");
        printf("3.Add at the specified position \n");
        printf("4.Delete from the begining \n");
        printf("5.Delete from the end \n");
        printf("6.Delete from specified position \n");
        printf("7.Display\n");
        printf("8.Exit \n");

        printf("Enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            add_at_begining(&head);
            break;
        case 2:
            add_at_end(&head);
            break;

        case 3:
            add_at_specified(&head);
            break;

        case 4:
            delete_from_begining(&head);
            break;
        case 5:
            delete_from_end(&head);
            break;
        case 6:
            delete_from_specific(&head);
            break;

        case 7:
            display(&head);
            break;

        case 8:
            printf("program is exited");

            break;

        default:
            printf("invalid command");
            break;
        }
    }

    while (choice != 8);

    return 0;
}