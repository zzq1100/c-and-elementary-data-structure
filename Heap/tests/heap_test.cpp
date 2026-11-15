#include "../Heap.hpp"
#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>
#include <random>
#include <stdexcept>
#include <vector>

template <class Exception, class Action>
void ExpectThrow(Action action)
{
    bool caught = false;
    try { action(); }
    catch (const Exception &) { caught = true; }
    assert(caught);
}

int main()
{
    Heap heap;
    heap.HeapPush(42);
    heap.HeapInit(nullptr, 0);
    // 空数组重新初始化必须清除旧元素。
    assert(heap.HeapEmpty());
    ExpectThrow<std::out_of_range>([&] { heap.HeapTop(); });
    ExpectThrow<std::out_of_range>([&] { heap.HeapPop(); });
    ExpectThrow<std::out_of_range>([&] { heap.HeapPrint(0); });

    HDataType values[] = {5, -3, 5, 0, -9, 12};
    heap.HeapInit(values, 6);
    ExpectThrow<std::invalid_argument>([&] { heap.HeapInit(nullptr, 2); });
    ExpectThrow<std::invalid_argument>([&] { heap.HeapInit(values, -1); });
    assert(heap.HeapSize() == 6 && heap.HeapTop() == -9);
    ExpectThrow<std::out_of_range>([&] { heap.HeapPrint(-1); });
    ExpectThrow<std::out_of_range>([&] { heap.HeapPrint(6); });
    std::sort(values, values + 6);
    for (int value : values)
    {
        assert(heap.HeapTop() == value);
        heap.HeapPop();
    }
    assert(heap.HeapEmpty());

    // 与标准库小根堆对照，覆盖扩容及交替插入、删除。
    std::priority_queue<int, std::vector<int>, std::greater<int>> reference;
    std::mt19937 random(12345);
    for (int i = 0; i < 10000; ++i)
    {
        if (reference.empty() || random() % 3 != 0)
        {
            int value = static_cast<int>(random() % 2001) - 1000;
            heap.HeapPush(value);
            reference.push(value);
        }
        else
        {
            assert(heap.HeapTop() == reference.top());
            heap.HeapPop();
            reference.pop();
        }
        assert(heap.HeapSize() == static_cast<int>(reference.size()));
        if (!reference.empty()) assert(heap.HeapTop() == reference.top());
    }
    while (!reference.empty())
    {
        assert(heap.HeapTop() == reference.top());
        heap.HeapPop();
        reference.pop();
    }
    assert(heap.HeapEmpty());
    std::cout << "Heap tests passed\n";
}
