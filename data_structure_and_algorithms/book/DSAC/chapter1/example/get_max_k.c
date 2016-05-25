#include <stdio.h>

typedef int ElementType;

void bubble_sort(ElementType *p_array, int array_len)
{
    int i, j;
    ElementType tmp;
    
    for (i = 0; i < array_len; ++i) {
        for (j = 0; j < array_len - i - 1; ++j) {
            if (p_array[j] < p_array[j + 1]) {
                tmp = p_array[j];
                p_array[j] = p_array[j + 1];
                p_array[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int array
    return 0;
}