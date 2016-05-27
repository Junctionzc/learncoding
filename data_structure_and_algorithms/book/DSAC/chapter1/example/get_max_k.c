#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void bubble_sort(ElementType array[], int array_len)
{
    int i, j;
    ElementType tmp;
    
    for (i = 0; i < array_len; ++i) {
        for (j = 0; j < array_len - i - 1; ++j) {
            if (array[j] < array[j + 1]) {
                tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int get_max_k(ElementType array[], int array_len, int k)
{
    int i;
    ElementType *sorted_array = (ElementType *)malloc(sizeof(ElementType) * array_len);
    ElementType result;
    
    for (i = 0; i < array_len; ++i)
    {
        sorted_array[i] = array[i];
    }
    
    bubble_sort(sorted_array, array_len);
    
    result = sorted_array[k - 1];
    
    free(sorted_array);
    
    return result; 
}

int main()
{
    int i;
    int array_len;
    int result;
    
    ElementType array[] = {6, 1, 5, 7, 14, 1, 7, 7, 3, 6, 2};
    array_len = sizeof(array) / sizeof(ElementType);
       
    printf("Now the array is: ");   
    for (i = 0; i < array_len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    result = get_max_k(array, array_len, 4);
    
    printf("The %d max element is %d\n", 4, result);
    
    printf("Now the array is: ");  
    for (i = 0; i < array_len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    bubble_sort(array, array_len);
    printf("Hava sorted the array\n");
    printf("Now the array is: ");  
    for (i = 0; i < array_len; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}