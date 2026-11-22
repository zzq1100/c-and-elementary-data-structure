#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <climits> // INT_MAX
#include <cstddef> // std::size_t
#include <stdexcept>
#include <queue>
#include <string>
#include "UnionFindSet.hpp"

using namespace std;

namespace matrix
{
    template <class V, class W, W MAX_W = INT_MAX, bool Direction = true>
    class Graph
    {
        typedef Graph<V, W, MAX_W, Direction> Self;

    public:
        Graph(const V *a, std::size_t n)
        {
            _vertexs.reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                _vertexs.push_back(a[i]);
                _indexMap[a[i]] = i;
            }
            _matrix.resize(n);
            for (size_t i = 0; i < _matrix.size(); ++i)
            {
                _matrix[i].resize(n, MAX_W);
            }
        }
        int GetVertexIndex(const V &v) const
        {
            auto it = _indexMap.find(v);
            if (it != _indexMap.end())
            {
                return it->second;
            }
            return -1;
        }
        void AddEdge(size_t i, size_t j, W w)
        {
            if (i < _vertexs.size() && j < _vertexs.size())
            {
                _matrix[i][j] = w;
                if (Direction == false)
                {
                    _matrix[j][i] = w;
                }
            }
        }

        void AddEdge(const V &v1, const V &v2, W w)
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

        void BFS(const V &startVertex)
        {
            int startIndex = GetVertexIndex(startVertex);

            std::vector<bool> visited(_vertexs.size(), false);
            std::queue<int> queue;

            queue.push(startIndex);
            visited[startIndex] = true;

            int n = _vertexs.size();

            while (!queue.empty())
            {
                int front = queue.front();
                queue.pop();
                std::cout << front << ":" << _vertexs[front] << std::endl;

                for (int i = 0; i < n; ++i)
                {
                    if (_matrix[front][i] != MAX_W && !visited[i])
                    {
                        visited[i] = true;
                        queue.push(i);
                    }
                }
            }
        }

        void DFSUtil(int vertexIndex, std::vector<bool> &visited)
        {
            visited[vertexIndex] = true;
            std::cout << vertexIndex << ":" << _vertexs[vertexIndex] << std::endl;

            int n = _vertexs.size();
            for (int i = 0; i < n; ++i)
            {
                if (_matrix[vertexIndex][i] != MAX_W && !visited[i])
                {
                    DFSUtil(i, visited);
                }
            }
        }

        void DFS(const V &startVertex)
        {
            int startIndex = GetVertexIndex(startVertex);

            std::vector<bool> visited(_vertexs.size(), false);
            DFSUtil(startIndex, visited);
        }

        struct Edge
        {
            int _srcIndex;
            int _dstIndex;
            W _w;
            Edge(int src, int dst, W w)
                : _srcIndex(src), _dstIndex(dst), _w(w)
            {
            }
            bool operator>(const Edge &e1, const Edge &e2)
            {
                return e1._w > e2._w;
            }
        };

        W Kruskal(Self &minTree)
        {
            priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
            size_t n = _vertexs.size();
            for (size_t i = 0; i < n; ++i)
            {
                for (size_t j = 0; j < n; ++j)
                {
                    if (i < j && _matrix[i][j] != MAX_W)
                    {
                        pq.push(Edge(i, j, _matrix[i][j]));
                    }
                }
            }
            size_t size = 0;
            W total = W();
            UnionFindSet ufs(n);
            while (!pq.empty())
            {
                Edge min = pq.top();
                pq.pop();

                if (!ufs.InSameSet(min._srcIndex, min._dstIndex))
                {
                    ufs.unionSet(min._srcIndex, min._dstIndex);
                    minTree.AddEdge(min._srcIndex, min._dstIndex, min._w);
                    size++;
                    total += min._w;
                } 
            }
            if (size != n - 1)
            {
                throw std::runtime_error("图不连通，无法生成最小生成树");
            }
            return total;
        }

    private:
        std::vector<V> _vertexs;             // 顶点集合
        std::map<V, int> _indexMap;          // 顶点索引映射
        std::vector<std::vector<W>> _matrix; // 邻接矩阵
    };
}

namespace LinkTable
{
    template <class W>
    struct LinkEdge
    {
        int _srcIndex;
        int _dstIndex;
        W _w;
        LinkEdge<W> *_next;
        LinkEdge(const W &w)
            : _srcIndex(-1), _dstIndex(-1), _w(w), _next(nullptr)
        {
        }
    };
    template <class V, class W, bool Direction = false>
    class Graph
    {
        typedef LinkEdge<W> Edge;

    public:
        Graph(const V *vertexs, size_t n)
        {
            _vertexs.reserve(n);
            for (size_t i = 0; i < n; ++i)
            {
                _vertexs.push_back(vertexs[i]);
                _vIndexMap[vertexs[i]] = i;
            }
            _linkTable.resize(n, nullptr);
        }

        size_t GetVertexIndex(const V &v)
        {
            auto ret = _vIndexMap.find(v);
            if (ret != _vIndexMap.end())
            {
                return ret->second;
            }
            else
            {
                throw invalid_argument("不存在的顶点");
            }
        }
        void AddEdge(const V &src, const V &dst, const W &w)
        {
            size_t srcindex = GetVertexIndex(src);
            size_t dstindex = GetVertexIndex(dst);
            // 0 1
            Edge *sd_edge = new Edge(w);
            sd_edge->_srcIndex = srcindex;
            sd_edge->_dstIndex = dstindex;
            sd_edge->_next = _linkTable[srcindex];
            _linkTable[srcindex] = sd_edge;
            // 1 0
            // 无向图
            if (Direction == false)
            {
                Edge *ds_edge = new Edge(w);
                ds_edge->_srcIndex = dstindex;
                ds_edge->_dstIndex = srcindex;
                ds_edge->_next = _linkTable[dstindex];
                _linkTable[dstindex] = ds_edge;
            }
        }

    private:
        map<V, int> _vIndexMap;    // 顶点值 → 下标
        vector<V> _vertexs;        // 下标 → 顶点值
        vector<Edge *> _linkTable; // 下标 → 对应链表的头指针
    };
}