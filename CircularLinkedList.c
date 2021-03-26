#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CLL
{
    struct Node *head, *tail;
};

void insert(int item, struct CLL *cll)
{

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
}

int main(int argc, char const *argv[])
{
    struct CLL *cll = (struct CLL *)malloc(sizeof(struct CLL));
    cll->head = NULL;
    cll->tail = NULL;

    return 0;
}
