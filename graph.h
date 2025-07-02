
#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "prim's.h"
#include "SSSP.h"
using namespace std;
class graph{
    vector<vector<int>> graph_routes ; // adj matrix
    int size; // number of zones or areas will be delivered+ warehouse
public:
    graph(int n) {
        size = n;
        graph_routes.resize(n, vector<int>(n, 0));
    }
    void add_node(int x,int y, int w) {
        graph_routes[x][y]=w;
        graph_routes[y][x]=w;
    }
    void MST() {
        mst m1;
        m1.prims_algo(graph_routes);
    }
    void shortest_path_from_zone(int zone_number);
    void display_routes();

};
#endif //GRAPH_H
