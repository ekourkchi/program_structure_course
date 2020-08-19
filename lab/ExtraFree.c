/*
 * ExtraFree.c
 *
 * Here is a simple C program that defines a struct that wraps around the standard C int array and some
 * functions that can be used to create and print the struct.  However, there are some mallocs and thus, there
 * must be some frees to prevent memory leaks (remember 1 malloc -> 1 free).
 *
 * It looks like the programmer went a little bit overboard when it came to adding the frees
 * and now the program keeps crashing!  Remove the extra frees by commenting them out.
 *
 * Hints:
 *   -If you should not free a pointer if you access the value that is being pointed to later on.
 *   -You do need to free malloced memory if the pointer gets re-assigned to another address.
 *   -To help you out, there is a Section comment marking every time pIntArray is re-assigned.
 *   -Stack memory should NOT be freed.
 */

#include <stdlib.h>
#include <stdio.h>

struct IntArray
{
    int length;
    int *pArray;
};

/*
 * Creates a new IntArray struct with an internal array of the given size and
 * returns a pointer to the created struct.
 */
struct IntArray *createIntArray(int size)
{
    struct IntArray * pIntArray;
    int i;

    pIntArray = (struct IntArray *) malloc(sizeof(struct IntArray));
    pIntArray->length = size;
    pIntArray->pArray = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < size; i++)
    {
        pIntArray->pArray[i] = 0;
    }

    //free(pIntArray->pArray);
    //free(pIntArray);
    return pIntArray;
}

/*
 * Prints every element of the internal array of the given IntArray struct.
 */
void printIntArray(struct IntArray *pIntArray)
{
    int i;
    printf("[");
    for (i = 0; i < pIntArray->length; i++)
    {
        printf("%d%s", pIntArray->pArray[i], i == pIntArray->length - 1 ? "" : ", ");
    }
    printf("]\n");
    //free(pIntArray->pArray);
    //free(pIntArray);
}

int main(void)
{
    int i;
    int myArray[] = { 3, -2, 1, -94, 91, 2 };
    struct IntArray intArray;
    struct IntArray *pIntArray;

    /* Section 1 */
    pIntArray = &intArray;  
    pIntArray->pArray = myArray;
    pIntArray->length = 6;
    printIntArray(pIntArray);
    //free(pIntArray->pArray);
    //free(pIntArray);

    /* Section 2 */
    pIntArray = (struct IntArray *) malloc(sizeof(struct IntArray));
    pIntArray->pArray = myArray;
    pIntArray->length = 6;
    printIntArray(pIntArray);
    //free(pIntArray->pArray);
    free(pIntArray);

    /* Section 3 */
    pIntArray = createIntArray(10);
    printIntArray(pIntArray);
    //free(pIntArray->pArray);
    //free(pIntArray);

    for (i = 0; i < pIntArray->length; i++)
    {
        pIntArray->pArray[i] = i * 5 / 7;
    }
    printIntArray(pIntArray);
    free(pIntArray->pArray);
    //free(pIntArray);

    pIntArray->pArray = (int *) malloc(sizeof(int) * 3);
    pIntArray->length = 3;
    pIntArray->pArray[0] = -2;
    pIntArray->pArray[1] = 0;
    pIntArray->pArray[2] = 20;
    //free(pIntArray->pArray);
    //free(pIntArray);

    printIntArray(pIntArray);
    free(pIntArray->pArray);
    free(pIntArray);

    printf("Please press Enter to exit:");
    getchar();
    return 0;
}
