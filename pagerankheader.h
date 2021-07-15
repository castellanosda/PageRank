#pragma once
#include <vector>

template<typename T>
class AdjacencyList{
        map<T, std::vector<std::pair<T, int>>> adjacencyList;
        map<T, int> indexMap;
        int vCount;
        vector<int> edgeCounter;

    public:
        AdjacencyList();
        int vertexCount();
        int edgeCount(T key);
        int getValue(T key);
        void insert(T from, T to, int weight);  //for unweighted graphs, pass 0
        std::vector<float> pageRank(int pIterations);
        //Functions to write at later date:
        //void setValue(T vertex, U val);
        //void removeEdge(T key, T val)
};
