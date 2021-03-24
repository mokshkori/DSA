#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct DLL
{
    struct Node *head;
    struct Node *tail;
};

void insert(struct DLL *dll, int item)
{
    if (dll->head == NULL)
    {
        dll->head = (struct Node *)malloc(sizeof(struct Node));

        dll->head->data = item;
        dll->head->next = NULL;
        dll->head->prev = NULL;

        dll->tail = dll->head;
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        temp->data = item;
        temp->prev = dll->tail;
        temp->next = NULL;

        dll->tail->next = temp;

        dll->tail = temp;
    }
}

void traverse(struct DLL *dll)
{
    struct Node *temp = dll->head;
    while (temp != 0)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int search(struct DLL *dll, int key)
{

    struct Node *temp = dll->head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }

    return 0;
}

void deleteItem(struct DLL *dll, int item)
{

    struct Node *curr = dll->head;

    while (curr != NULL && curr->data != item)
    {
        curr = curr->next;
    }

    if (curr == NULL)
        return;

    if (curr->prev == NULL && curr->next == NULL)
    {
        free(curr);
        dll->head = NULL;
        dll->tail == NULL;

        return;
    }
    //means delete current
    if (curr->prev == NULL)
    {
        //new head
        dll->head = curr->next;

        dll->head->prev = NULL;

        free(curr);
    }
    else if (curr->next == NULL)
    {
        dll->tail = curr->prev;
        dll->tail->next = NULL;
        free(curr);
    }
    else
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
    }
}

void reverseTraverse(struct DLL *dll)
{
    struct Node *curr = dll->tail;
    while (curr != NULL)
    {
        printf("%d, ", curr->data);
        curr = curr->prev;
    }

    printf("\n");
}

int main(int argc, char const *argv[])
{

    struct DLL *dll = (struct DLL *)malloc(sizeof(struct DLL));

    dll->head = NULL;
    dll->tail = NULL;

    for (int i = 1; i < 10; i++)
        insert(dll, i);

    deleteItem(dll, 5);
    deleteItem(dll, 1);
    deleteItem(dll, 9);

    traverse(dll);
    reverseTraverse(dll);

    return 0;
}
