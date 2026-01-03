//Implementation of Singly Linked List
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

void ins_beg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->next=head;
    head=newnode;
}
void ins_end()
{
    struct node *newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
}
void ins_pos()
{
    struct node *newnode,*temp=head;
    int pos,i=1;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter the Position\n");
    scanf("%d",&pos);
    if(pos<0)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==0)
    {
        newnode->next=head;
        head=newnode;
        return;
    }
    while(temp!=NULL && i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    if(temp==NULL)
    {
        printf("Position out of bound\n");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}
int main()
{
    int ch;
    while(1)
    {
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beg\n");
        printf("4. Insert at End\n");
        printf("5. Insert at pos\n");
        printf("6. Exit\n");
        printf("Whats your choice?\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
                    break;
            case 2:display();
                    break;
            case 3:ins_beg();
                    break;
            case 4:ins_end();
                    break;
            case 5:ins_pos();
                    break;
            case 6:exit(0);
        }
    }
return 0;
}
