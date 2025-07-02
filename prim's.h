
#ifndef PRIM_S_H
#define PRIM_S_H
#include <vector>
using namespace std;
class mst{
    int min_cost;
public:
    mst():min_cost(0){}
    void print(int parent[],vector<vector<int>>graph);
    void prims_algo(vector< vector<int> >graph);
    int get_min_cost()const {
        return min_cost;
    }
};




#endif //PRIM_S_H
