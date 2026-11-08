#pragma once

#include <iostream>

typedef int HDataType;

class Heap
{
public:
    Heap();
    ~Heap();

    void HeapPush(HDataType x);
    HDataType HeapPrint(int i);


    Heap(const Heap &) = delete;
    Heap &operator=(const Heap &) = delete;

private:
    void AdjustUp(HDataType *data, int size);

private:
    HDataType *_data;
    int _size;
    int _capacity;
};
