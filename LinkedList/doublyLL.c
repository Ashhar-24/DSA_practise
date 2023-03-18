#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
    struct Node *prev;
};

void forward_traversal(struct Node* head)
{
    struct Node *p=head;
    while(p!=NULL)
    {
        printf("\nThe element is: %d", p->value);
        p=p->next;
    }
    //printf("\nThe element is: %d", p->value); //printing this separately as the when p->next==NULL the value at last node isn't printed
}

void backward_traversal(struct Node* head)
{
    struct Node* p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }

    while(p!=NULL)
    {
        printf("\nThe element is: %d", p->value);
        p=p->prev;
    }
}

int main()
{
    struct Node* N1=(struct Node*)malloc(sizeof(struct Node));
    struct Node* N2=(struct Node*)malloc(sizeof(struct Node));
    struct Node* N3=(struct Node*)malloc(sizeof(struct Node));
    struct Node* N4=(struct Node*)malloc(sizeof(struct Node));
    struct Node* N5=(struct Node*)malloc(sizeof(struct Node));
    struct Node* head=N1;

    printf("\nEnetr the value: ");
    scanf("%d", &N1->value);

    printf("\nEnetr the value: ");
    scanf("%d", &N2->value);

    printf("\nEnetr the value: ");
    scanf("%d", &N3->value);

    printf("\nEnetr the value: ");
    scanf("%d", &N4->value);

    printf("\nEnetr the value: ");
    scanf("%d", &N5->value);

    N1->prev=NULL;
    N1->next=N2;

    N2->next=N3;
    N2->prev=N1;

    N3->next=N4;
    N3->prev=N2;

    N4->next=N5;
    N4->prev=N3;

    N5->next=NULL;
    N5->prev=N4;

    printf("\nThe linked list in forward traversal is: ");
    forward_traversal(head);

    printf("\nThe linked list in backward traversal is: ");
    backward_traversal(head); 
}