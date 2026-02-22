// Q22. Count Nodes in Linked List.

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() 
{
    // Create a simple linked list: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    // Count nodes
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }

    printf("Number of nodes in linked list: %d\n", count);

    return 0;
}
