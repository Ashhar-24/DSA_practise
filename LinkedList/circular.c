#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* next;
}; //semi-colon is must!

void traversal(struct Node* head)
{
    struct Node* p=head;
    do
    {
        printf("\nThe element is: %d", p->value);
        p=p->next;
    } while (p!=head); //we're using a do-while loop instead of while loop as in while loop p==head and hence it will not enter the loop.In order to avoid that we're using a do-while loop.
    
}
 
struct Node* insert_atfirst(struct Node* head)
{
    struct Node* new=(struct Node*)malloc(sizeof(struct Node));
    printf("\nEnter the value: ");
    scanf("%d", &new->value);
    struct Node* p=head;
    struct Node* q=p->next; //created a new pointer in order to get to the last node whose next is pointing to head node.

    while(q->next!=head)
    {
        q=q->next;
    }

    q->next=new; //linking the last node to the new node created 
    new->next=head; //linking the new node to previously starting node
    head=new; //updating the head as the new node created 
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
    fourth->next=head; //as it's a circular linked list

    traversal(head);
    head=insert_atfirst(head);
    printf("\nLinked list after updation is: ");
    traversal(head);

}
