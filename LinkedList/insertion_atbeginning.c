#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
}; //semi-colon is must!

struct Node* insert_atbeginning(struct Node* head) //the return type of this func is so because we're returning a pointer ('head' : pointer of type struct Node)
{   
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the new value to store at the beginning: ");
    scanf("%d", &new->value);
    new->next=head;
    head=new; //updating the new head
    return head;
}

struct Node* insert_atend(struct Node* head)
{
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value to store at the end: ");
    scanf("%d", &new->value);
    struct Node* p=head;
    while(p->next!=NULL) //for tarversing the linked list till we reach the last node.
    {
        p=p->next;
    }
    new->next=NULL;
    p->next=new;
    return head;
}

struct Node* insert_afteranindex(struct Node* head, int index)
{   
    int i=0;
    struct Node* p= head;
    struct Node* new= (struct Node* )malloc(sizeof(struct Node));
    printf("\nEnter the data to be stored: ");
    scanf("%d", &new->value);
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    new->next=p->next;
    p->next=new;
    return head;
}

void Print_Linkedlist(struct Node* head) //parameter passed from the calling func is an address (of type 'struct Node) hence we're also receiving it in a pointer of type 'struct Node'
{
    struct Node* p= head; //this pointer p is used for traversing the linked list as we dont want to loose the head pointer.
    while(p!=NULL)
    {
        printf("\nValue stored is: %d", p->value);
        p= p->next;
    }
}

// void newPrint_Linkedlist(struct Node* head)
// {
//     struct Node* p= head;
//     while(p!=NULL)
//     {
//         printf("\nValue stored is: %d", p->value);
//         p= p->next;
//     }
// } 

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

    // head->value=10;
    // first->value=320;
    // second->value=45;
    // third->value=50;
    // fourth->value=100;

    head->next=first;
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=NULL;

    printf("\nLinked list before any updation: ");
    Print_Linkedlist(head);
    head= insert_atbeginning(head);//storing it in head, because it will be used for traversing the linked list
    head=insert_atend(head);
    printf("Enter the index after which the insertion has to be made: ");
    int index;
    scanf("%d", &index);
    head=insert_afteranindex(head, index);
    printf("\nLinked list after updation: ");
    //newPrint_Linkedlist(head); 
    Print_Linkedlist(head); 
}