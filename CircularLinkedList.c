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
    temp->data = item;
    temp->next = NULL;

    if (cll->head == NULL)
    {
        temp->next = temp;
        cll->head = temp;
        cll->tail = temp;
    }
    else
    {
        cll->tail->next = temp;
        cll->tail = temp;
        temp->next = cll->head;
    }
}

void traverse(struct CLL *cll)
{
    struct Node *curr = cll->head;
    do
    {
        printf("%d ,", curr->data);
        curr = curr->next;
    } while (curr != cll->head);

    printf("\n");
}

void delete (int item, struct CLL *cll)
{
    struct Node *curr = cll->head, *prev = cll->tail;
    do
    {
        if (curr->data == item)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != cll->head);

    //only one element
    if (curr == cll->head)
    {

        if (curr == cll->tail)
        {
            cll->head = NULL;
            cll->tail = NULL;
        }
        else
        {
            cll->tail->next = curr->next;
            cll->head = curr->next;
        }

        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}

int main(int argc, char const *argv[])
{
    struct CLL *cll = (struct CLL *)malloc(sizeof(struct CLL));
    cll->head = NULL;
    cll->tail = NULL;

    for (int i = 0; i < 10; i++)
    {
        insert(i, cll);
    }

    traverse(cll);

    for (int i = 3; i < 10; i++)
        delete (i, cll);

    traverse(cll);

    return 0;
}
