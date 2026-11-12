#pragma once

#include <iostream>
#include <cstdlib>

typedef int HDataType;

typedef int BTDataType;

class BTreeNode
{
public:
    BTreeNode(BTDataType data)
        : _data(data), _left(nullptr), _right(nullptr)
    {
    }

    void BTPrevOrder(BTreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        std::cout << root->_data << " ";
        BTPrevOrder(root->_left);
        BTPrevOrder(root->_right);
    }

private:
    BTDataType _data;
    BTreeNode *_left;
    BTreeNode *_right;
};

class Heap
{
public:
    Heap();
    ~Heap();

    void HeapPush(HDataType x);
    void HeapPop();
    int HeapSize();
    HDataType HeapTop();
    bool HeapEmpty();
    HDataType HeapPrint(int i);

    Heap(const Heap &) = delete;
    Heap &operator=(const Heap &) = delete;

private:
    void AdjustUp(HDataType *data, int size);
    void AdjustDown(HDataType *data, int size);

private:
    HDataType *_data;
    int _size;
    int _capacity;
};
