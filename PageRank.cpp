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
    string from, to;
    cin >> numLines;
    cin >> powerIterations;
    AdjacencyList<string> graph;

    cout << numLines << " " << powerIterations << endl;

    //Creates the graph
    
    for(int i = 0; i < numLines; i++)
    {
        //Accepts from and to arguments from user
        cin >> from;
        cin >> to;

        //Adds elements to the graph
        graph.insert(from, to, weight);
    }

    vector<float> rankings = graph.pageRank(powerIterations);

    for(int i = 0; i < rankings.size(); i++)
        cout << fixed << setprecision(2) << rankings.at(i) << endl; 

    return 0;
}