/*-------------------------------
https://github.com/zulfiqarsielab/Advance_Data_Structures/tree/main/Assignment%2002
-------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1

#define STACK_SIZE 5
#define QUEUE_SIZE 5


struct Node
{
    int id;
    char name[20];
    struct Node *next;
};

/* Stack operations */
struct Node *top = NULL;

/* Circular Queue*/
struct Node *queue[QUEUE_SIZE];
int front = 0;
int rear = 0;
int queueCount = 0;


int push(int id, char name[])
{
    struct Node *newNode;

    /**Check Stack Overflow */
    int count = 0;
    struct Node *temp = top;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (count>=STACK_SIZE)
    {return ERROR;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return ERROR;
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = top;
    top = newNode;
    return OK;
}

/* Pop operation */
struct Node *pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        return NULL;
    }
    temp = top;
    top = top->next;
    return temp;
}

int printStack()
{
    struct Node *temp = top;
    if (temp == NULL)
    {
        return ERROR;
    }
    temp = top;
    printf("\n-- Stack Elements ---\n");
    while (temp != NULL)
    {
        printf("ID: %d, Name: %s\n", temp->id, temp->name);
        temp = temp->next;
    }
    printf("---------------------\n");
    return OK;
}

int insertQ(int id, char name[])
{
    struct  Node *newNode;

    if (queueCount >= QUEUE_SIZE)
    {
        return ERROR;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return ERROR;
    }
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    queue[rear] = newNode;
    rear = (rear + 1) % QUEUE_SIZE;
    queueCount++;
    return OK;
}

struct Node *deleteQ()
{
    struct Node *temp;

    if (queueCount <= 0)
    {
        return NULL;
    }
    temp = queue[front];
    front = (front + 1) % QUEUE_SIZE;
    queueCount--;
    temp->next = NULL; 
    return temp;
}

int printQueue()
{
   int i;
   int index;

   if (queueCount <= 0)
   {
       return ERROR;
   }
   printf("\n---Circular Queue Elements---\n");
   index = front;
    for (i = 0; i < queueCount; i++)
    {
         printf("ID: %d, Name: %s\n", queue[index]->id, queue[index]->name);
         index = (index + 1) % QUEUE_SIZE;
    }
    printf("---------------------\n");
    return OK;
}

/** Main function */
int main()
{
    struct Node *deletedNode;
    /*Stack Test*/
    push(2026001, "Ali");
    push(2026002, "Ahmed");
    push(2026003, "Muhabb");
    printStack();

printf("\nPop operation:\n");
    deletedNode = pop();
    if (deletedNode != NULL)
    {
        printf("Deleted Node - ID: %d, Name: %s\n", deletedNode->id, deletedNode->name);
        free(deletedNode);
    }
    printStack();

    /*Circular Queue Test*/
    insertQ(2026001, "Ali");
    insertQ(2026002, "Ahmed");
    insertQ(2026003, "Muhab");
    printQueue();
    printf("\nDelete operation:\n");
    deletedNode = deleteQ();
    if (deletedNode != NULL)
    {
        printf("Deleted Node - ID: %d, Name: %s\n", deletedNode->id, deletedNode->name);
        free(deletedNode);
    }
    printQueue();

    /*Demonstrate circular behavior*/

    insertQ(2026004, "Lee");
    insertQ(2026005, "Park");
    insertQ(2026006, "Kim");

    printQueue();

    return 0;
}