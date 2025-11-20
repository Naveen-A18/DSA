//Concatenation of two singly linked lists
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create(struct node *head)
{
    int n;
    struct node *temp,*newnode;
    printf("How many nodes?\n");
    scanf("%d",&n);
    if(n==0)
    return NULL;
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
    return head;
}
void display(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct node *concatenate(struct node *head1,struct node *head2)
{
    struct node *temp=head1;
    if(head1==NULL)
    return head2;
    if(head2==NULL)
    return head1;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=head2;
    return head1;
}
int main()
{
    struct node *head1=NULL;
    struct node *head2=NULL;
    printf("LIST1:\n");
    head1=create(head1);
    display(head1);
    printf("LIST2:\n");
    head2=create(head2);
    display(head2);
    printf("CONCATENATE TWO LISTS:\n");
    head1=concatenate(head1,head2);
    display(head1);
}
