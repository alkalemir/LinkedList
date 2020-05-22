#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct _Node {
    void * Data;
    struct _Node * Next;
    struct _Node * Prev;
} Node;

typedef struct _LinkedList {
    size_t typeSize;
    struct _Node * Root;
} LL;

int initLL(LL * ll, size_t typeSize)
{
    ll->typeSize = typeSize;
    ll->Root = NULL;

    return EXIT_SUCCESS;
}

int addToEnd(LL * ll, const void * Data)
{
    if (ll->Root == NULL)
    {
        ll->Root = malloc(sizeof(Node));

        if (ll->Root == NULL)
            return EXIT_FAILURE;

        ll->Root->Data = malloc(sizeof(ll->typeSize));

        if (ll->Root->Data == NULL)
            return EXIT_FAILURE;

        memcpy(ll->Root->Data, Data, ll->typeSize);
        ll->Root->Next = NULL;
        ll->Root->Prev = NULL;

        return EXIT_SUCCESS;
    }

    Node * node = malloc(sizeof(Node));

    if (node == NULL)
        return EXIT_FAILURE;

    node->Data = malloc(sizeof(ll->typeSize));

    if (node->Data == NULL)
        return EXIT_FAILURE;

    memcpy(node->Data, Data, ll->typeSize);
    node->Next = NULL;
    node->Prev = NULL;

    Node * iter = ll->Root;

    while (iter->Next != NULL)
        iter = iter->Next;

    iter->Next = node;
    node->Prev = iter;

    return EXIT_SUCCESS;
}

int addTo(LL * ll, int index, const void * Data)
{
    if (ll->Root == NULL)
    {
        ll->Root = malloc(sizeof(ll->typeSize));

        if (ll->Root == NULL)
            return EXIT_FAILURE;

        memcpy(ll->Root->Data, Data, ll->typeSize);
        ll->Root->Next = NULL;
        ll->Root->Prev = NULL;

        return EXIT_SUCCESS;
    }

    Node * node = malloc(sizeof(Node));

    if (node == NULL)
        return EXIT_FAILURE;

    node->Data = malloc(sizeof(ll->typeSize));

    if (node->Data == NULL)
        return EXIT_FAILURE;

    memcpy(node->Data, Data, ll->typeSize);
    node->Next = NULL;
    node->Prev = NULL;

    Node * iter = ll->Root;

    while(index--)
        iter = iter->Next;

    Node * temp = iter->Next;
    iter->Next = node;
    node->Prev = iter;
    node->Next = temp;

    return EXIT_SUCCESS;
}

int removeEnd(LL * ll)
{
    Node * iter = ll->Root;

    while (iter->Next->Next != NULL)
        iter = iter->Next;

    free(iter->Next);
    iter->Next = NULL;

    return EXIT_SUCCESS;
}

int removeAt(LL * ll, int index)
{
    if (index == 0)
    {
        Node * temp = ll->Root;
        temp = temp->Next;
        ll->Root = temp;
        free(temp->Prev);
        return EXIT_SUCCESS;
    }
    Node * iter = ll->Root;

    while (index--)
        iter = iter->Next;

    Node * temp = iter->Prev;
    temp->Next = iter->Next;
    iter->Next->Prev = temp;

    return EXIT_SUCCESS;
}

int clearNodes(LL * ll)
{
    Node * iter = ll->Root;

    while (iter->Next != NULL)
        iter = iter->Next;

    while (iter->Prev != ll->Root)
    {
        iter = iter->Prev;
        free(iter->Next);
    }
    ll->Root = NULL;
    free(ll->Root);

    return EXIT_SUCCESS;
}

int destroyLL(LL * ll)
{
    if (ll->Root != NULL)
        return EXIT_FAILURE;

    free(ll);

    return EXIT_SUCCESS;
}

void printNodes(LL * ll)
{
    Node * iter = ll->Root;

    while (iter->Next != NULL)
    {
        printf("%d\n", *(int *)iter->Data);
        iter = iter->Next;
    }
}
/*
int main()
{
    LL ll;

    initLL(&ll, sizeof(int));

    int x = 10;
    while(x--)
        addToEnd(&ll, &x);
    printNodes(&ll);
    printf("\n\n");
    int y = 5;
    while (--y)
        removeEnd(&ll);
    removeAt(&ll, 2);
    int z = 99;
    addTo(&ll, 2, &z);
    printNodes(&ll);
    destroyLL(&ll);
}
*/
