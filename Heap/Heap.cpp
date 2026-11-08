#include "Heap.hpp"

using namespace std;

Heap::Heap()
    : _data(nullptr), _size(0), _capacity(0)
{
}

Heap::~Heap()
{
    free(_data);
    _size = _capacity = 0;
}

void Heap::AdjustUp(HDataType *data, int size)
{
    int child = size;
    int parent = (child - 1) / 2;

    while (child > 0)
    {
        if (data[child] < data[parent])
        {
            swap(data[child], data[parent]);
            child = parent;
            parent = (child - 1) / 2;
        }
        else
        {
            break;
        }
    }
}

void Heap::HeapPush(HDataType x)
{
    if (_size == _capacity)
    {
        int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
        HDataType *newdata = (HDataType*)realloc(_data, sizeof(HDataType) * newcapacity);
        _capacity = newcapacity;
        _data = newdata;
    }
    _data[_size++] = x;
    AdjustUp(_data, _size - 1);
}

HDataType Heap::HeapPrint(int i)
{
    return _data[i];
}