#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
    int length;
};

struct LinkedList
{
    struct Node *head, *tail;
};

void insert(struct LinkedList *list, int item)
{
    if (list->head == NULL)
    {
        //allocate mem for head and tail
        list->head = (struct Node *)malloc(sizeof(struct Node));
        list->tail = (struct Node *)malloc(sizeof(struct Node));

        //set item;
        list->head->data = item;
        list->head->next = NULL;
        //set tail to point to last node
        list->tail = list->head;
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = item;
        temp->next = NULL;

        list->tail->next = temp;
        list->tail = temp;
    }
}

void traverse(struct LinkedList *list)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete (struct LinkedList *list, int item)
{
    struct Node *temp = list->head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != item)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element (%d) Does not exists\n", item);
        return;
    }

    if (prev == NULL)
    {
        list->head = list->head->next;
    }
    else
    {
        prev->next = temp->next;
    }

    free(temp);
}

void insertAtFront(struct LinkedList *list, int item)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = item;
    temp->next = list->head;
    list->head = temp;

    //if list was initialy empty
    if (list->tail == NULL)
    {
        list->tail = temp;
    }
}

int search(struct LinkedList *list, int key)
{
    struct Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return 1;
        temp = temp->next;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    struct LinkedList *list = NULL;
    list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->tail = NULL;

    //testing

    insertAtFront(list, -10);
    for (int i = 0; i < 10; i++)
    {
        insert(list, i);
    }

    traverse(list);
    delete (list, 9);
    delete (list, 7);
    delete (list, 0);
    delete (list, 10);
    traverse(list);

    insertAtFront(list, -19);

    printf("%d", search(list, 5));

    return 0;
}
