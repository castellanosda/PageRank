#include <string>
#include <map>
#include <vector>
#include <iterator>
#include "pagerankheader.h"

template<typename T>
AdjacencyList<T>::AdjacencyList()
{
    vCount = 0;
    eCount = 0;
}

template<typename T>
int AdjacencyList<T>::vertexCount() {return vCount + 1;}

template<typename T>
int AdjacencyList<T>::edgeCount(T key)
{
    return edgeCount.at(indexMap[key]);
}

template<typename T>
int getValue(T key) {return adjacencyList[key];}

template<typename T>
void AdjacencyList<T>::insert(T from, T to, int weight)
{
    //Adds to the vertex count and the indexMap
    //indexMap will be a powerful tool that will attach a string
    //to an index for easier iteration
    //i.e. A  0              1
    //     B  1 <- indexMap  1 <-edgeCount vector will index
    //     C  2 edgeCount -> 1   appropriately as well
    //     |  |              1
    if(indexMap.find(from) == indexMap.end())
    {
        indexMap[from] = vCount++;
        edgeCount.push_back(1);
    }
        
    if(indexMap.find(to) == indexMap.end())
    {
        indexMap[to] = vCount++;
        edgeCount.push_back(1);
    }

    //Adds edge between from and to and increments edge count
    adjacencyList[from].push_back(make_pair(to, weight));
    edgeCount.at(indexMap[from])++;

    //checks to see if to is in adjacencyList and adds if not found
    if(adjacencyList.find(to) == adjacencyList.end())
        adjacencyList[to] = {};
}

template<typename T>
std::vector<float> AdjacencyList<T>::pageRank(int pIterations)
{
    std::vector<float> r_0;
    std::vector<float> r_t;

    for(int i = 0; i < vCount + 1; i++)
        r.push_back(1/(vCount + 1));
    
    //powerIteration
    while(pIterations > 1)
    {
        for(auto it = indexMap.begin(); it! = indexMap.end(); it++)
        {
            //variables for matrix multiplication
            int i = 0;
            float r_val = 0;
            std::vector<std::pair<T, int>> directedEdges = adjacencyList[it->first];
            
            //
            for(int j = 0;j < directedEdges.size();j++)
            {
                //multiplication of r_0 and collapsed ith row of the adjacency list
                r_val += r_0.at(indexMap[directedEdges.at(j).at(0)])*edgeCount.at(it->second);
            }
            //pushing r_val into r_t
        }
        pIterations--;
    }

    return r;
}