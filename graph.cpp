#include"graph.h"

void graph::shortest_path_from_zone(int zone_number) {
    if (zone_number < 0 || zone_number >= size) {
        cout << "Invalid zone number\n";
        return;
    }
    sssp s1(graph_routes);
    s1.dijkstra(zone_number);
}
void graph::display_routes() {
       cout << "\nCurrent Delivery Routes:\n";
       cout << "------------------------\n";
       for (int i = 0; i < size; i++) {
           for (int j = i+1; j < size; j++) {
               if (graph_routes[i][j] > 0) {
                   cout << "Zone " << i << " - Zone " << j
                        << ": " << graph_routes[i][j] << " units\n";
               }
           }
       }
   }