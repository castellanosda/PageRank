#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

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

template<typename T>
AdjacencyList<T>::AdjacencyList()
{
    vCount = 0;
}

template<typename T>
int AdjacencyList<T>::vertexCount() {return vCount + 1;}

template<typename T>
int AdjacencyList<T>::outDegrees(T key)
{
    return outdegrees.at(indexMap[key]);
}

template<typename T>
std::vector<std::pair<T, int> > AdjacencyList<T>::getValue(T key) 
{
    return adjacencyList[key];
}

template<typename T>
void AdjacencyList<T>::insert(T from, T to, int weight)
{
    //Adds to the vertex count and the indexMap
    //indexMap will be a powerful tool that will attach a string
    //to an index for easier iteration
    //i.e. A  0              1
    //     B  1 <- indexMap  0 <-outdegrees vector will index
    //     C  2 edgeCount -> 0   appropriately as well
    //     |  |              |
    if(indexMap.find(from) == indexMap.end())
    {
        indexMap[from] = vCount++;
        outdegrees.push_back(0);
    }
        
    if(indexMap.find(to) == indexMap.end())
    {
        indexMap[to] = vCount++;
        outdegrees.push_back(0);
    }

    //Adds edge between from and to and increments edge count
    adjacencyList[from].push_back(make_pair(to, weight));
    outdegrees.at(indexMap[from])++;

    //checks to see if to is in adjacencyList and adds if not found
    if(adjacencyList.find(to) == adjacencyList.end())
        adjacencyList[to];

}

template<typename T>
std::vector<float> AdjacencyList<T>::pageRank(int pIterations)
{

    std::vector<float> r_0;
    for(int i = 0; i < vCount; i++)
    {
        //initializes both the initial vector
        r_0.push_back(1.0/((float)vCount));
    }
    
    //powerIteration
    while(pIterations > 1)
    {
        std::vector<float> r_t(vCount, 0);

        for(auto it = indexMap.begin(); it != indexMap.end(); it++)
        {
            //variables for matrix multiplication
            int i = 0;
            std::vector<std::pair<T, int> > directedEdges = adjacencyList[it->first];
            
            for(int j = 0;j < directedEdges.size();j++)
            {
                //multiplication of r_0 and collapsed ith row of the adjacency list
                r_t[indexMap[directedEdges.at(j).first]] += (float)(r_0[it->second])*(1.0/(float)(outdegrees.at(it->second)));
            }

        }

        //updates the previous iteration to the new one
        r_0 = r_t;
        pIterations--;
    }

    return r_0;
}

template <typename T>
std::map<T, int>& AdjacencyList<T>::getIM()
{
    return indexMap;
}

int main(){
    //Beginning by initializing driver code variables
    int numLines, powerIterations;
    int weight = 0; //unweighted graph
    std::string from, to;
    std::cin >> numLines;
    std::cin >> powerIterations;
    AdjacencyList<std::string> graph;

    //Creates the graph
    for(int i = 0; i < numLines; i++)
    {
        //Accepts from and to arguments from user
        std::cin >> from;
        std::cin >> to;

        //Adds elements to the graph
        graph.insert(from, to, weight);
    }

    //Returns the pageRank algorithm results as a vector and obtains the index map for iteration
    std::vector<float> rankings = graph.pageRank(powerIterations);
    std::map<std::string, int> indexMap = graph.getIM();

    for(auto it = indexMap.begin(); it != indexMap.end(); it++)
        std::cout << it->first << " " << std::fixed << std::setprecision(2) << rankings.at(it->second) << std::endl; 

    return 0;
}