#include <stdio.h>
#include <stdlib.h>

typedef struct singleLinkedList
{
    int data;
    struct singleLinkedList *next;
} node;

int getListLength(node **head)
{
    node *temp;
    int count = 0;
    if (*head == NULL)
    {
        return count;
    }
    else
    {
        temp = *head;
        while (temp->next != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count + 1;
    }
}

void addAtBeg(node **head)
{
    node *temp;
    int num;
    printf("Enter data : ");
    scanf("%d", &num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    if (*head == NULL)
        *head = temp;
    else
    {
        temp->next = *head;
        *head = temp;
    }
    printf("\n%d is added to the begining of Linked List.\n", (*head)->data);
}

void addAtEnd(node **head)
{
    node *temp, *temp1;
    int num;
    printf("Enter data : ");
    scanf("%d", &num);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        temp1 = *head;
        while (temp1->next != NULL)
        {
            temp1 = (temp1->next);
        }
        temp1->next = temp;
    }
    printf("%d is added to the end of Linked List.\n", (temp->data));
}

void addAtSpecPos(node **head)
{
    node *temp, *temp1;
    int num, pos;
    printf("Enter data and position : ");
    scanf("%d%d", &num, &pos);
    temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    if (*head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
    }
    else
    {
        if (pos == 1)
        {
            *head = temp;
        }
        else if (pos > getListLength(head) + 1)
        {
            printf("INVALID POSITION\n");
        }
        else
        {
            temp1 = *head;
            for (int i = 1; i < pos - 1; i++)
            {
                temp1 = temp1->next;
            }
            temp->next = temp1->next;
            temp1->next = temp;
        }
    }
}

void deleteFromBeg(node **head)
{
    if (*head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
    }
    else
    {
        node *temp;
        temp = *head;
        (*head) = (*head)->next;
        printf("Deleted item = %d\n", temp->data);
        free(temp);
    }
}

void deleteFromEnd(node **head)
{
    if (*head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
    }
    else
    {
        node *temp1, *temp = *head;
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = (temp->next);
        }
        temp1->next = NULL;
        printf("%d is deleted from end\n", temp->data);
        free(temp);
    }
}

void deleteFromSpecPos(node **head)
{
    if (*head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
    }
    else
    {
        int pos;
        printf("Enter position to delete : ");
        scanf("%d", &pos);
        if (pos == 1)
        {
            deleteFromBeg(head);
        }
        else if (pos == getListLength(head))
        {
            deleteFromEnd(head);
        }
        else if (pos > getListLength(head))
        {
            printf("INVALID POSITION\n");
        }
        else
        {
            node *temp1, *temp = *head;
            for (int i = 1; i <= pos - 1; i++)
            {
                temp1 = temp;
                temp = temp->next;
            }
            temp1->next = temp->next;
            printf("%d is deleted from %d position.\n", temp->data, pos);
            free(temp);
        }
    }
}

void display(node **head)
{
    node *temp;
    if (*head == NULL)
    {
        printf("LINKED LIST EMPTY\n");
    }
    else
    {
        temp = *head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void menu()
{
    printf("\n--------------------------\n");
    printf("1. Add at the begining\n");
    printf("2. Add at the end\n");
    printf("3. Add at the specified position\n");
    printf("4. Delete from the begining\n");
    printf("5. Delete from the end\n");
    printf("6. Delete from the specified position\n");
    printf("7. Display\n");
    printf("8. Exit\n");
    printf("\n--------------------------\n");
}
int main()
{
    node *head;
    head = NULL;
    int exit = 1;

    while (exit != 8)
    {
        menu();
        printf("Enter menu option : ");
        scanf("%d", &exit);
        switch (exit)
        {
        case 1:
            addAtBeg(&head);
            break;
        case 2:
            addAtEnd(&head);
            break;
        case 3:
            addAtSpecPos(&head);
            break;
        case 4:
            deleteFromBeg(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            deleteFromSpecPos(&head);
            break;
        case 7:
            display(&head);
            break;

        case 8:
        default:
            printf("\n--------MENU EXIT--------\n");
            exit = 8;
            break;
        }
    }
    return 0;
}