#include <stdio.h>
#include "list.h"

void ListTest();

int main(int argc, char **argv)
{
    TestList();
    
    return 0;
}

void TestList()
{
    struct Node node;
    List L = &node;
    Position P;
    
    L->Next = NULL;
    
    printf("Is list empty? %s\n", IsEmpty(L) ? "Yes." : "No.");
    
    Insert(5, L, L);
    
    printf("Have inserted an element 5 into the list.\n");
    
    printf("Is list empty? %s\n", IsEmpty(L) ? "Yes." : "No.");
    
    P = Find(5, L);
    
    if (P != NULL) {
        printf("There is an element %d in list.\n", P->Element);
    } else {
        printf("Couldn't find element 5 in list.\n");
    }
    
    Delete(5, L);
    
    printf("Have deleted the element 5.\n");
    
    printf("Is list empty? %s\n", IsEmpty(L) ? "Yes." : "No.");
}