#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Queue
{
    struct Node *front, *back;
};

void enqueue(int item, struct Queue *q)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->next = NULL;

    if (q->front == NULL)
    {
        q->front = temp;
        q->back = temp;
    }
    else
    {
        q->back->next = temp;
        q->back = temp;
    }
}

int dequeue(struct Queue *q)
{

    if (q->front == NULL)
    {
        fputs("QUEUE empty", stderr);
        return -1;
    }
    else
    {
        struct Node *front = q->front;
        q->front = q->front->next;

        int f = front->data;

        free(front);

        return f;
    }
}

int front(struct Queue *q)
{
    if (q == NULL || q->front == NULL)
    {
        fputs("QUEUE empty", stderr);
        return -1;
    }
    return q->front->data;
}

//testing
void traverse(struct Queue *q)
{
    struct Node *temp = q->front;

    while (temp)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->back = NULL;

    for (int i = 0; i < 10; i++)
    {
        enqueue(i, q);
    }

    printf("%d\n", front(q));
    for (int i = 0; i < 10; i++)
    {
        dequeue(q);
    }
    printf("%d\n", front(q));
    traverse(q);

    return 0;
}
