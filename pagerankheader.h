#pragma once
#include <vector>

template<typename T>
class AdjacencyList{
        std::map<T, std::vector<std::pair<T, int> > > adjacencyList;
        std::map<T, int> indexMap;
        int vCount;
        std::vector<int> outdegrees;

    public:
        AdjacencyList();
        int vertexCount();
        int outDegrees(T key);
        std::vector<std::pair<T, int> > getValue(T key);
        void insert(T from, T to, int weight);  //for unweighted graphs, pass 0
        std::vector<float> pageRank(int pIterations);
        std::map<T, int>& getIM();
        //Functions to write at later date:
        //void setValue(T vertex, U val);
        //void removeEdge(T key, T val)
};
