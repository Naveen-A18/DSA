//Singly linked list - Deletion
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void create()
{
    int n;
    struct node *temp,*newnode;
    printf("How many nodes?\n");
    scanf("%d",&n);
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data for node 1:");
    scanf("%d",&head->data);
    head->next=NULL;
    temp=head;
    for(int i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data for node %d:",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
    }
}
void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void del_beg()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    ptr=head;
    head=head->next;
    printf("Deleted node is: %d\n",ptr->data);
    free(ptr);
}
void del_end()
{
    struct node *ptr,*temp;
    if(head==NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }
    if(head->next==NULL)
    {
        ptr=head;
        head=NULL;
        printf("Deleted node is: %d\n",ptr->data);
        free(ptr);
        return;
    }
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=NULL;
    printf("Deleted node:%d\n",ptr->data);
    free(ptr);
}

void del_val()
{
    struct node *prev, *cur;
    int val;
    if(head==NULL)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Enter the node value to be deleted\n");
    scanf("%d",&val);
    if(head->data==val)
    {
        cur=head;
        head=head->next;
        free(cur);
        return;
    }
    prev=head;
    cur=head->next;
    while(cur!=NULL)
    {
        if(cur->data==val)
        {
            prev->next=cur->next;
            free(cur);
            return;
        }
        prev=cur;
        cur=cur->next;
    }
    printf("Node not found\n");
}
int main()
{
    int ch;
    while(1)
    {
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Delete at Beg\n");
        printf("4. Delete at End\n");
        printf("5. Delete based on value\n");
        printf("6. Exit\n");
        printf("Whats your choice?\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                    break;
            case 2:display();
                    break;
            case 3:del_beg();
                    break;
            case 4:del_end();
                    break;
            case 5:del_val();
                    break;
            case 6:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
