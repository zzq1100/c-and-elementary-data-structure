#pragma once

#include <iostream>
#include <assert.h>

typedef int STDataType;

typedef struct stack
{
    STDataType *data;
    int top;
    int capacity;
}stack;

void STInit(stack &s);

void STDestroy(stack &s);

void STPush(stack &s, STDataType x);

void STPop(stack &st);

STDataType& STTop(stack &st);

int STSize(stack &st);

bool STEmpty(stack &st);
