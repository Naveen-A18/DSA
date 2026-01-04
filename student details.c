#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node
{
    char usn[20], name[20], prog[10];
    int sem;
    long phno;
    struct node *next;
};

struct node *first = NULL, *last = NULL;

/* Create node */
struct node* create()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter USN Name Program Sem Phone:\n");
    scanf("%s %s %s %d %ld",
          temp->usn, temp->name, temp->prog,
          &temp->sem, &temp->phno);

    temp->next = NULL;
    count++;
    return temp;
}

/* Insert at front */
void insert_front()
{
    struct node *temp = create();
    if (first == NULL)
        first = last = temp;
    else
    {
        temp->next = first;
        first = temp;
    }
}

/* Insert at end */
void insert_end()
{
    struct node *temp = create();
    if (first == NULL)
        first = last = temp;
    else
    {
        last->next = temp;
        last = temp;
    }
}

/* Delete at front */
void delete_front()
{
    struct node *temp;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp = first;
    first = first->next;
    printf("Deleted student USN: %s\n", temp->usn);
    free(temp);
    count--;
}

/* Delete at end */
void delete_end()
{
    struct node *temp, *prev;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    if (first->next == NULL)
    {
        printf("Deleted student USN: %s\n", first->usn);
        free(first);
        first = last = NULL;
    }
    else
    {
        prev = first;
        temp = first->next;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        printf("Deleted student USN: %s\n", temp->usn);
        free(temp);
        prev->next = NULL;
        last = prev;
    }
    count--;
}

/* Display */
void display()
{
    struct node *temp;
    if (first == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("\nUSN\tName\tProg\tSem\tPhone\n");
    temp = first;
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%d\t%ld\n",
               temp->usn, temp->name,
               temp->prog, temp->sem, temp->phno);
        temp = temp->next;
    }
    printf("Total Students = %d\n", count);
}

/* Main */
int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n1.Create SLL\n2.Display\n3.Insert End\n4.Delete End");
        printf("\n5.Insert Front\n6.Delete Front\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);


