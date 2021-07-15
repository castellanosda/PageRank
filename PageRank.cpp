#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include "pagerankheader.h"

using namespace std;

int main(){
    
    //Beginning by initializing driver code variables
    int numLines, powerIterations;
    string from, to;
    cin >> numLines;
    cin >> powerIterations;
    AdjacencyList<string> graph;

    //Creates the graph
    for(int i = 0; i < numLines; i++)
    {
        //Accepts from and to arguments from user
        cin >> from;
        cin >> to;

        //Adds elements to the graph
        graph.insert(from, to, 0);
    }

    graph.pageRank(powerIterations);


    return 0;
}