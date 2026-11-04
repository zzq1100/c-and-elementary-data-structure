#include "stack.hpp"

void STInit(stack &s)
{
    // 分配 4 个元素的数组，而不是一个值为 4 的整数。
    s.data = new STDataType[4];
    s.top = 0;
    s.capacity = 4;
}

void STDestroy(stack &s)
{
    delete[] s.data;
    s.data = nullptr;
    s.top = s.capacity = 0;
}

void STPush(stack &s, STDataType x)
{
    if (s.top == s.capacity)
    {
        int newcapacity = s.capacity == 0 ? 4 : s.capacity * 2;
        // new[] 分配的内存不能用 realloc 扩容，需先分配再复制。
        STDataType *newdata = new STDataType[newcapacity];
        for (int i = 0; i < s.top; ++i)
        {
            newdata[i] = s.data[i];
        }
        delete[] s.data;
        s.data = newdata;
        s.capacity = newcapacity;
    }
    s.data[s.top] = x;
    s.top++;
}

void STPop(stack &st)
{
    assert(st.top > 0);
    st.top--;
}

STDataType& STTop(stack &st)
{
    assert(st.top > 0);
    return st.data[st.top - 1];
}

int STSize(stack &st)
{
    return st.top;
}

bool STEmpty(stack &st)
{
    return st.top == 0;
}
