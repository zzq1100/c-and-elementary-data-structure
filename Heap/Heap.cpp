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

// 向上调整建堆：先把数组整体拷进来，再从第 2 个元素开始逐个向上调整
// 时间复杂度 O(N*logN)，每次调整都是沿着一条路径走最多 logN 步
void Heap::HeapInit(HDataType *a, int n)
{
    if (a == nullptr || n <= 0)
    {
        return;
    }

    if (n > _capacity)
    {
        HDataType *newdata = (HDataType *)realloc(_data, sizeof(HDataType) * n);
        if (newdata == nullptr)
        {
            return;
        }
        _data = newdata;
        _capacity = n;
    }

    for (int i = 0; i < n; i++)
    {
        _data[i] = a[i];
    }
    _size = n;

    // 从下标 1 开始，每个元素都向上调整一次，最终整棵完全二叉树构成小根堆
    for (int i = 1; i < _size; i++)
    {
        AdjustUp(_data, i);
    }
}

void Heap::HeapPush(HDataType x)
{
    if (_size == _capacity)
    {
        int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
        HDataType *newdata = (HDataType *)realloc(_data, sizeof(HDataType) * newcapacity);
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

void Heap::AdjustDown(HDataType *data, int size)
{
    int parent = 0;
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && data[child + 1] < data[child])
        {
            child++;
        }
        if (data[parent] > data[child])
        {
            swap(data[parent], data[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

void Heap::HeapPop()
{
    swap(_data[0], _data[_size - 1]);
    _size--;
    AdjustDown(_data, _size);
}

int Heap::HeapSize()
{
    return _size;
}

HDataType Heap::HeapTop()
{
    return _data[0];
}

bool Heap::HeapEmpty()
{
    return _size == 0;
}