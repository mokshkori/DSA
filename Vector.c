#include <stdio.h>
#include <malloc.h>

#define MIN_SIZE 20

struct Vector
{
    int *ar;
    int size;
    int capacity;
};

void add(struct Vector *vector, int item)
{
    int size = vector->size;
    vector->ar[size++] = item;
    vector->size = size;

    if (vector->size > vector->capacity / 2)
    {
        printf("increasing size \n");
        int *temp = (int *)malloc(sizeof(vector->capacity * 2) * sizeof(int));

        for (int i = 0; i < vector->size; i++)
        {
            temp[i] = vector->ar[i];
        }
        vector->ar = NULL;
        free(vector->ar);
        vector->ar = temp;
        vector->capacity = vector->capacity * 2;
    }
}

void print(struct Vector *vector)
{
    for (int i = 0; i < vector->size; i++)
        printf("%d, ", (vector->ar)[i]);

    printf("\n");
}

int main(int argc, char const *argv[])
{
    struct Vector *vector = (struct Vector *)malloc(sizeof(struct Vector));
    vector->size = 0;
    vector->capacity = MIN_SIZE;
    vector->ar = (int *)malloc(MIN_SIZE * sizeof(int));

    for (int i = 0; i < 21; i++)
    {
        add(vector, i);
    }

    print(vector);

    printf("%d, %d", vector->size, vector->capacity);
    return 0;
}
