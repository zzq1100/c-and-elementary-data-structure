#include "stack.hpp"

#include <cassert>
#include <climits>
#include <iostream>

void TestStack()
{
    stack st{};
    STInit(st);

    // 初始化后应有存储空间，但尚未存入元素。
    assert(st.data != nullptr);
    assert(st.capacity == 4);
    assert(st.top == 0);
    assert(STSize(st) == 0);
    assert(STEmpty(st));

    // 包含零、负数、重复值和整数边界，验证栈能原样保存数据。
    const STDataType values[] = {0, -1, 7, 7, INT_MIN, INT_MAX, 2, 3, 4, 5};
    const int count = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < count; ++i)
    {
        STPush(st, values[i]);
        assert(STSize(st) == i + 1);
        assert(!STEmpty(st));
        assert(STTop(st) == values[i]);
        // 第 5、9 次入栈触发扩容；未满时容量不应改变。
        assert(st.capacity == (i < 4 ? 4 : (i < 8 ? 8 : 16)));
        for (int j = 0; j <= i; ++j)
        {
            assert(st.data[j] == values[j]);
        }
    }

    // STTop 返回引用，修改它应直接修改栈顶，但不改变元素数量。
    STTop(st) = 99;
    assert(st.data[st.top - 1] == 99);
    assert(STSize(st) == count);
    STTop(st) = values[count - 1];

    // 按入栈的相反顺序检查并出栈，验证后进先出。
    for (int i = count - 1; i >= 0; --i)
    {
        assert(STTop(st) == values[i]);
        STPop(st);
        assert(STSize(st) == i);
        assert(STEmpty(st) == (i == 0));
        assert(st.capacity == 16);
    }

    // 清空后交替入栈、出栈，验证空间可以复用。
    STPush(st, 10);
    STPush(st, 20);
    STPop(st);
    STPush(st, 30);
    assert(STTop(st) == 30);
    assert(STSize(st) == 2);
    STPop(st);
    assert(STTop(st) == 10);
    STPop(st);
    assert(STEmpty(st));

    // 销毁后只检查指针与状态，不能再解引用已释放的空间。
    STDestroy(st);
    assert(st.data == nullptr);
    assert(st.top == 0 && st.capacity == 0);
    assert(STSize(st) == 0 && STEmpty(st));
    STDestroy(st); // delete[] nullptr 应允许重复销毁。

    // 验证 STPush 中容量为 0 的扩容分支。
    STPush(st, 42);
    assert(st.data != nullptr && st.capacity == 4);
    assert(STSize(st) == 1 && STTop(st) == 42);
    STDestroy(st); // 同时验证非空栈的销毁。
    assert(st.data == nullptr && st.top == 0 && st.capacity == 0);

    // 空栈调用 STPop/STTop 会触发断言并终止程序，不在正常测试中调用。
    std::cout << "All stack tests passed!" << std::endl;
}

int main()
{
    TestStack();
    return 0;
}
