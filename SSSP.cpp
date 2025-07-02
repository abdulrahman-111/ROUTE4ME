#include"SSSP.h"
using namespace std;

void sssp:: convert_to_adj(vector<vector<int>> graph) {
    for(int i=0;i<graph.size();i++) {
        for (int j=0;j<graph.size();j++) {
            if(graph[i][j]>0){
                adj[i].push_back({j,graph[i][j]});
            }
        }
    }
}

void sssp:: dijkstra(int source) {
    // distance (n,INT MAX), Parent(n,INT_MAX)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    distance[source]=0;

    pq.push({0,source});
    while(!pq.empty()) {
        auto p= pq.top();
        pq.pop();
        int u=p.second;

        for(auto v: adj[u]) {
            if(distance[v.first]> distance[u]+ v.second) { // this is adj matrix,
                parent[v.first]=u;
                distance[v.first]=distance[u]+ v.second;
                pq.push({distance[v.first],v.first});
            }
        }
    }

    cout << "\nShortest delivery routes from zone " << source << ":\n";
    cout << "-----------------------------------------\n";
    cout << "Zone\tDistance\tPath\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < num_node; i++) {
        cout << i << "\t";
        if (distance[i] == INT_MAX) {
            cout << "Unreachable\t";
        } else {
            cout << distance[i] << "\t\t";
        }

        stack<int> path;
        vector<int>path_nodes;

        int zone=i;
        while(zone!=-1) {
            path.push(zone);
            zone=parent[zone];
        }
        cout<<"path: ";
        while(!path.empty()) {
            cout<<path.top();
            path.pop();
            if(!path.empty()) cout<<" -> ";
        }
        cout<<endl;
    }

}