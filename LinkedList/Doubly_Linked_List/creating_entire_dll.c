#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};



struct node* addToEmpty(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* addAtBeg(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    return head;
}

struct node* addAtEnd(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
    {
        tp = tp->next;
        tp->next = temp;
        temp->prev = tp;
    }

    return head;
}

struct node* addAfterPos(struct node *head, int data, int position)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = addToEmpty(newP, data);

    while (position != 1)
    {
        temp = temp->next;
        position--;
    }
    temp2 = temp->next;
    temp->next = newP;
    temp2->prev = newP;
    temp2->next = temp2;
    newP->prev = temp;

    return head;
}

struct node* createList(struct node* head){
    int n, data,i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n==0)
    return head;

    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for (int i = 1; i < n; i++)
    {
        printf("Enter the element for the node %d: ",i+1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = createList(head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}