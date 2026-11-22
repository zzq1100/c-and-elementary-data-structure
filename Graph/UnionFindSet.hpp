#pragma once

#include <vector>
#include <math.h> // abs
#include <iostream>

class UnionFindSet
{
public:
    UnionFindSet(int n) : _ufs(n, -1) {}

    int findRoot(int x)
    {
        int root = x;
        while (_ufs[root] >= 0)
        {
            root = _ufs[root];
        }

        // 路径压缩
        while (_ufs[x] >= 0)
        {
            int parent = _ufs[x];
            _ufs[x] = root;
            x = parent;
        }

        return root;
    }

    void unionSet(int x, int y)
    {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY)
        {
            if (_ufs[rootX] < _ufs[rootY])
            {
                _ufs[rootX] += _ufs[rootY];
                _ufs[rootY] = rootX;
            }
            else
            {
                _ufs[rootY] += _ufs[rootX];
                _ufs[rootX] = rootY;
            }
        }
    }

    bool InSameSet(int x, int y)
    {
        return findRoot(x) == findRoot(y);
    }

    // 统计所有集合的数量。
    int setCount() const
    {
        int count = 0;

        for (int value : _ufs)
        {
            if (value < 0)
            {
                ++count;
            }
        }

        return count;
    }

    // 查询 x 所在集合的元素数量。
    int setSize(int x)
    {
        return -_ufs[findRoot(x)];
    }

private:
    std::vector<int> _ufs;
};

void testUnionFindSet()
{
    UnionFindSet ufs(10);
    ufs.unionSet(0, 1);
    ufs.unionSet(1, 2);
    ufs.unionSet(3, 4);
    ufs.unionSet(4, 5);
    ufs.unionSet(6, 7);
    ufs.unionSet(7, 8);
    ufs.unionSet(8, 9);

    std::cout << "Root of 0: " << ufs.findRoot(0) << std::endl; // Should print the root of the set containing 0
    std::cout << "Root of 3: " << ufs.findRoot(3) << std::endl; // Should print the root of the set containing 3
    std::cout << "Root of 6: " << ufs.findRoot(6) << std::endl; // Should print the root of the set containing 6

    std::cout << "Number of disjoint sets: " << ufs.setCount() << std::endl; // Should print the number of disjoint sets
}