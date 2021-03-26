#include <stdio.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct BST
{
    struct Node *root;
};
struct Node *insertUtill(struct Node *root, struct Node *tbi)
{

    if (root == NULL)
        return tbi;

    if (root->data > tbi->data)
    {
        root->left = insertUtill(root->left, tbi);
    }
    else
    {
        root->right = insertUtill(root->right, tbi);
    }
    return root;
}
void insert(int data, struct BST *tree)
{

    struct Node *tbi = (struct Node *)malloc(sizeof(struct Node));
    tbi->data = data;
    tbi->left = NULL;
    tbi->right = NULL;

    tree->root = insertUtill(tree->root, tbi);
}
int search(struct Node *root, int key)
{
    if (root != NULL)
    {

        if (root->data == key)
            return 1;

        if (root->data > key)
            return search(root->left, key);
        else
            return search(root->right, key);
    }
    return 0;
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void deleteUtil(struct Node *root, int key)
{
}
void delete (struct BST *tree, int key)
{
}

int main(int argc, char const *argv[])
{
    int ar[] = {8, 3, 20, 60, 81, 14, 4, 7, 100, 13};
    struct BST *tree = (struct BST *)(malloc(sizeof(struct BST)));

    tree->root == NULL;

    for (int i = 0; i < sizeof(ar) / sizeof(int); i++)
    {
        insert(ar[i], tree);
    }
    inorder(tree->root);
    printf("\n");

    printf("%d\n", search(tree->root, 16));

    return 0;
}
