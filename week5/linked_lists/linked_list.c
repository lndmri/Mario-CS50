#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    // Running the program with command line

    // filling nodes
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;

    }

    // printing nodes
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n",ptr->number);
        ptr = ptr->next;

    }

    // freeing dynamic space allocated

    ptr = list;
    while (ptr != NULL)
    {
        node *temp = ptr->next;
        free(ptr);
        ptr = temp;
    }

}