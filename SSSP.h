#ifndef SSSP_H
#define SSSP_H

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class sssp {
    vector<int> parent;
    vector<int> distance;
    vector<vector<pair<int,int>>>adj;//adj list
    int num_node; // num of nodes
public:
    sssp(vector<vector<int>> graph) {
        num_node=graph.size();
        adj.resize(num_node);
        convert_to_adj(graph);
        parent.resize(num_node,-1);
        distance.resize(num_node,INT_MAX);
    }
    void convert_to_adj(vector<vector<int>> graph);
    void dijkstra(int source);

};
#endif //SSSP_H
