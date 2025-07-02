#include <iostream>
#include"prim's.h"
using namespace std;

void mst::prims_algo(vector< vector<int> >graph) {
    int num_node=graph.size();

    bool visited[num_node];
    int distances[num_node];
    int parent[num_node];   //MST Structure

    for (int i=0;i<num_node;i++) {
        visited[i]=false;
        distances[i]=INT_MAX;
    }
    parent[0]=-1;
    distances[0]=0;

    for(int count=0;count<num_node-1;count++) { //  as I select edge  |E|-1
        int v=-1;
        int min =INT_MAX;
        for (int j=0;j<num_node;j++) {
            if(visited[j]== false && distances[j]<min) {
                min=distances[j];
                v=j;
            }
        }
        if(v==-1){  break; }

        visited[v]=true;
        for(int i=0;i<num_node;i++) {
            if(visited[i]==false &&graph[v][i]!=0 &&graph[v][i]<distances[i]) {
                distances[i]=graph[v][i];
                parent[i]=v;
            }
        }
    }
    print(parent,graph);
}

void mst::print(int parent[],vector<vector<int>>graph) {
    cout << "Edge\tWeight\n";
    for (int i = 1; i < graph.size(); i++) {
        cout << parent[i] << "-" << i << "\t" << graph[parent[i]][i] << endl;
        min_cost+=graph[parent[i]][i];
    }
    cout<<"The min_cost= "<<min_cost<<endl;
}