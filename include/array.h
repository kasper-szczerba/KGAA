#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>
#include "main.h"

typedef struct
{
    int *data;
    uint32_t size;
} intArray_t;

typedef struct
{
    float *data;
    uint32_t size;
} floatArray_t;

typedef struct
{
    char *data;
    uint32_t size;
} charArray_t;

bool initIntArray(intArray_t *, int *, uint16_t);
bool initFloatArray(floatArray_t *, float *, uint16_t);
bool initCharArray(charArray_t *, char *, uint16_t);

void freeIntArray(intArray_t *);
void freeFloatArray(floatArray_t *);
void freeCharArray(charArray_t *);

#endif // __ARRAY_H__