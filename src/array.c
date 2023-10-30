#include "array.h"

bool initIntArray(intArray_t *intArray, int *data, uint16_t size)
{
    // Allocate memory for the array
    intArray->data = (int *)malloc(size * sizeof(int));
    // Set the size of the array
    intArray->size = size;

    if (intArray->data != NULL)
    {
        // Copy the data to the array
        memcpy(intArray->data, data, size * sizeof(int));
    }

    // Return true if the allocation was successful
    return (intArray->data != NULL);
}

bool initFloatArray(floatArray_t *floatArray, float *data, uint16_t size)
{
    // Allocate memory for the array
    floatArray->data = (float *)malloc(size * sizeof(float));
    // Set the size of the array
    floatArray->size = size;

    if (floatArray->data != NULL)
    {
        // Copy the data to the array
        memcpy(floatArray->data, data, size * sizeof(float));
    }

    // Return true if the allocation was successful
    return (floatArray->data != NULL);
}

bool initCharArray(charArray_t *charArray, char *data, uint16_t size)
{
    // Allocate memory for the array
    charArray->data = (char *)malloc(size * sizeof(char));
    // Set the size of the array
    charArray->size = size;

    if (charArray->data != NULL)
    {
        // Copy the data to the array
        memcpy(charArray->data, data, size * sizeof(char));
    }

    // Return true if the allocation was successful
    return (charArray->data != NULL);
}

void freeIntArray(intArray_t *intArray)
{
    // Free the memory allocated for the array and reset all values
    free(intArray->data);
    intArray->data = NULL;
    intArray->size = 0;
}

void freeFloatArray(floatArray_t *floatArray)
{
    // Free the memory allocated for the array and reset all values
    free(floatArray->data);
    floatArray->data = NULL;
    floatArray->size = 0;
}

void freeCharArray(charArray_t *charArray)
{
    // Free the memory allocated for the array and reset all values
    free(charArray->data);
    charArray->data = NULL;
    charArray->size = 0;
}
