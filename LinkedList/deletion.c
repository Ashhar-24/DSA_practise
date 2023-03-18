#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
}; //semi-colon is must!

void Print_Linkedlist(struct Node* head) //parameter passed from the calling func is an address (of type 'struct Node) hence we're also receiving it in a pointer of type 'struct Node'
{
    struct Node* p= head; //this pointer p is used for traversing the linked list as we dont want to loose the head pointer.
    while(p!=NULL)
    {
        printf("\nValue stored is: %d", p->value);
        p= p->next;
    }
}

struct Node* delete_beginning(struct Node* head)
{   struct Node* p=head;
    head=head->next;
    free(p);
    return head;
}

struct Node* deletion_afteranindex(struct Node* head, int index)
{
    int i=0;
    struct Node* p= head;
    while(i!=index-1) //for accessing the previous node
    {
        p=p->next;
        i++;
    }

    struct Node*q=p->next; //creating a new pointer which points to the node which has to be deleted.
    p->next=q->next; //updating the links
    free(q); 
    return head;
}

struct Node* delete_fromend(struct Node* head)
{
    struct Node*p=head;
    struct Node*q=p->next;
    //p=p->next;
    while(q->next!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;    
}

struct Node* delete_avalue(struct Node* head, int value)
{
    struct Node*p=head;
    struct Node*q=p->next;
    //int i=value;
    while(q->value!=value)
    {   
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

int main()
{
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    struct Node* first= (struct Node*)malloc(sizeof(struct Node));
    struct Node* second= (struct Node*)malloc(sizeof(struct Node));
    struct Node* third= (struct Node*)malloc(sizeof(struct Node));
    struct Node* fourth= (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the value: ");
    scanf("%d", &head->value);//using '&' sign is must, else it will not store the value
    // '->' is used along with a pointer variable. It accesses/stores the value at the location ie,variable to which the pointer points.

    printf("\nEnter the value: ");
    scanf("%d", &first->value);

    printf("\nEnter the value: ");
    scanf("%d", &second->value);

    printf("\nEnter the value: ");
    scanf("%d", &third->value);

    printf("\nEnter the value: ");
    scanf("%d", &fourth->value);

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    printf("\nLinked list before any updation: ");
    Print_Linkedlist(head);
    // printf("\nDeletion from beginnig: ");
    // head=delete_beginning(head);
    // Print_Linkedlist(head);

    // printf("\nDeletion after a given index: ");
    // printf("\nEnter the index: ");
    // int index;
    // scanf("%d", &index);
    // head=deletion_afteranindex(head, index);
    // printf("\nAfter deletion: ");
    // Print_Linkedlist(head);

    printf("\nDeletion from end: ");
    head=delete_fromend(head);
    printf("\nLinked list looks like: ");
    Print_Linkedlist(head);

    printf("\nDelete a node with a given value: ");
    int value;
    printf("\nEnter the value: ");
    scanf("%d",&value);
    head=delete_avalue(head, value);
    printf("\nNew linked list: ");
    Print_Linkedlist(head);
}