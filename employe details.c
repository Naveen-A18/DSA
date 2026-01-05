#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;

struct node
{
    int ssn;
    char name[20], dept[10], desig[20];
    float sal;
    long phno;
    struct node *prev, *next;
};

struct node *first = NULL, *last = NULL;

/* Create node */
struct node* create()
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter SSN Name Dept Designation Salary Phone:\n");
    scanf("%d %s %s %s %f %ld",
          &temp->ssn, temp->name, temp->dept,
          temp->desig, &temp->sal, &temp->phno);

    temp->prev = temp->next = NULL;
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
        first->prev = temp;
        first = temp;
    }
}

/* Insert at rear */
void insert_rear()
{
    struct node *temp = create();
    if (first == NULL)
        first = last = temp;
    else
    {
        last->next = temp;
        temp->prev = last;
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
    printf("Deleted Employee SSN: %d\n", temp->ssn);
    first = first->next;
    if (first != NULL)
        first->prev = NULL;
    else
        last = NULL;
    free(temp);
    count--;
}

/* Delete at rear */
void delete_rear()
{
    struct node *temp;
    if (last == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    temp = last;
    printf("Deleted Employee SSN: %d\n", temp->ssn);
    last = last->prev;
    if (last != NULL)
        last->next = NULL;
    else
        first = NULL;
    free(temp);
    count--;
}

/* Display */
void display()
{
    struct node *temp = first;
    if (temp == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    printf("\nSSN  Name  Dept  Desig  Salary  Phone\n");
    while (temp != NULL)
    {
        printf("%d %s %s %s %.2f %ld\n",
               temp->ssn, temp->name, temp->dept,
               temp->desig, temp->sal, temp->phno);
        temp = temp->next;
    }
    printf("Total Employees = %d\n", count);
}

/* Main */
int main()
{
    int ch, n, i;

    while (1)
    {
        printf("\n1.Create DLL\n2.Display\n3.Insert Front\n4.Delete Front");
        printf("\n5.Insert Rear\n6.Delete Rear\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                    insert_rear();
                break;

            case 2: display(); break;
            case 3: insert_front(); break;
            case 4: delete_front(); break;
            case 5: insert_rear(); break;
            case 6: delete_rear(); break;
            case 7: exit(0);
            default: printf("Wrong Choice\n");
        }
    }
}
