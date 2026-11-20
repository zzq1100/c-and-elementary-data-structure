#pragma once

#include <vector>
#include <map>
#include <climits>  // INT_MAX
#include <cstddef>  // std::size_t



namespace matrix
{
    template <class V, class W, W MAX_W = INT_MAX, bool Direction = true>
    class Graph
    {
    public:
        Graph(const V* a, std::size_t n)
        {
            _vertexs.reserve(n);
            for (int i = 0; i < n; ++i)
            {
                _vertexs.push_back(a[i]);
                _indexMap[a[i]] = i;
            }
            _matrix.resize(n);
            for (int i = 0; i < _matrix.size(); ++i)
            {
                _matrix[i].resize(n, MAX_W);
            }  
        }
        int GetVertexIndex(const V& v) const
        {
            auto it = _indexMap.find(v);
            if (it != _indexMap.end())
            {
                return it->second;
            } 
            return -1;
        }
        void AddEdge(const V& v1, const V& v2, W w)
        {
            int i = GetVertexIndex(v1);
            int j = GetVertexIndex(v2);
            if (i != -1 && j != -1)
            {
                _matrix[i][j] = w;
                if (Direction == false)
                {
                    _matrix[j][i] = w;
                }
            }
        }
    private:
        std::vector<V> _vertexs;        // 顶点集合
        std::map<V, int> _indexMap;     // 顶点索引映射
        std::vector<std::vector<W>> _matrix; // 邻接矩阵
    };
} 