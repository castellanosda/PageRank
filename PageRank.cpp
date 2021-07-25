#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "pagerankheader.h"
#include "AdjacencyListClass.cpp"

using namespace std;

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