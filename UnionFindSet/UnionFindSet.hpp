#pragma once

#include <vector>

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

    int unionSize(int x) 
    {
        int size = 0;
        for (int i = 0; i < _ufs.size(); ++i) 
        {
            if (_ufs[i] < 0)
            {
                size++;
            }
        }
        return size;
    }

private:
    std::vector<int> _ufs;
};