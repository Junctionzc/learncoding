#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

struct StackRecord;
typedef struct StackRecord *Stack;

typedef int ElementType;

int Empty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
ElementType TopAndPop(Stack S);

#endif

/* Place in implementation file */
/* Stack implementation is a dynamically allocated array */
#define EmptyTOS(-1)
#define MinStackSize(5)

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};