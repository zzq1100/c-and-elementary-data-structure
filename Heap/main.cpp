#include <iostream>

#include "Heap.hpp"

using namespace std;

int main()
{
    HDataType a[] = {1, 23, 423, 543, 432, 5, 34, 2,  4, 431, 4,  25, 2, 234, 23, 523, 5, 2523};
    int n = sizeof(a) / sizeof(a[0]);
    Heap hp;
    for (int i = 0; i < n; i++)
    {
        hp.HeapPush(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << hp.HeapPrint(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        hp.HeapPop();
        for (int j = 0; j < hp.HeapSize(); j++)
        {
            cout << hp.HeapPrint(j) << " ";
        }
        cout << endl;
    }



    return 0;
}
