// Q23. Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node *insert(struct Node *start, int data)
{
    struct Node* newNode = create(data);
    if (start == NULL) 
    {
        return newNode;
    }
    struct Node* temp = start;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return start;

}

struct Node *merge(struct Node *L1, struct Node *L2)
{
    if(L1 == NULL)
        return L2;
    if(L2 == NULL)
        return L1;

    struct Node *result = NULL;
    if(L1->data <= L2->data)
    {
        result = L1;
        result->next = merge(L1->next, L2);
    }
    else
    {
        result = L2;
        result->next = merge(L1, L2->next);
    }
    return result;
}

void printList(struct Node* start) 
{
    struct Node* temp = start;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n1, n2, value;
    struct Node *list1 = NULL, *list2 = NULL;

    printf("Enter the value of n1: ");
    scanf("%d",&n1);

    printf("Enter list1 data: \n ");
    for(int i=0; i < n1; i++)
    {
        scanf("%d",&value);
        list1 = insert(list1, value);
    }

    printf("Enter the value of n2: ");
    scanf("%d",&n2);

    for (int i = 0; i < n2; i++) 
    {
        scanf("%d", &value);
        list2 = insert(list2, value);
    }

    printf("First List: ");
    printList(list1);
    printf("Second List: ");
    printList(list2);

    struct Node* merged = merge(list1, list2);

    printf("Merged Sorted List: ");
    printList(merged);

    return 0;
}
