#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node * next;
}node;

int main(int argc, char* argv[])
{
    node *list = NULL;

    for (int i = 0; i < argc - 1; i++)
    {
        int number = atoi(argv[i+1]);
        node *n = malloc(sizeof(node));
        if (n==NULL)
        {
            return 1;
        }

        n->value = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }

    //printing the nodes

    node *ptr = list;
    for (int i = 0; i < argc - 1; i++)
    {
        printf("%d ",ptr->value);
        ptr = ptr->next;

    }

}

