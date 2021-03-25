#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Stack
{
    struct Node *head, *tail;
};

void push(int item, struct Stack *st)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = NULL;

    if (st->head == NULL)
    {
        st->head = temp;
        st->tail = st->head;
    }
    else
    {
        st->tail->next = temp;
        temp->prev = st->tail;

        st->tail = temp;
    }
}

int pop(struct Stack *st)
{
    if (st->head == NULL)
    {
        fputs("Stack UNDERFLOW", stderr);
        return -1;
    }

    int top = st->tail->data;

    //only one element
    if (st->head->next == NULL)
    {
        free(st->head);
        st->head = NULL;
        st->tail = NULL;
    }
    else
    {

        st->tail = st->tail->prev;
        free(st->tail->next);
        st->tail->next = NULL;
    }

    return top;
}
int peek(struct Stack *st)
{
    if (st->head == NULL)
    {
        fputs("Stack UNDERFLOW", stderr);
        return -1;
    }

    return st->tail->data;
}

//for testing
void traverse(struct Stack *st)
{
    struct Node *temp = st->head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//for testing
void rtraverse(struct Stack *st)
{
    struct Node *temp = st->tail;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));

    st->head = NULL;
    st->tail = NULL;

    //test
    for (int i = 0; i < 10; i++)
    {
        push(i, st);
    }

    for (int i = 0; i < 6; i++)
        pop(st);

    printf("%d", peek(st));

    return 0;
}
